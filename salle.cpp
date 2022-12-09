#include "salle.h"
#include "qcustomplot.h"

/*Salle::Salle(int nombre, int numero, QString tyype, QString equipement)
{
  this->tyype=tyype;
  this->nombre=nombre;
  this->equipement=equipement;
  this->numero=numero;




}
bool Salle:: ajouter()
{
    QSqlQuery qry ;

    QString numero_string=QString::number(numero);
    QString nombre_string=QString::number(nombre);
    qry.prepare("INSERT INTO Etudiant (REF, MODELE, ETAT,DATE1,PRIX) "
                  "VALUES (:id, :forename, :surname,:forename1,:id1)");
       qry.bindValue(":nombre",nombre);
       qry.bindValue(":tyype",tyype);
       qry.bindValue(":numero",numero);
       qry.bindValue(":equipement",equipement);

       return qry.exec();
}
QSqlQueryModel * Salle::afficher()
{
  QSqlQueryModel *model = new QSqlQueryModel();
  model->setQuery("SELECT *FROM Salle");
  model->setHeaderData(1,Qt::Horizontal,QObject::tr("NUMERO"));
  model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOMBRE"));
  model->setHeaderData(1,Qt::Horizontal,QObject::tr("EQUIPEMENT"));
  model->setHeaderData(1,Qt::Horizontal,QObject::tr("TYYPE"));



}
bool Salle::supprimer(int nombre)
{
  QSqlQuery qry ;
  QString res = QString::number(nombre);
  qry.prepare("Delete from Salle where NOMBRE=:NOMBRE");
  qry.bindValue(":NOMBRE",res);
  return qry.exec();

}
bool Salle::modifier()
{
  QSqlQuery query;

  query.prepare("UPDATE Salle set  tyype=:tyype,equipement=:equipement where numero=:numero");

   query.bindValue(":numero", numero);
   query.bindValue(":tyype",tyype);
   query.bindValue(":equipement", equipement);
   query.bindValue(":nombre", nombre);

 return query.exec();}

*/
salle::salle()
{

}
bool salle::ajouter()
{
    QSqlQuery query;
    //QString numero_string=QString::number(numero);
    //QString nombre_string=QString::number(nombre);
    query.prepare("INSERT INTO salle (numero,nombre,tyype,equipement,video) "
      "VALUES (:numero, :nombre, :tyype, :equipement, :video)");
    query.bindValue(":numero",numero);
    query.bindValue(":nombre", nombre);
    query.bindValue(":tyype", tyype);
    query.bindValue(":equipement",equipement );
    query.bindValue(":video",video );

return query.exec();


}
QSqlQueryModel *salle ::afficher()
{
QSqlQueryModel*model =new QSqlQueryModel();

     model->setQuery("SELECT* FROM salle ");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("numero"));
     model->setHeaderData(1, Qt::Horizontal,QObject::tr("nombre"));
     model->setHeaderData(2, Qt::Horizontal,QObject::tr("tyype"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("equipement"));


          /*QTableView *view = new QTableView;
            view->setModel(model);
            view->show();*/

return model;
}
bool salle::supprimer()
{
    QSqlQuery query;
QString numero_string=QString::number(numero);
    query.prepare("DELETE FROM salle where  numero=:numero");

    query.bindValue(":numero",numero_string);

return query.exec();




}
bool salle::modifier()
{
    QSqlQuery query;
    query.prepare("update salle set numero=:numero, nombre=:nombre, tyype=:tyype,equipement=:equipement where numero=:numero");
    query.bindValue(":numero",numero );
    query.bindValue(":nombre", nombre);
    query.bindValue(":tyype", tyype);
    query.bindValue(":equipement",equipement );
    return query.exec();

}

QSqlQueryModel *salle::rechercher(QString rech)
{
    QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * from SALLE where NUMERO LIKE '"+rech+"%'");
    return model;
}

QSqlQueryModel *salle::tri(){

   QSqlQuery *q = new QSqlQuery();
   QSqlQueryModel *model = new QSqlQueryModel();
   q->prepare("SELECT * FROM SALLE ORDER BY NOMBRE ");
   q->exec();
   model->setQuery(*q);

   return model;
}
/*
QSqlQueryModel *Reparations::trid(){

   QSqlQuery *q = new QSqlQuery();
   QSqlQueryModel *model = new QSqlQueryModel();
   q->prepare("SELECT * FROM SALLE ORDER BY NOMBRE DESC");
   q->exec();
   model->setQuery(*q);

   return model;
}
*/
QString salle::rechercherV(int rech)
{
    QSqlQuery *salle = new QSqlQuery();

        salle->prepare("select video from SALLE where NUMERO =:rech");
        salle->bindValue(":rech",rech);
        salle->exec();
        salle->next();
        return salle->value(0).toString();
}
void salle::stat(QCustomPlot *customPlot)
{
    QSqlQuery query,query1;
    // set dark background gradient:
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(70, 70, 70));
    customPlot->clearPlottables();
    customPlot->clearGraphs();
    customPlot->replot();

    customPlot->setBackground(QBrush(gradient));


    QCPBars *fossil = new QCPBars(customPlot->xAxis, customPlot->yAxis);

    fossil->setAntialiased(false);

    fossil->setStackingGap(1);
    // set names and colors:
    fossil->setName("statistique des SALLE");
    fossil->setPen(QPen(QColor(111, 9, 176).lighter(170)));
    fossil->setBrush(QColor(111, 9, 176));

    QVector<double> ticks;
    QVector<QString> labels;
    query.prepare("SELECT COUNT(DISTINCT NUMERO) FROM SALLE where NOMBRE between 0 and 10");
    query.exec();
    int un;
    while(query.next())
    {
        un=query.value(0).toInt();
        qDebug()<<un;
    }
    query.prepare("SELECT COUNT(DISTINCT NUMERO) FROM SALLE where NOMBRE between 10 and 20");
    query.exec();
    int deux;
    while(query.next())
    {
        deux=query.value(0).toInt();
    }

    query.prepare("SELECT COUNT(DISTINCT NUMERO) FROM SALLE where NOMBRE between 20 and 40");
    query.exec();
    int trois;
    while(query.next())
    {
        trois=query.value(0).toInt();
    }





    ticks << 1 << 2 << 3 ;
    labels << "" << "" << "" ;
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    customPlot->xAxis->setTicker(textTicker);
    customPlot->xAxis->setTickLabelRotation(60);
    customPlot->xAxis->setSubTicks(false);
    customPlot->xAxis->setTickLength(0, 4);
    customPlot->xAxis->setRange(0, 8);
    customPlot->xAxis->setBasePen(QPen(Qt::white));
    customPlot->xAxis->setTickPen(QPen(Qt::white));
    customPlot->xAxis->grid()->setVisible(true);
    customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    customPlot->xAxis->setTickLabelColor(Qt::white);
    customPlot->xAxis->setLabelColor(Qt::green);

    // prepare y axis:
    customPlot->yAxis->setRange(0, 20);
    customPlot->yAxis->setPadding(5); // a bit more space to the left border
    customPlot->yAxis->setLabel("Nombre de salle");
    customPlot->yAxis->setBasePen(QPen(Qt::white));
    customPlot->yAxis->setTickPen(QPen(Qt::white));
    customPlot->yAxis->setSubTickPen(QPen(Qt::white));
    customPlot->yAxis->grid()->setSubGridVisible(true);
    customPlot->yAxis->setTickLabelColor(Qt::white);
    customPlot->yAxis->setLabelColor(Qt::white);
    customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

    // Add data:
    QVector<double> fossilData, nuclearData, regenData;
    fossilData  << un << deux << trois;
   // nuclearData << 0.08*10.5 << 0.12*5.5 << 0.12*5.5 << 0.40*5.8 << 0.09*5.2 << 0.00*4.2 << 0.07*11.2;
    regenData   << 0.06*10.5 << 0.05*5.5 << 0.04*5.5 << 0.06*5.8 << 0.02*5.2 << 0.07*4.2 << 0.25*11.2;
    fossil->setData(ticks, fossilData);
  //  nuclear->setData(ticks, nuclearData);
 //   regen->setData(ticks, regenData);

    // setup legend:
    customPlot->legend->setVisible(true);
    customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    customPlot->legend->setBrush(QColor(255, 255, 255, 100));
    customPlot->legend->setBorderPen(Qt::NoPen);
    QFont legendFont = QFont();
    legendFont.setPointSize(10);
    customPlot->legend->setFont(legendFont);
    customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

}
