#include <QApplication>

#include "calendarmainwindow.h"
#include "contactsgui.h"


int main(int argc, char** argv) {
    QApplication app(argc, argv);
    /*
    ContactsGui gui;
    gui.show();
    //*/

    CalendarMainWindow gui;
    gui.show();


    return app.exec();
}
