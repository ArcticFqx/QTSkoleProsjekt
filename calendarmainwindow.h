#ifndef CALENDARMAINWINDOW_H
#define CALENDARMAINWINDOW_H

#include <QDate>
#include <QMainWindow>


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

private:
    Ui::CalendarMainWindow *ui;

    void insert() const;
};

#endif // CALENDARMAINWINDOW_H
