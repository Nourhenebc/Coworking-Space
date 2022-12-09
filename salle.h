#ifndef SALLE_H
#define SALLE_H
#include<QSqlQuery>
#include<QSqlQueryModel>
#include "qcustomplot.h"


class salle
{
private :
    int numero,nombre ;
    QString tyype,equipement,video;

public:


    salle();
    salle(int num,int nbr,QString tpe,QString eqp,QString video)
    {
        this->numero=num;
        this->nombre=nbr;
        this->tyype=tpe;
        this->equipement=eqp;
        this->video=video;

    }
    salle (int num)
    {
        this->numero=num;
    }

    bool ajouter();
   QSqlQueryModel *afficher();
    bool modifier ();

    bool supprimer ();
    QSqlQueryModel * rechercher(QString);
     QSqlQueryModel *tri();
     QSqlQueryModel * trid();
     QString rechercherV(int rech);
      void stat(QCustomPlot *customPlot);

};

#endif // SALLE_H
