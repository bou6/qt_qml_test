#include "service.h"
#include <stdlib.h>
#include <QSslConfiguration>
#include <QSslSocket>

Service::Service(QObject *parent)
    : QObject{parent}
{

}

Service::Service(QString name, int number):
    m_service_name(name),
    m_service_number(number),
    m_mqtt_username("Achbou6"),
    m_mqtt_password("AchMqt26081991@"),
    m_hostname("2c45a082862d4b60b6dd63904ff8c728.s1.eu.hivemq.cloud"),
    m_useSSL(true)
{
    // setup Mqtt client
    m_mqttClient.setHostname(m_hostname);
    m_mqttClient.setUsername(m_mqtt_username);
    m_mqttClient.setPassword(m_mqtt_password);
    
    if (m_useSSL) {
        m_mqttClient.setPort(8883);
        QSslConfiguration sslConfig = QSslConfiguration::defaultConfiguration();
        sslConfig.setProtocol(QSsl::TlsV1_2OrLater);
        sslConfig.setPeerVerifyMode(QSslSocket::VerifyNone);
        m_mqttClient.connectToHostEncrypted(sslConfig);
        qDebug() << "Using SSL/TLS connection on port 8883";
    }
    else {
        m_mqttClient.setPort(1883);
        m_mqttClient.connectToHost();
        qDebug() << "Using plain connection on port 1883";
    }

    connect(&m_mqttClient, &QMqttClient::connected, this, [this](){
        qDebug("MQTT client connected to broker.");
        // Subscribe to topic after successful connection
        auto subscription = m_mqttClient.subscribe(m_service_name);
        if (subscription) {
            qDebug() << "Subscribed to topic:" << m_service_name;
        } else {
            qWarning() << "Failed to subscribe to topic:" << m_service_name;
        }
    });

    connect (&m_mqttClient, &QMqttClient::disconnected, this, [this](){
        qDebug("MQTT client disconnected from broker.");
        qDebug() << "Client state:" << m_mqttClient.state();
        qDebug() << "Last error:" << m_mqttClient.error();
    });

    connect(&m_mqttClient, &QMqttClient::messageReceived, this, [=](const QByteArray &message, const QMqttTopicName &topic){
        qDebug() << "Message received on topic" << topic.name() << ":" << message;
        // get the service number from the message
        bool ok;
        int received_number = message.toInt(&ok);
        if (ok) {
            setService_number(received_number);
            qDebug() << "Updated service number to:" << m_service_number;
        } else {
            qWarning() << "Failed to convert message to integer:" << message;
        }
    
    });

    connect(&m_mqttClient, &QMqttClient::stateChanged, this, [this](QMqttClient::ClientState state) {
        switch (state) {
        case QMqttClient::Disconnected:
            qDebug() << "MQTT State: Disconnected";
            break;
        case QMqttClient::Connecting:
            qDebug() << "MQTT State: Connecting...";
            break;
        case QMqttClient::Connected:
            qDebug() << "MQTT State: Connected";
            break;
        }
    });

    connect(&m_mqttClient, QOverload<QMqttClient::ClientError>::of(&QMqttClient::errorChanged),
            this, [this](QMqttClient::ClientError error) {
        switch (error) {
        case QMqttClient::NoError:
            qDebug() << "No error";
            break;
        case QMqttClient::InvalidProtocolVersion:
            qWarning() << "Invalid protocol version";
            break;
        case QMqttClient::IdRejected:
            qWarning() << "Client ID rejected";
            break;
        case QMqttClient::ServerUnavailable:
            qWarning() << "Server unavailable";
            break;
        case QMqttClient::BadUsernameOrPassword:
            qWarning() << "Bad username or password";
            break;
        case QMqttClient::NotAuthorized:
            qWarning() << "Not authorized - check username and password";
            qWarning() << "Username:" << m_mqtt_username;
            qWarning() << "Hostname:" << m_hostname;
            break;
        case QMqttClient::TransportInvalid:
            qWarning() << "Transport invalid - check hostname and port";
            break;
        case QMqttClient::ProtocolViolation:
            qWarning() << "Protocol violation";
            break;
        case QMqttClient::UnknownError:
        default:
            qWarning() << "Unknown error:" << error;
            break;
        }
    });
}

Service::~Service()
{
    m_mqttClient.disconnectFromHost();
}

QString Service::service_name() const
{
    return m_service_name;
}

void Service::setService_name(const QString &newService_name)
{
    if (m_service_name == newService_name)
        return;
    m_service_name = newService_name;
    emit service_nameChanged();
}

int Service::service_number() const
{
    return m_service_number;
}

void Service::setService_number(int newService_number)
{
    if (m_service_number == newService_number)
        return;
    m_service_number = newService_number;
    emit service_numberChanged();
}
