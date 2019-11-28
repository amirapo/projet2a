#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{
    QString username=ui->lineEdit->text();
    QString password=ui->lineEdit_2->text();
    if(username =="amira"&& password=="123")
    {QMessageBox::information(this,"login","username is correct");
    hide();
    mainwindow=new MainWindow(this);
    mainwindow->show();
    }
    else {
        QMessageBox::warning(this,"login","username and password incorrect");
    }
}
