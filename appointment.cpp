#include <QStringList>
#include <QTextStream>

#include "appointment.h"
#include "QDebug"

const QString Appointment::SEPARATOR = "|";


Appointment::Appointment() {
}

Appointment::Appointment(QStringList list) {
    startDateTime = QDateTime::fromString(list.at(START));
    endDateTime = QDateTime::fromString(list.at(END));
    appointmentName = list.at(NAME);
    location = list.at(LOCATION);
    absence = list.at(ABSENCE);
    type = list.at(TYPE);
    info = list.at(INFO);
    contact = list.at(CONTACT);
}

Appointment::Appointment(QDateTime start, QDateTime end, QString name, QString loc,
        QString absence, QString typetxt, QString infotxt, QString contacttxt) :
    startDateTime(start), endDateTime(end), appointmentName(name), absence(absence),
        location(loc), type(typetxt), info(infotxt), contact(contacttxt) {
}


bool Appointment::operator<(const Appointment& other) const {
    if (startDateTime == other.getStartDateTime()) {
        if (endDateTime == other.getEndDateTime()) {
            return appointmentName < other.getAppointmentName();
        }
        return endDateTime < other.getEndDateTime();
    }
    return startDateTime < other.getStartDateTime();
}

QString Appointment::getQStringOfType(Attributes attribute) const {
    switch (attribute) {
        case START:
            return startDateTime.toString();
        case END:
            return endDateTime.toString();
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
    startDateTime = startDateTime.addDays(days);
    endDateTime = endDateTime.addDays(days);
}

QString Appointment::toString() const {
    QString string = startDateTime.toString();
    string.append(SEPARATOR);
    string.append(endDateTime.toString());
    string.append(SEPARATOR);
    string.append(appointmentName);
    string.append(SEPARATOR);
    string.append(location);
    string.append(SEPARATOR);
    string.append(absence);
    string.append(SEPARATOR);
    string.append(type);
    string.append(SEPARATOR);
    string.append(info);
    string.append(SEPARATOR);
    string.append(contact);

    qDebug() << string << endl;
    return string;
}
