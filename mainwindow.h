#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "salle.h"
#include "ARDUINO/mainwindow1.h"

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


    void on_ajouter_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();
    void on_rechercher_button_clicked();
    void on_radioButton_croissant_clicked();

 //   void on_radioButton_dcroissant_clicked();
    //void on_btn_imp_clicked();

    void on_view_clicked();

    void on_video_clicked();

    void on_imp_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
   salle s;
 /* MainWindow *ajouter;
     MainWindow *modifier;
  MainWindow *afficher;
  MainWindow *supp;*/
   MainWindow1 *Arduino;

};

#endif // MAINWINDOW_H
