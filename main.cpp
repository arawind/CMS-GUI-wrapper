#include "cmsdialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    cmsdialog w;
    w.show();
    
    return a.exec();
}
