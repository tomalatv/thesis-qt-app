#include <QtGui/QApplication>
#include <QtPlugin>
#include "multimediax.h"

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    MultimediaX w;
    w.show();
    return a.exec();
}
