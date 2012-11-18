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
    void editAppointment(Appointment app);
    void setupAppointmentUi();

public slots:
    void setContactLineEditText(QString);

private slots:
    void on_buttonBox_accepted();
    void on_radioAvtale_toggled(bool checked);

private:
    Ui::AppointmentUi *ui;
    bool modeEdit;
    void setDateTimeEditDefaults() const;

signals:
    void newAppointment(Appointment, int);
    void openContactsList();

};

#endif // APPOINTMENTUI_H
