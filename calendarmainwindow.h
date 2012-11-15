#ifndef CALENDARMAINWINDOW_H
#define CALENDARMAINWINDOW_H

#include <QDate>
#include <QList>
#include <QMainWindow>
#include <QMap>

#include "appointment.h"
#include "contactsgui.h"


namespace Ui {
class CalendarMainWindow;
}


class CalendarMainWindow : public QMainWindow {
    Q_OBJECT
    
public:
    explicit CalendarMainWindow(QWidget *parent = 0);
    ~CalendarMainWindow();
    
private slots:
    void on_gotoTodayButton_clicked();

    void on_calendarWidget_clicked(const QDate &date);

public slots:
    void on_newAppointmentButton();

    void on_contactlistButton_clicked();

    void on_removeAppointmentButton_clicked();

private:
    Ui::CalendarMainWindow *ui;
    ContactsGui contactsgui;
    QMap<QDate, QList<Appointment> >  map;

    void load();
};

#endif // CALENDARMAINWINDOW_H
