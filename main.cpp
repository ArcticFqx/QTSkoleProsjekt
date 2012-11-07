#include <QApplication>

#include "contactsgui.h"


int main(int argc, char** argv) {
    QApplication app(argc, argv);
    ContactsGui gui;
    gui.show();

    return app.exec();
}
