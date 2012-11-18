#include <QApplication>
#include "calendarmainwindow.h"


int main(int argc, char** argv) {
    QApplication app(argc, argv);
    CalendarMainWindow gui;
    gui.show();

    return app.exec();
}
