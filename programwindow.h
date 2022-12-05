#ifndef PROGRAMWINDOW_H
#define PROGRAMWINDOW_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <QWidget>
#include <QStandardItemModel>
#include <QTableView>
#include <QLabel>
#include <QBoxLayout>
#include <QMainWindow>
#include <QIcon>
#include <QMenuBar>
#include <QCoreApplication>
#include <QInputDialog>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>
#include "buyers.h"




class CentralField : public QWidget
{
    Q_OBJECT

public:
    CentralField(const std::vector<buyer*> &ptrBuyers, const std::vector<products*> &ptrProducts, std::string currency);
    void majFenetre(const std::vector<buyer*> &ptrBuyers, const std::vector<products*> &ptrProducts, std::string currency);

public slots:


private:
    QStandardItemModel *mBuyer;
    QStandardItemModel *mProduct;
    QTableView *vBuyer;
    QTableView *vProduct;
    QVBoxLayout *orderView1;
    QVBoxLayout *orderView2;
    QHBoxLayout *orderView;
    QLabel *block1;
    QLabel *block2;
    int max;
    QStringList *listP;
    QStringList *listB;
};







class ProgramWindow : public QMainWindow
{
    Q_OBJECT

public:
    ProgramWindow();
    void activating(bool status);

public slots:
    void FnouveauFichier();
    void FouvreSQL();
    void FouvreOrdi();
    void FprendSQL();
    void FprendOrdi();
    void FnouvProduit();
    void FnouvAcheteur();
    void FnouvTransaction();
    void Fajouter();
    void Fpayer();
    void FlisteTransactions();
    void Fpaid();

private:
    CentralField *field;
    std::vector<products*> productVector;
    std::vector<buyer*> buyerVector;
    int choice;
    int car1;
    int car2;
    double quad;
    int turn;
    bool validate;
    char bike;
    std::string devise;
    std::string truck1;
    std::string truck2;
    std::string truck3;
    std::ifstream read;
    std::ofstream write;

    QAction *nouveauFichier;
    QAction *ouvreSQL;
    QAction *ouvreOrdi;
    QAction *prendSQL;
    QAction *prendOrdi;
    QAction *quitter;
    QAction *nouvProduit;
    QAction *nouvAcheteur;
    QAction *nouvTransaction;
    QAction *ajouter;
    QAction *payer;
    QAction *listeTransactions;
    QAction *depense;
    QToolBar *actionBar;
};


class TransactionsWindow : public QWidget
{
    Q_OBJECT

public:
    TransactionsWindow(const std::vector<buyer*> &ptrBuyers);

public slots:


private:
    QTableView *vTransactions;
    QStandardItemModel *mTransactions;
    QStringList *listT;
    int nextRow;

};


#endif // PROGRAMWINDOW_H

