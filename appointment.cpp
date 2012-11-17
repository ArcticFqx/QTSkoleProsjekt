#include <QStringList>
#include <QTextStream>

#include "appointment.h"


const QString Appointment::SEPARATOR = "|";


Appointment::Appointment() {
}

Appointment::Appointment(QStringList list) {
    startTime = QDateTime::fromString(list.at(START));
    endTime = QDateTime::fromString(list.at(END));
    appointmentName = list.at(NAME);
    location = list.at(LOCATION);
    type = list.at(TYPE);
    info = list.at(INFO);
    contact = list.at(CONTACT);
}

Appointment::Appointment(QDateTime start, QDateTime end, QString name, QString loc,
        QString typetxt, QString infotxt, QString contacttxt) :
        startTime(start), endTime(end), appointmentName(name),
        location(loc), type(typetxt), info(infotxt), contact(contacttxt) {
}


bool Appointment::operator<(const Appointment& other) const {
    if (startTime == other.getStartTime()) {
        if (endTime == other.getEndTime()) {
            return appointmentName < other.getAppointmentName();
        }
        return endTime < other.getEndTime();
    }
    return startTime < other.getStartTime();
}

QString Appointment::getQStringOfType(Attributes attribute) const {
    switch (attribute) {
        case START:
            return startTime.toString();
        case END:
            return endTime.toString();
        case NAME:
            return appointmentName;
        case LOCATION:
            return location;
        case TYPE:
            return type;
        case INFO:
            return info;
        case CONTACT:
            return contact;
        default:
            return "";
    }
}

void Appointment::moveDays(int days) {
    startTime = startTime.addDays(days);
    endTime = endTime.addDays(days);
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
