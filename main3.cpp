#include "widget.h"

#include <QApplication>
#include "salle1/connection.h"
#include "salle1/mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    Connection c;
   bool test=c.createconnect();
        //MainWindow w;
    if(test)
    {w.show();
        QMessageBox::information(nullptr, QObject::tr("CORRECT !"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    return a.exec();
}
