#include "equipement.h"
#include <QSqlQuery>
#include <QtDebug>
#include<QObject>
#include<QSqlQueryModel>
#include <cstring>
#include<QImage>
#include <QVariant>
Equipement::Equipement()
{
    ref=0;
    modele="";
    etat="";
    date="";
    prix=0;



}
Equipement::Equipement(int ref,QString modele,QString etat,QString date,int prix,QString img,int e){

        this->ref=ref;
        this->modele=modele;
        this->etat=etat;
        this->date=date;
        this->prix=prix;
        this->img=img;
        this->e=e;


}

int Equipement:: getref(){
    return ref;
}
QString Equipement:: getmodele () {
    return modele;
}
QString  Equipement::getetat(){ return etat;}

QString  Equipement::getdate(){ return date;}


int Equipement:: getprix(){return prix;}



void Equipement:: setref(int ref){
       this->ref=ref;
}
void Equipement:: setmodele(QString modele){
     this->modele=modele;
}
void Equipement:: setetat(QString etat){
     this->etat=etat;
}

void Equipement:: setdate(QString date){
     this->date=date;
}


void Equipement:: setprix(int prix){
       this->prix=prix;
}



bool Equipement :: ajouter(){

    QSqlQuery query;
    QString ref_string=QString::number(ref);
    QString prix_string=QString::number(prix);
    query.prepare("INSERT INTO ETUDIANT (REF, MODELE, ETAT,DATE1,PRIX,img,ERROR) "
                  "VALUES (:ref, :modele, :etat,  :date,  :prix, :img,:e)");
     query.bindValue(":ref", ref_string);
     query.bindValue(":modele", modele);
     query.bindValue(":etat", etat);
     query.bindValue(":date",date);
     query.bindValue(":prix",prix);
     query.bindValue(":img", img);
     query.bindValue(":e", e);


   return query.exec();


    //return test;
}
bool Equipement ::supprimer(int ref){

    QSqlQuery query;

    query.prepare("Delete from etudiant where REF =:ref  ");
    query.bindValue(0, ref);

   return query.exec();





}
   QSqlQueryModel* Equipement :: afficher(){




            QSqlQueryModel * modal=new QSqlQueryModel();
            modal->setQuery("SELECT * FROM etudiant");

            return modal;


}




   bool Equipement :: modifier(int ref){

          QSqlQuery query;


          query.prepare("UPDATE etudiant set  modele=:modele,etat=:etat,prix=:prix where ref=:ref");

           query.bindValue(":ref", ref);
           query.bindValue(":modele", modele);
           query.bindValue(":etat", etat);
           query.bindValue(":date_de_naissance", date);
           query.bindValue(":prix",prix);
         return query.exec();

}

   QSqlQueryModel * Equipement ::recherchemodele (QString modele )
   {
       QSqlQueryModel * model= new QSqlQueryModel();
       QSqlQuery query;
       modele='%'+modele+'%';

       query.prepare("select * from etudiant where modele like :modele order by modele");
       query.addBindValue(modele);
       query.exec();

       model->setQuery(query);
       model->setHeaderData(0,Qt::Horizontal,QObject::tr("ref"));
       model->setHeaderData(1,Qt::Horizontal,QObject::tr("modele"));
       model->setHeaderData(2,Qt::Horizontal,QObject::tr("etat"));
       model->setHeaderData(3,Qt::Horizontal,QObject::tr("date"));
       model->setHeaderData(4,Qt::Horizontal,QObject::tr("prix"));
       model->setHeaderData(5,Qt::Horizontal,QObject::tr("img"));




           return model;

   }

   QSqlQueryModel * Equipement::rechercheref (QString date)
           {

   QSqlQueryModel *model=new::QSqlQueryModel;
                          model->setQuery("select * from  ETUDIANT where date1 like '%"+date+"%'");
                          return model;

           }




   QSqlQueryModel * Equipement::tri_croissant()
           {
               QSqlQueryModel * model= new QSqlQueryModel();
                   model->setQuery("SELECT * FROM ETUDIANT ORDER BY PRIX ASC");
                   return model;
           }


   QSqlQueryModel * Equipement::tri_deccroissant()
           {
               QSqlQueryModel * model= new QSqlQueryModel();
                   model->setQuery("SELECT * FROM ETUDIANT ORDER BY PRIX DESC");
                   return model;
           }





QSqlQueryModel * Equipement::tric_modele(){

     QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("SELECT * FROM ETUDIANT ORDER BY MODELE ASC");

     return model;

 }


QSqlQueryModel * Equipement::trid_modele(){

     QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("SELECT * FROM ETUDIANT ORDER BY MODELE DESC");

     return model;

 }





  QSqlQueryModel* Equipement::tri_prix()
{
  QSqlQueryModel * model=new QSqlQueryModel();
  model->setQuery("SELECT * FROM ETUDIANT ORDER BY REF ASC");

  return model;
  }







