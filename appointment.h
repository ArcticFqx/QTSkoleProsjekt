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


    QDateTime getStartDateTime() const { return startDateTime; }
    QDateTime getEndDateTime() const { return endDateTime; }

    QString getAppointmentName() const { return appointmentName; }
    QString getLocation() const { return location; }
    QString getType() const { return type; }
    QString getInfo() const { return info; }

    QString getContact() const { return contact; }


    void setStartTime(QDateTime start) { startDateTime = start; }
    void setEndTime(QDateTime end) { endDateTime = end; }

    void setAppointmentName(QString name) { appointmentName = name; }
    void setLocation(QString loc) { location = loc; }
    void setType(QString typetxt) { type = typetxt; }
    void setInfo(QString infotxt) { info = infotxt; }

    void setContact(QString contacttxt) { contact = contacttxt; }

    bool operator<(const Appointment&) const;

    QString getQStringOfType(Attributes) const;
    void moveDays(int);
    QString toString() const;


    static const QString SEPARATOR;

private:
    QDateTime startDateTime;
    QDateTime endDateTime;

    QString appointmentName;
    QString location;
    QString type;
    QString info;

    QString contact;
};

#endif // APPOINTMENT_H
