#ifndef CONTACTSGUI_H
#define CONTACTSGUI_H

#include <QFile>
#include <QWidget>


namespace Ui {
class ContactsGui;
}

class ContactsGui : public QWidget {
    Q_OBJECT
    
public:
    explicit ContactsGui(QWidget *parent = 0);
    ~ContactsGui();

signals:
    void selectedContact(QString) const;
    
private slots:
    void on_addButton_clicked();
    void on_closeButton_clicked();
    void on_deleteButton_clicked();

private:
    QString getPathToFilename() const;
    void readFromFile() const;
    void saveToFile() const;

    QFile* file;
    Ui::ContactsGui* ui;
};

#endif // CONTACTSGUI_H
