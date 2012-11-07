#include "appointment.h"


Appointment::Appointment() {
}

Appointment::Appointment(QDateTime start, QDateTime end, QString name, QString loc,
        QString typetxt, QString infotxt, QVector<Contact> contactVector) :
        startTime(start), endTime(end), appointmentName(name),
        location(loc), type(typetxt), info(infotxt) {

    contacts = contactVector;
}
