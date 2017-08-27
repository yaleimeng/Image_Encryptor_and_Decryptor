#include "myw.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyW w;
    w.show();

    return a.exec();
}
