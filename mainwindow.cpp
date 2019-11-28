#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"abonne.h"
#include <QMessageBox>
#include "place.h"
#include "statistique.h"
#include <QSqlQueryModel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabAbonne->setModel(tmpabonne.afficher());
    ui->tab_place->setModel(tmpplace.afficherp());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{

    QString email= ui->lineEdit_email->text();
    int id = ui->lineEdit_id->text().toInt();
    int hentre = ui->lineEdit_heure_entree->text().toInt();
    int hsortie  = ui->lineEdit_heure_sortie->text().toInt();
    abonne e(email,id,hentre,hsortie);
    bool test=false;
    int i;
    for(i=0;i<email.size();i++)
    {if(email[i]=="@")
    test=true;}
    if(test)
    {e.ajouter();}
    if(test)
    {ui->tabAbonne->setModel(tmpabonne.afficher());
        QMessageBox::information(nullptr, QObject::tr("Ajouter un abonne"),
                                 QObject::tr("abonne ajouté.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un abonne"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_supprimer_clicked()
{
    QString mail=ui->lineEdit_id_2->text();
    bool test=tmpabonne.supprimer(mail);
    if(test)
    {ui->tabAbonne->setModel(tmpabonne.afficher());
        QMessageBox::information(nullptr, QObject::tr("supprimer un abonne"),
                                 QObject::tr("abonne supprimer.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);}
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un abonne"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_clicked()
{
    QString email=ui->lineEdit_email->text();
    int id=ui->lineEdit_id->text().toInt();
    int hentre=ui->lineEdit_heure_entree->text().toInt();
    int hsortie=ui->lineEdit_heure_sortie->text().toInt();
    abonne a;
    bool atout=a.modifier(email,id,hentre,hsortie);
    if(atout)
    {ui->tabAbonne->setModel(tmpabonne.afficher());
        QMessageBox::information(nullptr, QObject::tr("modifier un abonne"),
                                 QObject::tr("abonne modifié.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);}
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier un abonne"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pushButton_ajouter_clicked()
{
    int id = ui->lineEdit_id2->text().toInt();
    int nb_place = ui->lineEdit_pnbplace->text().toInt();
    int nb_voiture  = ui->lineEdit_nbvoiture->text().toInt();
    float tarif = ui->lineEdit_tarif->text().toFloat();
    place p(id,nb_place,nb_voiture,tarif);
    bool test=false;
    if(id>0)
    {test=true;}
    if (test)
    {p.ajouterp();}
    if(test)
    {
        ui->tab_place->setModel(tmpplace.afficherp());

        QMessageBox::information(nullptr, QObject::tr("Ajouter une place"),
                                 QObject::tr("place ajouté.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter une place"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_2_clicked()
{
    int id=ui->lineEdit_idd->text().toInt();
    bool test=tmpplace.supprimerp(id);
    if(test)
    {ui->tab_place->setModel(tmpplace.afficherp());
        QMessageBox::information(nullptr, QObject::tr("supprimer une place"),
                                 QObject::tr("place supprimer.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);}
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une place"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_modifier_clicked()
{
    int id=ui->lineEdit_id2->text().toInt();
    int nb_place=ui->lineEdit_pnbplace->text().toInt();
    int nb_voiture=ui->lineEdit_nbvoiture->text().toInt();
    float tarif=ui->lineEdit_tarif->text().toFloat();
    place p;
    bool atout=p.modifierp(id,nb_place,nb_voiture,tarif);
    if(atout)
    {ui->tab_place->setModel(tmpplace.afficherp());
        QMessageBox::information(nullptr, QObject::tr("modifier une place"),
                                 QObject::tr("place modifié.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);}
    else
        QMessageBox::critical(nullptr, QObject::tr("Modifier une place"),
                              QObject::tr("Erreur !.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}









void MainWindow::on_pushButton_3_clicked()
{
    int id=ui->chercher->text().toInt();

    ui->tab_place->setModel(tmpplace.chercher(id));

}

void MainWindow::on_stat_clicked()
{
    statistique *a=new statistique();
    a->show();
}




void MainWindow::on_pushButton_4_clicked()
{
    int id=ui->lineEdit_chercher->text().toInt();

    ui->tabAbonne->setModel(tmpabonne.cherchera(id));
}


void MainWindow::on_pushButton_5_clicked()
{
   ui->tab_place->setModel(tmpplace.trie(0));
}

void MainWindow::on_pushButton_6_clicked()
{
     ui->tab_place->setModel(tmpplace.trie(1));
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->tabAbonne->setModel(tmpabonne.triea(0));
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->tabAbonne->setModel(tmpabonne.triea(2));
}

void MainWindow::on_pushButton_9_clicked()
{
     ui->tab_place->setModel(tmpplace.afficherp());
}

void MainWindow::on_pushButton_10_clicked()
{
     ui->tabAbonne->setModel(tmpabonne.afficher());
}
