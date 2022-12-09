#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "salle.h"
#include <QMessageBox>
#include<QIntValidator>
#include <QSqlQuery>
#include<QSqlQueryModel>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QFileDialog>
#include <QDebug>
#include <QPdfWriter>
#include <QPainter>
#include "ARDUINO/mainwindow1.h"
#include <QSystemTrayIcon>
QString filename="";
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//ui->numero( new QIntValidator(100, 9999999, this));
    salle s;
ui->tablesalle->setModel(s.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*void MainWindow::on_pb_ajouter_clicked()
{

}*/


/*void MainWindow::on_pb_supp_clicked()
{
Salle S1;
S1.setnombre(ui->le_numerosupp->text().toInt());
bool test=S1.supprimer(S1.getnombre());
if(test){


    QMessageBox::information(nullptr, QObject::tr("ok"),
                QObject::tr("suppresion successful.\n"
                            "suppresion effectuer."), QMessageBox::Cancel);
ui->tab_Salle->setModel(S1.afficher());
}
else

    QMessageBox::critical(nullptr, QObject::tr("nope"),
                QObject::tr("suppresion failed.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}


void MainWindow::on_pushButton_clicked()
{
    ui->tab_Salle->setModel(S1.afficher());
}



void MainWindow::on_pb_ajouter_3_clicked()
{
  Salle S1;

       int ref =ui->numero->text().toInt();
       QString  modele=ui->equipement->text();
      QString etat =ui->le_prenom->text();
      QString date =ui->le_date->text();
      int  prix=ui->le_prix->text().toInt();

   Salle E(numerO,tyype,equipement,nombre);
   bool test=E.modifier(ref);
   ui->tablesalle->setModel(S1.afficher());

   if(test)



     {

       QMessageBox::information(nullptr, QObject::tr("SUCCESS"),

                   QObject::tr("update successful.\n"

                               "modifaction effectuer."), QMessageBox::Cancel);





   }

   else



       QMessageBox::critical(nullptr, QObject::tr("ERROR"),

                   QObject::tr("connection failed.\n"

                               "Click Cancel to exit."), QMessageBox::Cancel);

}
*/

/*void MainWindow::on_ajouter_clicked()
{
    int numero =ui->numero->text().toInt();
      //QString tyype =ui->tyype->text();
  if (QComboBox::AdjustToContents==1)
    //if ( ui->tyype==reunion)
       QString equipement =ui->l_equipement->text();
           int nombre =ui->le_nombre->text().toInt();

Salle S(numero,tyype,equipement,nombre);
bool test=S.ajouter();
ui->tab_Salle->setModel(S1.afficher());
if(test)


    QMessageBox::information(nullptr, QObject::tr("ok"),
                QObject::tr("ajout successful.\n"
                            "ajout effectuer."), QMessageBox::Cancel);


else

    QMessageBox::critical(nullptr, QObject::tr("nope"),
                QObject::tr("connection failed.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);




}*/


void MainWindow::on_ajouter_clicked()
{

  int n= ui->numero->text().toInt();
  int no= ui->nombre->text().toInt();
  // QString num=QString::number(numero);

  QString numero_string=QString::number(n);
  QString nombre_string=QString::number(no);
      QString tpe ;
      if (ui->reunion->isChecked())
      {
          tpe="reunion";
      }
      else if (ui->revision->isChecked())
      {
          tpe="revision";     }


      QString eqp;
  if (ui->data->isChecked())
  {
      eqp= "DATA SHOW";
  }
  else if (ui->ordinateur->isChecked())
  {
      eqp="ORDINATEUR";
  }
  else if (ui->tableau->isChecked())
  {
      eqp="TABLEAU";
  }
  else if (ui->clima->isChecked())
  {
      eqp="CLIMATISATION";
  }
//salle s(num,nbr,tpe,eqp);
//salle s(int num,int nbr,QString tpe,QString eqp);

  QSqlQuery query;
salle s(n,no,tpe,eqp,filename);
bool test=s.ajouter();
  if (test)
  {
      QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
            notifyIcon->show();
            notifyIcon->showMessage("Notification ajout ! ","La salle est bien ajoutée !",QSystemTrayIcon::Information,15000);
     QMessageBox::information(nullptr, QObject::tr("CORRECT !"),
                 QObject::tr("Create successful.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);
  ui->tablesalle->setModel(s.afficher());


  }
  else

     QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                 QObject::tr("create  failed.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);

filename="";
  }


void MainWindow::on_pushButton_3_clicked()
{
    int num =ui->numeroooo->text().toInt();
    salle s (num);
    bool test =s.supprimer();
    if (test)
    {
        QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
              notifyIcon->show();
              notifyIcon->showMessage("Notification suppression ! ","La salle est bien supprimée!",QSystemTrayIcon::Information,15000);

      //s.afficher();
      ui->tablesalle->setModel(s.afficher());

       QMessageBox::information(nullptr, QObject::tr("CORRECT !"),
                   QObject::tr("delete sucessful \n"
                               "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else

       QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                   QObject::tr("delete failed \n"
                               "Click Cancel to exit."), QMessageBox::Cancel);


    }

void MainWindow::on_pushButton_2_clicked()
{
    int n= ui->numero->text().toInt();
    int no= ui->nombre->text().toInt();
    // QString num=QString::number(numero);

    QString numero_string=QString::number(n);
    QString nombre_string=QString::number(no);
        QString tpe ;
        if (ui->reunion->isCheckable())
        {
            tpe="reunion";
        }
        else if (ui->revision->isCheckable())
        {
            tpe="revision";     }


        QString eqp;
    if (ui->data->isCheckable())
    {
        eqp= "DATA SHOW";
    }
    else if (ui->ordinateur->isCheckable())
    {
        eqp="ORDINATEUR";
    }
    else if (ui->tableau->isCheckable())
    {
        eqp="TABLEAU";
    }
    else if (ui->clima->isCheckable())
    {
        eqp="CLIMATISATION";
    }
  //salle s(num,nbr,tpe,eqp);
  //salle s(int num,int nbr,QString tpe,QString eqp);

    QSqlQuery query;
  salle s(n,no,tpe,eqp,filename);
  bool test=s.modifier();
    if (test)
    {
        QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
              notifyIcon->show();
              notifyIcon->showMessage("Notification modification ! ","La salle est bien modifiée !",QSystemTrayIcon::Information,15000);
       QMessageBox::information(nullptr, QObject::tr("CORRECT !"),
                   QObject::tr("update successful.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
    ui->tablesalle->setModel(s.afficher());


    }
    else

       QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                   QObject::tr("update failed.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);


    }

void MainWindow::on_rechercher_button_clicked()
{
    QString rech =ui->id_reparation->text();
        ui->tablesalle->setModel(s.rechercher(rech));
}



void MainWindow::on_radioButton_croissant_clicked()
{
     ui->tablesalle->setModel(s.tri());
}

/*void MainWindow::on_radioButton_dcroissant_clicked()
{
     ui->tablesalle->setModel(s.trid());
}
*/

void MainWindow::on_view_clicked()
{
    salle s;
    int num= ui->lineEdit_video->text().toInt();
    qDebug() <<s.rechercherV(num);
    QMediaPlayer* player = new QMediaPlayer;
      connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(on_positionChanged(qint64)));
      connect(player, SIGNAL(durationChanged(qint64)), this, SLOT(on_durationChanged(qint64)));
     player->setMedia(QUrl::fromLocalFile(s.rechercherV(num)));
     QVideoWidget* videoWidget = new QVideoWidget;
      player->setVideoOutput(videoWidget);

      videoWidget->setGeometry(100, 100, 600, 320);
      videoWidget->setParent(this);
      videoWidget->show();
      player->play();
}

void MainWindow::on_video_clicked()
{
    filename = QFileDialog::getOpenFileName(this,tr("choose"),tr(""));
}

void MainWindow::on_imp_clicked()
{
    QPdfWriter pdf("C:/Users/Dell/Desktop/salle1/Liste_salle.pdf");

   QPainter painter(&pdf);
   int i = 4100;

          QColor dateColor(0x4a5bcf);
          painter.setPen(dateColor);

          painter.setFont(QFont("Montserrat SemiBold", 11));
          QDate cd = QDate::currentDate();
          painter.drawText(8400,250,cd.toString("Tunis"));
          painter.drawText(8100,500,cd.toString("dd/MM/yyyy"));

          QColor titleColor(0x341763);
          painter.setPen(titleColor);
          painter.setFont(QFont("Montserrat SemiBold", 25));

          painter.drawText(3000,2700,"Liste des salles");

          painter.setPen(Qt::black);
          painter.setFont(QFont("Time New Roman", 15));
          //painter.drawRect(100,100,9400,2500);
          painter.drawRect(100,3300,9400,500);

          painter.setFont(QFont("Montserrat SemiBold", 10));

          painter.drawText(500,3600,"Numero");
          painter.drawText(2000,3600,"Nombre");
          painter.drawText(3300,3600,"Type");
          painter.drawText(4500,3600,"Equipement");
          painter.setFont(QFont("Montserrat", 10));
          painter.drawRect(100,3300,9400,9000);

          QSqlQuery query;
          query.prepare("select * from salle");
          query.exec();
          int y=4300;
          while (query.next())
          {
              painter.drawLine(100,y,9490,y);
              y+=500;
              painter.drawText(500,i,query.value(0).toString());
              painter.drawText(2000,i,query.value(1).toString());
              painter.drawText(3300,i,query.value(2).toString());
              painter.drawText(4500,i,query.value(3).toString());

             i = i + 500;
          }
          QMessageBox::information(this, QObject::tr("PDF Enregistré!"),
          QObject::tr("PDF Enregistré!.\n" "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_clicked()
{
    ui->tabWidget->setCurrentIndex(3);
       salle s;


        s.stat(ui->widget);
}

void MainWindow::on_pushButton_4_clicked()
{
    Arduino = new MainWindow1(this);
    Arduino ->show();
}
