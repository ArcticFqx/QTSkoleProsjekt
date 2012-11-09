#include "appointment.h"


Appointment::Appointment() {
}

Appointment::Appointment(QDateTime start, QDateTime end, QString name, QString loc,
        QString typetxt, QString infotxt, Contact contactObj) :
        startTime(start), endTime(end), appointmentName(name),
        location(loc), type(typetxt), info(infotxt), contact(contactObj) {
}
