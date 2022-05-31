#include "firstwidget.h"
#include <QApplication>




int main(int argc, char *argv[])
{
    //创建应用程序
    QApplication flightManager(argc, argv);
    //添加数据库
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL","mybase");

    //建立初始化窗口
    FirstWidget widget;
    widget.show();

    //函数结束释放
    return flightManager.exec();
}
