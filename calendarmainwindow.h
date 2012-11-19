#ifndef CALENDARMAINWINDOW_H
#define CALENDARMAINWINDOW_H

#include <QDate>
#include <QList>
#include <QMainWindow>
#include <QMap>

#include "appointment.h"
#include "contactsgui.h"
#include "appointmentui.h"

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
    void addAppointment(Appointment);
    void addAppointmentFromUi(Appointment, int);
    void on_addAppointmentButton_clicked();
    void on_appointmentTable_cellClicked(int row, int column);
    void on_calendarWidget_clicked(const QDate &date);
    void on_closeButton_clicked();
    void on_contactlistButton_clicked();
    void on_editAppointmentButton_clicked();
    void on_gotoTodayButton_clicked();
    void on_removeAllAppointmentsButton_clicked();
    void on_removeAppointmentButton_clicked();
    void on_searchButton_clicked();
    void on_searchLineEdit_returnPressed();

private:
    Ui::CalendarMainWindow *ui;
    ContactsGui* contactsgui;
    AppointmentUi* appointmentUi;
    QMap<QDate, QList<Appointment> >  map;
    QFile* file;

    bool appointmentOverlaps(Appointment) const;
    QList<Appointment> find(QString) const;
    QString getPathToFilename() const;
    void insertIntoAppointmentTable(QList<Appointment>) const;
    void loadFromFile();
    void saveToFile() const;
    void setAppointmentTableHeaders() const;
    void updateAppointmentTable(const QDate&) const;
    void clearFields();
    bool isSok;
};

#endif // CALENDARMAINWINDOW_H
