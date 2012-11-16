#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <QDateTime>
#include <QVector>
#include <QString>


class Appointment {

public:
    enum Attributes {
        START, END, NAME, LOCATION, TYPE, INFO, CONTACT
    };

    Appointment();
    Appointment(QStringList);
    Appointment(QDateTime start, QDateTime end, QString name, QString loc,
                QString typetxt, QString infotxt, QString contacttxt);


    QDateTime getStartTime() const { return startTime; }
    QDateTime getEndTime() const { return endTime; }

    QString getAppointmentName() const { return appointmentName; }
    QString getLocation() const { return location; }
    QString getType() const { return type; }
    QString getInfo() const { return info; }

    QString getContact() const { return contact; }


    void setStartTime(QDateTime start) { startTime = start; }
    void setEndTime(QDateTime end) { endTime = end; }

    void setAppointmentName(QString name) { appointmentName = name; }
    void setLocation(QString loc) { location = loc; }
    void setType(QString typetxt) { type = typetxt; }
    void setInfo(QString infotxt) { info = infotxt; }

    void setContact(QString contacttxt) { contact = contacttxt; }

    bool operator<(const Appointment&) const;

    void moveDays(int);
    QString toString() const;


    static const QString SEPARATOR;

private:
    QDateTime startTime;
    QDateTime endTime;

    QString appointmentName;
    QString location;
    QString type;
    QString info;

    QString contact;
};

#endif // APPOINTMENT_H
