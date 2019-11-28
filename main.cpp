#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include <QtDebug>
#include "login.h"
int main(int argc, char *argv[])
{  QApplication a(argc, argv);

    Connection c;


   if(c.ouvrirconnexion())
   {
       login l;
        MainWindow w;
       l.show();
       w.show();
      return a.exec();
   }
    return 0;
}



