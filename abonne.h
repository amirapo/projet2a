#ifndef ABONNE_H
#define ABONNE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class abonne
{
public:
    abonne();
    abonne(QString,int,int,int);
    QString get_email();
    int get_id();
    int get_hentre();
    int get_hsortie();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
    bool modifier(QString,int,int,int);
    QSqlQueryModel *cherchera(int id);
    QSqlQueryModel* triea(int index);
private:
    QString email;
    int id;
    int hentre;
    int hsortie;
};

#endif // ABONNE_H
