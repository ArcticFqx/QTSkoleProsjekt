#ifndef CONTACTSGUI_H
#define CONTACTSGUI_H

#include <QWidget>


namespace Ui {
class ContactsGui;
}

class ContactsGui : public QWidget
{
    Q_OBJECT
    
public:
    explicit ContactsGui(QWidget *parent = 0);
    ~ContactsGui();
    
private slots:
    void on_addButton_clicked();

    void on_deleteButton_clicked();

private:
    Ui::ContactsGui* ui;

    void dummyData();
};

#endif // CONTACTSGUI_H
