#ifndef SERVICE_H
#define SERVICE_H

#include <QObject>
#include <QTimer>

class Service : public QObject
{
    Q_OBJECT
public:
    explicit Service(QObject *parent = nullptr);
    Service (QString name,int number);
    Q_PROPERTY(QString service_name READ service_name WRITE setService_name NOTIFY service_nameChanged FINAL)
    Q_PROPERTY(int service_number READ service_number WRITE setService_number NOTIFY service_numberChanged FINAL)

    QString service_name() const;
    void setService_name(const QString &newService_name);

    int service_number() const;
    void setService_number(int newService_number);

signals:
    void service_nameChanged();
    void service_numberChanged();

private:
    QTimer* m_timer;
    QString m_service_name;
    int m_service_number;
    int m_random_number;
};

#endif // SERVICE_H
