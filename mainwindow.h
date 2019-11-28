#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"abonne.h"
#include <QMainWindow>
#include "place.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pushButton_clicked();

    void on_pushButton_ajouter_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_modifier_clicked();

    void on_pushButton_3_clicked();


    void on_stat_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_comboBox_activated(int index);

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

private:
    Ui::MainWindow *ui;
    abonne tmpabonne;
    place tmpplace;

};

#endif // MAINWINDOW_H
