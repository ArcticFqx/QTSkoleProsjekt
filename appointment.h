#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <QDateTime>
#include <QVector>
#include <QString>

#include "contact.h"


class Appointment {

public:
    Appointment();
    Appointment(QDateTime, QDateTime, QString, QString, QString,
                QString, Contact);


    QDateTime getStartTime() const { return startTime; }
    QDateTime getEndTime() const { return endTime; }

    QString getAppointmentName() const { return appointmentName; }
    QString getLocation() const { return location; }
    QString getType() const { return type; }
    QString getInfo() const { return info; }

    Contact getContact() const { return contact; }


    void setStartTime(QDateTime start) { startTime = start; }
    void setEndTime(QDateTime end) { endTime = end; }

    void setAppointmentName(QString name) { appointmentName = name; }
    void setLocation(QString loc) { location = loc; }
    void setType(QString typetxt) { type = typetxt; }
    void setInfo(QString infotxt) { info = infotxt; }

    void setContact(Contact contactObj) { contact = contactObj; }

private:
    QDateTime startTime;
    QDateTime endTime;

    QString appointmentName;
    QString location;
    QString type;
    QString info;

    Contact contact;

};

#endif // APPOINTMENT_H
