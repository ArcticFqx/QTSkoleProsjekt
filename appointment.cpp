#include <QTextStream>

#include "appointment.h"


const QString Appointment::SEPARATOR = "|";


Appointment::Appointment() {
}

Appointment::Appointment(QDateTime start, QDateTime end, QString name, QString loc,
        QString typetxt, QString infotxt, QString contacttxt) :
        startTime(start), endTime(end), appointmentName(name),
        location(loc), type(typetxt), info(infotxt), contact(contacttxt) {
}


bool Appointment::operator<(const Appointment& other) const {
    return startTime<(other.getStartTime());
}

QString Appointment::toString() const {
    QString string = startTime.toString();
    string.append(SEPARATOR);
    string.append(endTime.toString());
    string.append(SEPARATOR);
    string.append(appointmentName);
    string.append(SEPARATOR);
    string.append(location);
    string.append(SEPARATOR);
    string.append(type);
    string.append(SEPARATOR);
    string.append(info);
    string.append(SEPARATOR);
    string.append(contact);

    return string;
}
