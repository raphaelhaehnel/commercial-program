#include <QApplication>
#include "programwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    ProgramWindow myWindow;
    myWindow.show();


    return app.exec();
}
