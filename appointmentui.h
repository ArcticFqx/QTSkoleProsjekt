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

private:
    Ui::AppointmentUi *ui;

signals:
    void openContactsList();

private slots:
    void triggerOpenContactsList();
};

#endif // APPOINTMENTUI_H
