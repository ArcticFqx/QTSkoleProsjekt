#ifndef APPOINTMENTUI_H
#define APPOINTMENTUI_H

#include <QWidget>

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
    void getContact(QString);
    
private:
    Ui::AppointmentUi *ui;
};

#endif // APPOINTMENTUI_H
