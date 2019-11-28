#include "abonne.h"

abonne::abonne()
{
 email="";
 id=0;
 hentre=0;
 hsortie=0;}

abonne::abonne(QString email,int id,int hentre,int hsortie)
{
    this->email=email;
    this->id=id;
    this->hentre=hentre;
    this->hsortie=hsortie;
}

QString abonne::get_email(){return email;}
int abonne::get_id(){return id;}
int abonne::get_hentre(){return hentre;}
int abonne::get_hsortie(){return hsortie;}

bool abonne::ajouter()
{
    QSqlQuery query;

    query.prepare("insert INTO abonnepr (EMAIL,ID,H_ENTRE,H_SORTIE) VALUES(:email,:id,:h_entre,:h_sortie)");
    query.bindValue(":email",email);
    query.bindValue(":id",id);
    query.bindValue(":h_entre",hentre);
    query.bindValue(":h_sortie",hsortie);
    return query.exec();
}

QSqlQueryModel * abonne::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from abonnepr");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("email"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("id "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("hentre"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("hsortie"));
    return model;
}

bool abonne::supprimer(QString mail)
{
    QSqlQuery query;
query.prepare("Delete from abonnepr where EMAIL =:mail");
query.bindValue(":mail", mail);
return   query.exec();
}

bool abonne::modifier(QString email,int id,int h_entre,int h_sortie)
{
    QSqlQuery query;
    QString res=email;
    query.prepare("update abonnepr set id=:id,h_entre=:h_entre,h_sortie=:h_sortie where EMAIL='"+res+"'");
    query.bindValue(":EMAIL",res);
    query.bindValue(":id",id);
    query.bindValue(":h_entre",h_entre);
    query.bindValue(":h_sortie",h_sortie);
    return query.exec();
}

QSqlQueryModel * abonne::cherchera(int id)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * from abonnepr where id like :id order by h_entre ");
    query.bindValue(":id",id);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("email"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("h_entre"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("h_sortie"));
    return model;
}
QSqlQueryModel* abonne::triea(int index)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    if(index == 0)
    {
        model->setQuery("select *FROM abonnepr ORDER BY ID ASC");
    }
    else
    {
        model->setQuery("select *FROM abonnepr ORDER BY ID DESC ");
    }


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("email"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("h_entre"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("h_sortie"));

    return model;
}
