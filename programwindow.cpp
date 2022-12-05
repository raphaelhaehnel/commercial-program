#include "programwindow.h"

using namespace std;

ProgramWindow::ProgramWindow()
{

    QMenu *menuFichier = menuBar()->addMenu("&File");
    QMenu *menuEdition = menuBar()->addMenu("&Edit");
    QMenu *menuAffichage = menuBar()->addMenu("Information");

    nouveauFichier = menuFichier->addAction("New file");
    QMenu *ouvrir = menuFichier->addMenu("Open");
        ouvreSQL = ouvrir->addAction("From SQL database");
        ouvreOrdi = ouvrir->addAction("From computer");
    QMenu *sauvegarder = menuFichier->addMenu("Save");
        prendSQL = sauvegarder->addAction("In the SQL database");
        prendOrdi = sauvegarder->addAction("In the computer");
    quitter = menuFichier->addAction("Quit");

    QMenu *nouveau = menuEdition->addMenu("New");
        nouvProduit = nouveau->addAction("New product");
        nouvAcheteur = nouveau->addAction("New buyer");
        nouvTransaction = nouveau->addAction("New transaction");
    ajouter = menuEdition->addAction("Add quantity");
    payer = menuEdition->addAction("Payement");

    listeTransactions = menuAffichage->addAction("Transactions");
    depense = menuAffichage->addAction("Money spent");


    nouvProduit->setShortcut((QKeySequence("Ctrl+P")));
    nouvAcheteur->setShortcut((QKeySequence("Ctrl+B")));
    nouvTransaction->setShortcut((QKeySequence("Ctrl+T")));
    listeTransactions->setShortcut((QKeySequence("Ctrl+L")));

    std::cout << "PATH " << QCoreApplication::applicationDirPath().toStdString() << std::endl;

    nouveauFichier->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/icones_qaction/new_fichier.png"));
    ouvreSQL->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/icones_qaction/ouvrir_sql.png"));
    ouvreOrdi->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/icones_qaction/ouvrir_ordi.png"));
    prendSQL->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/icones_qaction/sauver_sql.png"));
    prendOrdi->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/icones_qaction/sauver_ordi.png"));
    nouvProduit->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/icones_qaction/new_produit.png"));
    nouvAcheteur->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/icones_qaction/new_acheteur.png"));
    nouvTransaction->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/icones_qaction/new_transaction.png"));
    ajouter->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/icones_qaction/ajouter_quantite.png"));
    payer->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/icones_qaction/payer.png"));
    listeTransactions->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/icones_qaction/transactions.png"));
    depense->setIcon(QIcon(QCoreApplication::applicationDirPath() + "/icones_qaction/depense.png"));


    actionBar = addToolBar("ToolBar");
    actionBar->addAction(nouveauFichier);
    actionBar->addAction(ouvreSQL);
    actionBar->addAction(ouvreOrdi);
    actionBar->addAction(prendSQL);
    actionBar->addAction(prendOrdi);
    actionBar->addSeparator();
    actionBar->addAction(nouvProduit);
    actionBar->addAction(nouvAcheteur);
    actionBar->addAction(nouvTransaction);
    actionBar->addAction(ajouter);
    actionBar->addAction(payer);
    actionBar->addSeparator();
    actionBar->addAction(listeTransactions);
    actionBar->addAction(depense);
    actionBar->addSeparator();


    QObject::connect(nouveauFichier, SIGNAL(triggered()), this, SLOT(FnouveauFichier()));
    QObject::connect(ouvreSQL, SIGNAL(triggered()), this, SLOT(FouvreSQL()));
    QObject::connect(ouvreOrdi, SIGNAL(triggered()), this, SLOT(FouvreOrdi()));
    QObject::connect(prendSQL, SIGNAL(triggered()), this, SLOT(FprendSQL()));
    QObject::connect(prendOrdi, SIGNAL(triggered()), this, SLOT(FprendOrdi()));
    QObject::connect(quitter, SIGNAL(triggered()), qApp, SLOT(quit()));

    QObject::connect(nouvProduit, SIGNAL(triggered()), this, SLOT(FnouvProduit()));
    QObject::connect(nouvAcheteur, SIGNAL(triggered()), this, SLOT(FnouvAcheteur()));
    QObject::connect(nouvTransaction, SIGNAL(triggered()), this, SLOT(FnouvTransaction()));
    QObject::connect(ajouter, SIGNAL(triggered()), this, SLOT(Fajouter()));
    QObject::connect(payer, SIGNAL(triggered()), this, SLOT(Fpayer()));

    QObject::connect(listeTransactions, SIGNAL(triggered()), this, SLOT(FlisteTransactions()));
    QObject::connect(depense, SIGNAL(triggered()), this, SLOT(Fpaid()));


    field = new CentralField(buyerVector, productVector, devise);
    devise = "NONE";

    this->setCentralWidget(field);
    this->setWindowTitle("Commercial simulation");
    this->setWindowIcon(QIcon(QCoreApplication::applicationDirPath() + "/icones_qaction/icone_fenetre.png"));
    this->setMinimumWidth(570);
    this->setMinimumHeight(350);
    this->activating(true);
}


void ProgramWindow::activating(bool status)
{
    prendSQL->setDisabled(status);
    prendOrdi->setDisabled(status);
    nouvProduit->setDisabled(status);
    nouvAcheteur->setDisabled(status);
    nouvTransaction->setDisabled(status);
    ajouter->setDisabled(status);
    payer->setDisabled(status);
    listeTransactions->setDisabled(status);
    depense->setDisabled(status);
}


void ProgramWindow::FnouveauFichier()
{
    bool ok = false;
    QString Qdevise = QInputDialog::getText(this, "New currency", "Type the currency" , QLineEdit::Normal, QString(), &ok);
    if (ok && !Qdevise.isEmpty())
    {
        devise = Qdevise.toStdString();
        QMessageBox::information(this, "New currency", "The trades will be in " + Qdevise + ".\nA new session has been started.");
        for (int i=productVector.size()-1; i>=0; i--)
        {
            delete productVector[i];
            productVector.pop_back();
        }

        for (int i=buyerVector.size()-1; i>=0; i--)
        {
            delete buyerVector[i];
            buyerVector.pop_back();
        }
        field->majFenetre(buyerVector, productVector, devise);
        this->activating(false);
    } else
        QMessageBox::information(this, "New currency", "you canceled the operation");
}

void ProgramWindow::FouvreSQL()
{

}

void ProgramWindow::FouvreOrdi()
{
    read.open("registerDeals.reg");

    read.seekg(0, ios::end);
    int taille = read.tellg();
    read.seekg(0, ios::beg);

    if (read && taille > 1)
    {
        statusBar()->showMessage(tr("Loading data. Please wait..."));
        truck1 = "";

            //Récupère la devise
            do
            {
                read.get(bike);
                if (bike == ';')
                    validate = false;
                else
                    truck1 += bike;
            }
            while (validate == true);
            devise = truck1;
            read.get(bike);


            //Récupère les produits
            validate = true;
            do
            {
                truck1 = "";
                do
                {
                    read.get(bike);
                    if (bike == ',' || bike == ';')
                        validate = false;
                    else
                        truck1 += bike;
                } while (validate == true);
                if (truck1.size()>0)
                    productVector.push_back(new products(truck1));
                if (bike != ';')
                    validate = true;
            } while (validate == true);
            read.get(bike);


            //Récupère les prix
            car1 = productVector.size();
            if (car1)
            {
                for (int i=0; i<car1; i++)
                {
                    read >> quad;
                    productVector[i]->setPrice(quad);
                    read.get(bike);
                }
            }
            read.get(bike);


            //Récupère les quantités
            if (car1)
            {
                for (int i=0; i<car1; i++)
                {
                    read >> car2;
                    productVector[i]->setAmount(car2);
                    read.get(bike);
                }
            }
            read.get(bike);


            //Récupère les acheteurs
            validate = true;
            truck1 = "";
            do
            {
                truck1 = "";
                do
                {
                    read.get(bike);
                    if (bike == ',' || bike == ';')
                        validate = false;
                    else
                        truck1 += bike;
                } while (validate == true);
                if (truck1.size()>0)
                    buyerVector.push_back(new buyer(truck1));
                if (bike != ';')
                    validate = true;
            } while (validate == true);
            read.get(bike);


            //Récupère l'historique des achats
            turn = buyerVector.size();
            for (int i=0; i<turn; i++)
            {
                read >> car1;
                read.get(bike);

                if (bike != ';')
                {
                    truck1 = anyToString(car1) + bike;
                    int add = 3;

                    while (bike != ';')
                    {
                        for (int j=0; j<10-add; j++)
                        {
                            read.get(bike);
                            truck1 += bike;
                        }
                        read.get(bike);
                        read >> car1;
                        read.get(bike);
                        read >> car2;
                        read.get(bike);
                        buyerVector[i]->sell(productVector[car1]->getName(), car2, truck1);
                        truck1 = "";
                        add = 0;
                    }

                    read >> car1;
                    read.get(bike);
                }
                buyerVector[i]->pay(car1);
                read.get(bike);
            }

            statusBar()->showMessage(tr("The data has been copied successfully."));
            field->majFenetre(buyerVector, productVector, devise);
            this->activating(false);

        } else
            statusBar()->showMessage(tr("ERROR : impossible to read !"));
}

void ProgramWindow::FprendSQL()
{

}

void ProgramWindow::FprendOrdi()
{
    write.open("registerDeals.reg");

    if (write)
    {
        car1 = productVector.size();
        car2 = buyerVector.size();

        //Ecriture de la devise
        write << devise << ';' << endl;


        //Ecriture du nom des produits
        if (car1>0)
        {
            for (int i=0; i<car1; i++)
            {
                if (i>0)
                    write << ',';
                write << productVector[i]->getName();
            }
        }
        write << ';' << endl;


        //Ecriture des prix
        if (car1>0)
        {
            for (int i=0; i<car1; i++)
            {
                if (i>0)
                    write << ',';
                write << productVector[i]->getPrice();
            }
        }
        write << ';' << endl;


        //Ecriture des quantites
        if (car1>0)
        {
            for (int i=0; i<car1; i++)
            {
                if (i>0)
                    write << ',';
                write << productVector[i]->getAmount();
            }
        }
        write << ';' << endl;


        //Ecriture des acheteurs
        if (car2>0)
        {
            for (int i=0; i<car2; i++)
            {
                if (i>0)
                    write << ',';
                write << buyerVector[i]->getName();
            }
        }
        write << ';' << endl;


        //Ecriture des achats
        if (car2>0)
        {
            for (int i=0; i<car2; i++)
            {
                turn = buyerVector[i]->sellNumber();
                for(int j=0; j<turn; j++)
                {
                    if (j>0)
                        write << ',';
                    truck1 = buyerVector[i]->getObjetName(j);
                    validate = false;
                    int k=0;
                    while (!validate)
                    {
                        if (productVector[k]->getName() == truck1)
                            validate = true;
                        else
                            k++;
                    }
                    write << buyerVector[i]->getObjetDate(j) << '=' << k << '*' << buyerVector[i]->getObjetAmount(j) << ';';
                }
                write << buyerVector[i]->paid() << ';' << endl;
            }
        }

        statusBar()->showMessage(tr("The data has been saved"));

    } else
        statusBar()->showMessage(tr("ERROR : impossible to write !"));
}

void ProgramWindow::FnouvProduit()
{
    bool ok = false;
    QString pseudo = QInputDialog::getText(this, "Product name", "Enter the name of the product" , QLineEdit::Normal, QString(), &ok);
    if (ok && !pseudo.isEmpty())
    {
        validate = true;
        truck1 = pseudo.toStdString();
        for (unsigned short i=0; i < productVector.size(); i++)
        {
            if (productVector[i]->getName() == truck1)
                validate = false;
        }

        if (validate==true)
        {
            quad = QInputDialog::getDouble(this, "Product price", "Enter the price of the product");
            car2 = QInputDialog::getInt(this, "Product amount", "Enter the amount of the productt");

            productVector.push_back(new products(truck1, quad, car2));
            QMessageBox::information(this, "Success", "The product has been added");
            field->majFenetre(buyerVector, productVector, devise);

        } else
            QMessageBox::critical(this, "Error", "This product already exist");
    }
}

void ProgramWindow::FnouvAcheteur()
{
    bool ok = false;
    QString name = QInputDialog::getText(this, "New buyer", "Enter the name of the buyer" , QLineEdit::Normal, QString(), &ok);
    if (ok && !name.isEmpty())
    {
        truck1 = name.toStdString();
        for (unsigned int i=0; i < buyerVector.size(); i++)
        {
            if (buyerVector[i]->getName() == truck1)
            {
                ok = false;
                QMessageBox::critical(this, "Error", "This buyer already exist");
            }
        }
        if (ok)
        {
            buyerVector.push_back(new buyer(truck1));
            QMessageBox::information(this, "New buyer", QString::fromStdString("The buyer \"" + truck1 + "\" has been added to the list."));
            field->majFenetre(buyerVector, productVector, devise);
        }
    }
}

void ProgramWindow::FnouvTransaction()
{
    validate = false;

    bool ok = false;
    QString name = QInputDialog::getText(this, "New transaction", "Enter the name of the buyer" , QLineEdit::Normal, QString(), &ok);
    if (ok && !name.isEmpty())
    {
        truck1 = name.toStdString();
        truck2 = QInputDialog::getText(this, "New transaction", "Enter the name of the product").toStdString();
        car1 = QInputDialog::getInt(this, "New transaction", "Enter the quantity");
        truck3 = QInputDialog::getText(this, "New transaction", "Enter the date (in format dd/mm/yyyy)").toStdString();

        if (car1 > 0)
        {
            for (unsigned short i=0; i < buyerVector.size(); i++)
            {
                if (buyerVector[i]->getName() == truck1)
                {
                    for (unsigned short j=0; j < productVector.size(); j++)
                    {
                        if (productVector[j]->getName() == truck2)
                        {
                            if (productVector[j]->getAmount() >= car1)
                            {
                                buyerVector[i]->sell(productVector[j]->getName(), car1, truck3);
                                productVector[j]->sell(car1);
                                validate = true;

                            }
                        }
                    }
                }
            }
        }
        if (validate)
        {
            QMessageBox::information(this, "New buyer", "The selling has been executed.");
            field->majFenetre(buyerVector, productVector, devise);
        }
        else
            QMessageBox::warning(this, "New buyer", "This selling cannot be performed. Please verify that the sale may be carried out.");
    }
}

void ProgramWindow::Fajouter()
{
    bool ok = false;
    QString name = QInputDialog::getText(this, "Increasing quantity", "Enter the name of the product that you want to increase the quantity" , QLineEdit::Normal, QString(), &ok);
    if (ok && !name.isEmpty())
    {
        validate = false;
        truck1 = name.toStdString();
        car1 = QInputDialog::getInt(this, "Increasing quantity", "Of which quantity ?");
        for (unsigned int i=0; i < productVector.size(); i++)
        {
            if (productVector[i]->getName() == truck1)
            {
                productVector[i]->increasingAmout(car1);
                validate = true;
                car2 = i;
            }
        }
        if (validate)
        {
            QMessageBox::information(this, "Increasing quantity", QString::fromStdString("The quantity of the product \"" + truck1 + "\" is now of " + anyToString(productVector[car2]->getAmount()) + "."));
            field->majFenetre(buyerVector, productVector, devise);
        }
        else
            QMessageBox::warning(this, "Increasing quantity", QString::fromStdString("The product \"" + truck1 + "\" has not been found."));
    }
}

void ProgramWindow::Fpayer()
{
    validate = false;
    bool ok = false;
    QString person = QInputDialog::getText(this, "Payement", "Of which person do you want to make pay" , QLineEdit::Normal, QString(), &ok);
    if (ok && !person.isEmpty())
    {
        truck1 = person.toStdString();
        for (unsigned short i=0; i < buyerVector.size(); i++)
        {
            if (buyerVector[i]->getName() == truck1)
            {
                validate = true;
                quad = QInputDialog::getDouble(this, "Payement", QString::fromStdString(truck1 + " owes you " + anyToString(buyerVector[i]->dues(productVector)) + ' ' + anyToString(devise) + ".\nHow much does he paid ? "));
                buyerVector[i]->pay(quad);
                QMessageBox::information(this, "Payement", QString::fromStdString(truck1 + " now owes you " + anyToString(buyerVector[i]->dues(productVector)) + ' ' + anyToString(devise) + '.'));
                field->majFenetre(buyerVector, productVector, devise);
            }
        }
        if (!validate)
            QMessageBox::warning(this, "Payement", "This person doesn't exit !");
    }
}

void ProgramWindow::FlisteTransactions()
{
    TransactionsWindow *lesTransactions = new TransactionsWindow(buyerVector);
    lesTransactions->show();
}

void ProgramWindow::Fpaid()
{
    validate = false;

    bool ok = false;
    QString person = QInputDialog::getText(this, "Total paid", "Of which person do you want to see who much he spent ?" , QLineEdit::Normal, QString(), &ok);
    if (ok && !person.isEmpty())
    {
        truck1 = person.toStdString();
        for (unsigned short i=0; i < buyerVector.size(); i++)
        {
            if (buyerVector[i]->getName() == truck1)
            {
                validate = true;
                QMessageBox::information(this, "Total paid", QString::fromStdString(truck1 + " spent a total of " + anyToString(buyerVector[i]->paid()) + ' ' + anyToString(devise) + '.'));
            }
        }
        if (!validate)
            QMessageBox::warning(this, "Total paid", "This person doesn't exit !");
    }
}


CentralField::CentralField(const std::vector<buyer*> &ptrBuyers, const std::vector<products*> &ptrProducts, string currency)
{
    vProduct = new QTableView;
    vBuyer = new QTableView;
    mProduct = 0;
    mBuyer = 0;

    listP = new QStringList;
        *listP << "Name" << "Price" << "Amount";
    listB = new QStringList;
        *listB << "Name" << "Balance";

    this->majFenetre(ptrBuyers, ptrProducts, currency);


    vProduct->setColumnWidth(1, 70);
    vProduct->setColumnWidth(2, 70);
    vProduct->setFixedWidth(290);
    vProduct->setSelectionMode(QAbstractItemView::NoSelection);
    vProduct->setEditTriggers(QAbstractItemView::NoEditTriggers);
    block1 = new QLabel("List of products");
    block1->setStyleSheet("text-decoration: underline; font-size: 15px;");

    vBuyer->setColumnWidth(1, 70);
    vBuyer->setFixedWidth(220);
    vBuyer->setSelectionMode(QAbstractItemView::NoSelection);
    vBuyer->setEditTriggers(QAbstractItemView::NoEditTriggers);
    block2 = new QLabel("List of buyers");
    block2->setStyleSheet("text-decoration: underline; font-size: 15px;");

    orderView1 = new QVBoxLayout;
    orderView1->addWidget(block1);
    orderView1->addWidget(vProduct);

    orderView2 = new QVBoxLayout;
    orderView2->addWidget(block2);
    orderView2->addWidget(vBuyer);

    orderView = new QHBoxLayout;
    orderView->addLayout(orderView1);
    orderView->addSpacing(20);
    orderView->addLayout(orderView2);

    this->setLayout(orderView);
}


void CentralField::majFenetre(const std::vector<buyer*> &ptrBuyers, const std::vector<products*> &ptrProducts, string currency)
{
    if (mProduct)
    {
        delete mProduct;
        mProduct = 0;
    }
    mProduct = new QStandardItemModel(0, 3);
    max = ptrProducts.size();
    for (int i=0; i<max; i++)
    {
        mProduct->setItem(i, 0, new QStandardItem(QString::fromStdString(ptrProducts[i]->getName())));
        mProduct->setItem(i, 1, new QStandardItem(QString::fromStdString(anyToString(ptrProducts[i]->getPrice()))));
        mProduct->setItem(i, 2, new QStandardItem(QString::fromStdString(anyToString(ptrProducts[i]->getAmount()))));
    }
    mProduct->setHorizontalHeaderLabels(*listP);
    vProduct->setModel(mProduct);


    if (mBuyer)
    {
        delete mBuyer;
        mBuyer = 0;
    }
    mBuyer = new QStandardItemModel(0, 2);
    max = ptrBuyers.size();
    for (int i=0; i<max; i++)
    {
        mBuyer->setItem(i, 0, new QStandardItem(QString::fromStdString(ptrBuyers[i]->getName())));
        mBuyer->setItem(i, 1, new QStandardItem(QString::fromStdString(anyToString(ptrBuyers[i]->dues(ptrProducts)) + " " + anyToString(currency))));
    }
    mBuyer->setHorizontalHeaderLabels(*listB);
    vBuyer->setModel(mBuyer);
}



TransactionsWindow::TransactionsWindow(const std::vector<buyer*> &ptrBuyers)
{
    vTransactions = new QTableView(this);
    listT = new QStringList;
        *listT << "Buyer name" << "Product name" << "Amount" << "Date";

    mTransactions = new QStandardItemModel(0, 4);
    nextRow = 0;

    for (unsigned short i = 0; i < ptrBuyers.size(); i++)
        for (unsigned short j = 0; j < ptrBuyers[i]->sellNumber(); j++)
        {
            mTransactions->setItem(nextRow, 0, new QStandardItem(QString::fromStdString(ptrBuyers[i]->getName())));
            mTransactions->setItem(nextRow, 1, new QStandardItem(QString::fromStdString(ptrBuyers[i]->getObjetName(j))));
            mTransactions->setItem(nextRow, 2, new QStandardItem(QString::fromStdString(anyToString(ptrBuyers[i]->getObjetAmount(j)))));
            mTransactions->setItem(nextRow, 3, new QStandardItem(QString::fromStdString(ptrBuyers[i]->getObjetDate(j))));
            nextRow++;
        }

    mTransactions->setHorizontalHeaderLabels(*listT);
    vTransactions->setModel(mTransactions);
    vTransactions->setSelectionMode(QAbstractItemView::NoSelection);
    vTransactions->setEditTriggers(QAbstractItemView::NoEditTriggers);
    vTransactions->setFixedWidth(535);
    vTransactions->setFixedHeight(250);

    this->setWindowTitle("Transactions table");
    this->setWindowIcon(QIcon(QCoreApplication::applicationDirPath() + "/icones_qaction/icone_transactions.png"));
    this->setFixedWidth(535);
    this->setFixedHeight(250);
    this->setAttribute(Qt::WA_DeleteOnClose);
}
