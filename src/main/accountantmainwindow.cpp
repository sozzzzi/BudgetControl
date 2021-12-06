#include "accountantmainwindow.hpp"
#include "ui_accountantmainwindow.h"

AccountantMainWindow::AccountantMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AccountantMainWindow)
{
    ui->setupUi(this);
}

AccountantMainWindow::~AccountantMainWindow()
{
    delete ui;
}
