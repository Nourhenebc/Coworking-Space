#include "mainwnourh.h"
#include "ui_mainwnourh.h"
#include "equipement.h"
#include <QMessageBox>
#include<QIntValidator>
#include<QSqlQueryModel>
#include<QTextDocument>
#include"qprinter.h"
#include"qpainter.h"
#include"QPdfWriter"
#include"qdesktopservices.h"
#include"QtPrintSupport/qprinter.h"
#include"qsqlquery.h"
#include"exportexcelobjet.h"
#include "qdebug.h"
#include "QTimer"
#include"QVariant"
#include"QVBoxLayout"
#include"QToolTip"
#include"qcustomplot.h"
//#include"connection.h"
#include <QSqlRecord>
// C++ program to convert string
// to char array using c_str()
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QtWidgets>

QString imgx ="";
int ref = 0 ;
QTimer *timer = new QTimer();
QVBoxLayout *layoutt = new QVBoxLayout();


Mainwnourh::Mainwnourh(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Mainwnourh)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

ui->le_ref->setValidator( new QIntValidator(100, 9999999, this));
ui->tab_etudiant ->setLayout( layoutt );            // SCROLL

ui->tab_etudiant->setModel(E1.afficher());
arduino_is_available = false;
arduino_port_name = "";
arduino = new QSerialPort;

/*
qDebug() << "Number of available ports: " << QSerialPortInfo::availablePorts().length();
foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
    qDebug() << "Has vendor ID: " << serialPortInfo.hasVendorIdentifier();
    if(serialPortInfo.hasVendorIdentifier()){
        qDebug() << "Vendor ID: " << serialPortInfo.vendorIdentifier();
    }
    qDebug() << "Has Product ID: " << serialPortInfo.hasProductIdentifier();
    if(serialPortInfo.hasProductIdentifier()){
        qDebug() << "Product ID: " << serialPortInfo.productIdentifier();
    }
}
*/

foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
    if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()){
        if(serialPortInfo.vendorIdentifier() == arduino_uno_vendor_id){
            if(serialPortInfo.productIdentifier() == arduino_uno_product_id){
                arduino_port_name = serialPortInfo.portName();
                arduino_is_available = true;
            }
        }
    }
}

if(arduino_is_available){
    // open and configure the serialport
    arduino->setPortName(arduino_port_name);
    arduino->open(QSerialPort::WriteOnly);
    arduino->setBaudRate(QSerialPort::Baud9600);
    arduino->setDataBits(QSerialPort::Data8);
    arduino->setParity(QSerialPort::NoParity);
    arduino->setStopBits(QSerialPort::OneStop);
    arduino->setFlowControl(QSerialPort::NoFlowControl);
}else{
    // give error message if not available
    QMessageBox::warning(this, "Port error", "Couldn't find the Arduino!");
}

//connect(timer, SIGNAL(timeout()), this, SLOT(setFormulaire()));

}

Mainwnourh::~Mainwnourh()
{
    delete ui;
}

void Mainwnourh::on_pb_ajouter_clicked()
{
       int ref =ui->le_ref->text().toInt();
       QString modele =ui->le_modele->text();
       QString etat =ui->le_etat->text();
       QString date_de_naissance =ui->dateEdit->text();
       int prix =ui->le_prix->text().toInt();
       QString imgz = ui->img_f->text();
Equipement E(ref ,modele,etat,date_de_naissance,prix,imgx,e);
bool test=E.ajouter();

ui->tab_etudiant->setModel(E1.afficher());
if(test)


    QMessageBox::information(nullptr, QObject::tr("ok"),
                QObject::tr("ajout successful.\n"
                            "ajout effectuer."), QMessageBox::Cancel);


else

    QMessageBox::critical(nullptr, QObject::tr("nope"),
                QObject::tr("connection failed.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);




}


void Mainwnourh::on_pb_supp_clicked()
{
Equipement E1;
E1.setref(ui->le_idsupp->text().toInt());
bool test=E1.supprimer(E1.getref());
if(test){


    QMessageBox::information(nullptr, QObject::tr("ok"),
                QObject::tr("suppresion successful.\n"
                            "suppresion effectuer."), QMessageBox::Cancel);
ui->tab_etudiant->setModel(E1.afficher());
}
else

    QMessageBox::critical(nullptr, QObject::tr("nope"),
                QObject::tr("suppresion failed.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}



void Mainwnourh::on_pb_modifier_clicked()
{  Equipement E1;

    int ref =ui->le_ref->text().toInt();

       QString modele =ui->le_modele->text();

       QString etat =ui->le_etat->text();


       QString date_de_naissance =ui->dateEdit->text();


    int prix =ui->le_prix->text().toInt();

    QString imgz = ui->img_f->text();


Equipement E(ref ,modele,etat,date_de_naissance,prix,imgx,e);

bool test=E.modifier(ref);

ui->tab_etudiant->setModel(E1.afficher());

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



void Mainwnourh::on_pb_recherche_clicked()
{
    if (ui->rech_modele->text().isEmpty())
         {

             QMessageBox::information(this," ERREUR "," VEUILLEZ VERIFIER CHAMP !!!!") ;
             QToolTip::showText(ui->rech_modele->mapToGlobal(QPoint(100,0)), tr("Invalid Input"));
            // ui->rech_modele->setStyleSheet("border: 1px solid red ");



         }
        else {
        QString modele= ui->rech_modele->text();
        ui->tab_etudiant->setModel(E1.recherchemodele(modele));
        //ui->rech_modele->setStyleSheet("border: 1px solid blue ");

}
}
//tri par prix
void Mainwnourh::on_pushButton_2_clicked()
{


             Equipement E;
            ui->tab_etudiant->setModel(E.tri_croissant());

}


void Mainwnourh::on_pb_tri_clicked()
{
    Equipement E;
        ui->tab_etudiant->setModel(E.tri_deccroissant());
}


void Mainwnourh::on_pb_pdf_clicked()
{
    

        QPdfWriter pdf("C:/Users/msi/Desktop/integration/intergration/testpdf.pdf");
                              QPainter painter(&pdf);
                             int i = 4000;
                                  painter.setPen(Qt::red);
                                  painter.setFont(QFont("Arial", 30));
                                  painter.drawText(2300,1200,"Liste Des Equipement");
                                  painter.setPen(Qt::black);
                                  painter.setFont(QFont("Arial", 50));
                                 // painter.drawText(1100,2000,afficheDC);
                                 // painter.drawRect(1500,200,7300,2600);
                                  painter.drawPixmap(QRect(0,-20,2000,2600),QPixmap("C:/Users/Nourhene/Desktop/nou/nou/logo.jpg"));
                                  painter.drawRect(0,3000,9600,500);
                                  painter.setFont(QFont("Arial", 9));
                                  painter.drawText(300,3300,"ref");
                                  painter.drawText(2300,3300,"modele");
                                  painter.drawText(4300,3300,"etat");
                                  painter.drawText(6300,3300,"date_de_naissance");
                                  painter.drawText(8300,3300,"prix");




                                  QSqlQuery query;
                                  query.prepare("select  * from etudiant");
                                  query.exec();
                                  while (query.next())
                                  {
                                      painter.drawText(300,i,query.value(0).toString());
                                      painter.drawText(2300,i,query.value(1).toString());
                                      painter.drawText(4300,i,query.value(2).toString());
                                      painter.drawText(6300,i,query.value(3).toString());
                                      painter.drawText(8300,i,query.value(4).toString());




                                     i = i +500;
                                  }
                                  int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
                                      if (reponse == QMessageBox::Yes)
                                      {

                                          painter.end();
                                      }
                                      if (reponse == QMessageBox::No)
                                      {
                                           painter.end();
                                      }


    }




//excel

void Mainwnourh::on_pushButton_3_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Exportation en fichier Excel"), qApp->applicationDirPath (),
                                                           tr("Fichiers d'extension Excel (*.xls)"));
           if (fileName.isEmpty())
               return;

           ExportExcelObject obj(fileName, "mydata",ui->tab_etudiant);
           // you can change the column order and
           // choose which colum to export
           obj.addField(0, "ref", "char(20)");
           obj.addField(1, "modele","char(20)");
           obj.addField(2, "etat", "char(20)");
           obj.addField(3, "Date", "char(20)");
           obj.addField(4, "prix", "char(20)");


           int retVal = obj.export2Excel();

           if( retVal > 0)
           {
               QMessageBox::information(this, tr("FAIS!"),
                                        QString(tr("%1 enregistrements exportés!")).arg(retVal)
                                        );
           }

}

void Mainwnourh::on_insert_img_clicked()
{


}

void Mainwnourh::on_add_imageBtn_clicked()

{
    QString imageFile = QFileDialog::getOpenFileName(this,tr("choose"),"",tr(" (*.png *.jpg *.jpeg)"));//   les img png

         QFileInfo info(imageFile);
         QFileInfo  filename = info.fileName(); //path

         QPixmap image (imageFile);
         ui->lblBkImge->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );// taille
         image = image.scaled(300,300,Qt::IgnoreAspectRatio,Qt::FastTransformation);
         ui->lblBkImge->setPixmap(image);
         ui->lblBkImge->show(); // place of png
        // qDebug() << image <<endl << imageFile <<endl<<info.fileName();

        imgx = imageFile;
}





void Mainwnourh::on_stat_clicked()
{
    QTableView table_necessiteux,table_n2;
                QSqlQueryModel * Mod=new  QSqlQueryModel();
                QSqlQueryModel * Mod2=new  QSqlQueryModel();
                     //Connection c;
                     QSqlQuery qry,q2;
                     qry.prepare("select modele from etudiant");
                     qry.exec();
                     Mod->setQuery(qry);
                     table_necessiteux.setModel(Mod);

                     q2.prepare("select AVG(prix) from etudiant group by modele");
                     q2.exec();
                     Mod2->setQuery(q2);
                     table_n2.setModel(Mod2);

                     //c.closeConnection();

                    qDebug()<<table_necessiteux.model()->data(table_necessiteux.model()->index(0, 0)).toString().simplified();
                    qDebug()<<table_n2.model()->data(table_n2.model()->index(0, 0)).toInt();

                    const int rowCount = table_necessiteux.model()->rowCount();
                    const int rowCount2 = table_n2.model()->rowCount();



                   // set dark background gradient:
                    QLinearGradient gradient(0, 0, 0, 400);
                    gradient.setColorAt(0, QColor(192, 192, 192));
                    gradient.setColorAt(0.38, QColor(192, 192, 192));
                    gradient.setColorAt(1, QColor(70, 70, 70));
                    ui->customPlot->setBackground(QBrush(gradient));

                    // create empty bar chart objects:
                    QCPBars *besoin = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);

                    besoin->setAntialiased(false); // gives more crisp, pixel aligned bar borders

                    besoin->setStackingGap(1);

                    // set names and colors:

                    besoin->setName("prix");
                    besoin->setPen(QPen(QColor(0, 168, 140).lighter(130)));
                besoin->setBrush(QColor(18, 116, 161));
                    // stack bars on top of each other:


                    // prepare x axis with needs' labels:
                    QVector<double> ticks;
                    QVector<QString> labels;

                    for(int i=0; i<rowCount; ++i){
                        ticks.push_back(i);
                        labels.push_back(table_necessiteux.model()->data(table_necessiteux.model()->index(i, 0)).toString().simplified());
                        qDebug()<<ticks[i];
                        qDebug()<<labels[i];
                    }
                    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
                    textTicker->addTicks(ticks, labels);
                    ui->customPlot->xAxis->setTicker(textTicker);
                    ui->customPlot->xAxis->setTickLabelRotation(60);
                    ui->customPlot->xAxis->setSubTicks(false);
                    ui->customPlot->xAxis->setTickLength(0, 4);
                    ui->customPlot->xAxis->setRange(0, 8);
                    ui->customPlot->xAxis->setBasePen(QPen(Qt::black));
                    ui->customPlot->xAxis->setTickPen(QPen(Qt::black));
                    ui->customPlot->xAxis->grid()->setVisible(true);
                    ui->customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
                    ui->customPlot->xAxis->setTickLabelColor(Qt::black);
                    ui->customPlot->xAxis->setLabelColor(Qt::black);

                    // prepare y axis:
                    ui->customPlot->yAxis->setRange(0,50);
                ui->customPlot->yAxis->setPadding(5); // a bit more space to the left border
                ui->customPlot->yAxis->setBasePen(QPen(Qt::white));
                ui->customPlot->yAxis->setTickPen(QPen(Qt::white));
                ui->customPlot->yAxis->setSubTickPen(QPen(Qt::white));
                ui->customPlot->yAxis->grid()->setSubGridVisible(true);
                ui->customPlot->yAxis->setTickLabelColor(Qt::white);
                ui->customPlot->yAxis->setLabelColor(Qt::white);
                ui->customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
                ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

                    // Add data:
                    QVector<double>besoinData;

                    for(int i=0; i<rowCount2; ++i){
                        besoinData.push_back(table_n2.model()->data(table_n2.model()->index(i, 0)).toInt());
                        qDebug()<<besoinData;

                    }

                    besoin->setData(ticks, besoinData);

                    // setup legend:
                    ui->customPlot->legend->setVisible(true);
                ui->customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
                ui->customPlot->legend->setBrush(QColor(255, 255, 255, 100));
                ui->customPlot->legend->setBorderPen(Qt::NoPen);
                QFont legendFont = font();
                legendFont.setPointSize(10);
                ui->customPlot->legend->setFont(legendFont);
                ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

                ui->customPlot->replot();
}


void Mainwnourh::on_close_clicked()
{
    close();

}

void Mainwnourh::on_min_clicked()
{
setWindowState(Qt::WindowMinimized);
}

void Mainwnourh::on_pushButton_5_clicked()
{ Equipement E;
    ui->tab_etudiant->setModel(E.tric_modele());

}

void Mainwnourh::on_pb_tri_2_clicked()
{
    Equipement E;
       ui->tab_etudiant->setModel(E.trid_modele());
}

void Mainwnourh::on_pushButton_6_clicked()
{
    Equipement E;
       ui->tab_etudiant->setModel(E.tri_prix());

}

void Mainwnourh::on_formulaire_clicked()
{
    QSqlQuery fetcher;
            fetcher.prepare("SELECT * FROM etudiant WHERE ref = (:sel) ");
            fetcher.bindValue(":sel", selected);
            fetcher.exec();

            int refe = fetcher.record().indexOf("ref");
            int model = fetcher.record().indexOf("modele");
            int etate = fetcher.record().indexOf("etat");
            int date = fetcher.record().indexOf("date_de_naissance");
            int prixe= fetcher.record().indexOf("prix");


            while (fetcher.next())
            {
                ui->le_ref->setText(fetcher.value(refe).toString());
                ui->le_modele->setText(fetcher.value(model).toString());
                ui->le_etat->setText(fetcher.value(etate).toString());
                //ui->dateEdit->setText(fetcher.value(date).toString());
                ui->le_prix->setText(fetcher.value(prixe).toString());



        }

}


void Mainwnourh::on_tab_etudiant_clicked(const QModelIndex &index)
{
    selected=ui->tab_etudiant->model()->data(index).toInt();
        QMessageBox::information(nullptr, QObject::tr("SUCCESS"),
                    QObject::tr("identifiant is selected\n"
                                ""), QMessageBox::Cancel);
}




void Mainwnourh::aff_table(){
    //Equipement E;
//creation model (masque du tableau) : permet recherche et tri
    proxy = new QSortFilterProxyModel();

 //definir la source (tableau original)
    proxy->setSourceModel(E.afficher());

 //pour la recherche
    proxy->setFilterCaseSensitivity(Qt::CaseInsensitive); // S=s (pas de difference entre majiscule et miniscule)
    proxy->setFilterKeyColumn(-1); // chercher dans tout le tableau (-1) ou donner le numero de la colone
   //remplissage tableau avec le masque
    ui->tab_etudiant->setModel(proxy);

}
void Mainwnourh::on_recherche_textChanged(const QString &arg1)
{
    proxy->setFilterFixedString(arg1);
}


void Mainwnourh::on_pushButton_7_clicked()
{

        aff_table();

}


void Mainwnourh::on_pushButton_clicked()
{
    if(arduino->isWritable()){
        arduino->write("3");
        e--;
        qDebug()<<"Encender";
    }
}

void Mainwnourh::on_pushButton_8_clicked()
{
    if(arduino->isWritable()){
        arduino->write("2");
          e++;
        qDebug()<<"Encender";
    }
}

void Mainwnourh::on_close_5_clicked()
{
    close();

}

void Mainwnourh::on_red_slider_4_sliderMoved(int position)
{
    ui->red_value_label_4->setText(QString("<span style=\" font-size:18pt; font-weight:600;\">%1</span>").arg(position));
       Mainwnourh::updateRGB(QString("r%1").arg(position));
        qDebug() << position;
}


void Mainwnourh::updateRGB(QString command)
{
    if(arduino->isWritable()){
        arduino->write(command.toStdString().c_str());
    }else{
        qDebug() << "Couldn't write to serial!";
    }
}



void Mainwnourh::on_green_slider_4_sliderMoved(int position)
{
    ui->green_value_label_4->setText(QString("<span style=\" font-size:18pt; font-weight:600;\">%1</span>").arg(position));
        Mainwnourh::updateRGB(QString("g%1").arg(position));
        qDebug() << position;
}

void Mainwnourh::on_blue_slider_4_sliderMoved(int position)
{
    ui->blue_value_label_4->setText(QString("<span style=\" font-size:18pt; font-weight:600;\">%1</span>").arg(position));
       Mainwnourh::updateRGB(QString("b%1").arg(position));
       qDebug() << position;
}

void Mainwnourh::on_pushButton_37_clicked()
{
    if(arduino->isWritable()){
        arduino->write("2");
          e++;

        qDebug()<<"Encender";
    }
}

void Mainwnourh::on_pushButton_38_clicked()
{
    if(arduino->isWritable()){
        arduino->write("3");
    e--;
        qDebug()<<"Encender";
    }
}
