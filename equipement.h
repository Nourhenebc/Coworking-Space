#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H
#include<QString>
#include<QSqlQueryModel>
#include <QVariant>
class Equipement
{

private :
    int ref,prix;
    QString modele,etat,date,img;


public:
    Equipement();
    Equipement(int,QString,QString,QString,int,QString);


    int getref();
    QString getmodele();
    QString getetat();
    QString getdate();
     int getprix();


    void setref(int);
    void setmodele(QString);
    void setetat(QString);
    void setdate(QString);
    void setprix(int);
    bool ajouter();
    bool test/*=false*/;
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int);
     QSqlQueryModel* recherchemodele (QString);
      QSqlQueryModel* rechercheref (QString);
     QSqlQueryModel* tri_croissant();
     QSqlQueryModel* tri_deccroissant();
     bool ajouterimg();
        QSqlQueryModel* tri_prix();
     QSqlQueryModel *tric_modele();
     QSqlQueryModel *trid_modele();

     QVariant PersonasModel;
};

#endif // EQUIPEMENT_H
