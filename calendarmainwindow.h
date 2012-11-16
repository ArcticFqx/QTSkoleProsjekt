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

    virtual void closeEvent(QCloseEvent*);
    
private slots:
    void on_appointmentTable_cellClicked(int row, int column);
    void on_calendarWidget_clicked(const QDate &date);
    void on_closeButton_clicked();
    void on_contactlistButton_clicked();
    void on_gotoTodayButton_clicked();
    void on_removeAllAppointmentsButton_clicked();
    void on_removeAppointmentButton_clicked();

private:
    Ui::CalendarMainWindow *ui;
    ContactsGui* contactsgui;
    QMap<QDate, QList<Appointment> >  map;
    QFile* file;

    void addAppointment(Appointment);
    QString getPathToFilename() const;
    void loadFromFile();
    void saveToFile() const;
    void setAppointmentTableHeaders() const;
    void updateAppointmentTable(const QDate&) const;
};

#endif // CALENDARMAINWINDOW_H
