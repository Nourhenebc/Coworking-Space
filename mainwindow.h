#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QDialog>
#include <QSerialPort>
#include <QMainWindow>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDialog>
#include <QFileDialog>
#include <QDialog>
#include <QDesktopWidget>
#include <QSettings>
#include <QPrinter>
#include <QTextStream>
#include <QFile>
#include <QDataStream>



#include <QMainWindow>
#include "equipement.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
           QSortFilterProxyModel *proxy;
           void aff_table();

           Equipement E;

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supp_clicked();


    void on_pb_modifier_clicked();

    void on_pb_recherche_clicked();

    void on_pushButton_2_clicked();

    void on_pb_tri_clicked();

    void  on_pb_pdf_clicked();


    void on_date_cursorPositionChanged(int arg1, int arg2);

    void on_pushButton_3_clicked();

    void on_insert_img_clicked();

    void on_add_imageBtn_clicked();
    void on_stat_clicked();


    void on_close_clicked();

    void on_min_clicked();

    void on_pushButton_5_clicked();

    void on_pb_tri_2_clicked();

    void on_pushButton_6_clicked();

    void on_formulaire_clicked();

    void on_tab_etudiant_clicked(const QModelIndex &index);

    void on_recherche_textChanged(const QString &arg1);

    void on_pushButton_7_clicked();

    void on_pushButton_clicked();

    void on_pushButton_8_clicked();

    void on_close_5_clicked();

    void on_red_slider_4_sliderMoved(int position);
    void updateRGB(QString command);

    void on_green_slider_4_sliderMoved(int position);

    void on_blue_slider_4_sliderMoved(int position);

    void on_pushButton_37_clicked();

    void on_pushButton_38_clicked();

private:
    Ui::MainWindow *ui;
    Equipement E1;
      int selected=0;
      QSerialPort *arduino;
      static const quint16 arduino_uno_vendor_id = 9025;
      static const quint16 arduino_uno_product_id = 67;
      QString arduino_port_name;
      bool arduino_is_available;
      int e;
};


#endif // MAINWINDOW_H
#ifndef MAINWINDOW_H


#define MAINWINDOW_H

#include <QMainWindow>
#include "equipement.h"

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

    void on_pb_supp_clicked();

    void on_pushButton_clicked();

    void on_pb_modifier_clicked();

    void on_pb_recherche_clicked();

    void on_pushButton_2_clicked();

    void on_pb_tri_clicked();

    void on_pb_pdf_clicked();

private:
    Ui::MainWindow *ui;
    Equipement E1;




    };

    #endif // MAINWINDOW_H
