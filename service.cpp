#include "service.h"
#include <stdlib.h>
#include <time.h>

Service::Service(QObject *parent)
    : QObject{parent}
{

}

Service::Service(QString name, int number):
    m_service_name(name),
    m_service_number(number),
    m_timer(new QTimer(this)),
    m_random_number(0)
{
    srand(static_cast<unsigned int>(time(nullptr)));

    connect(m_timer,&QTimer::timeout,[=](){

        m_random_number = rand() % 20;
        setService_number(m_random_number);

    });
    m_timer->start(1000);

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
