#ifndef CONTACTADDGUI_H
#define CONTACTADDGUI_H

#include <QWidget>

namespace Ui {
class ContactAddGui;
}

class ContactAddGui : public QWidget
{
    Q_OBJECT
    
public:
    explicit ContactAddGui(QWidget *parent = 0);
    ~ContactAddGui();


    
private:
    Ui::ContactAddGui *ui;
};

#endif // CONTACTADDGUI_H
