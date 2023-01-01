#include "hotelmenu.h"
#include <QtWidgets/QApplication>
#include <qfile.h>
#include <qtextstream.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile file(":/res/qss/style-1.qss");       //qss文件导入
    file.open(QFile::ReadOnly);
    QTextStream filetext(&file);
    QString stylesheet = filetext.readAll();
    a.setStyleSheet(stylesheet);
    file.close();

    hotelmenu w;
    w.show();
    return a.exec();
}
