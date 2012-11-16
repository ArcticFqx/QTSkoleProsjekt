#ifndef APPOINTMENTUI_H
#define APPOINTMENTUI_H

#include <QWidget>

#include "appointment.h"


namespace Ui {
class AppointmentUi;
}

class AppointmentUi : public QWidget
{
    Q_OBJECT
    
public:
    explicit AppointmentUi(QWidget *parent = 0);
    ~AppointmentUi();

public slots:
    void setContactLineEditText(QString);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::AppointmentUi *ui;

    void setDateTimeEditDefaults() const;

signals:
    void newAppointment(Appointment, int);
    void openContactsList();

};

#endif // APPOINTMENTUI_H
