#include "appointment.h"


Appointment::Appointment() {
}

Appointment::Appointment(QDateTime start, QDateTime end, QString name, QString loc,
        QString typetxt, QString infotxt, QString contacttxt) :
        startTime(start), endTime(end), appointmentName(name),
        location(loc), type(typetxt), info(infotxt), contact(contacttxt) {
}
