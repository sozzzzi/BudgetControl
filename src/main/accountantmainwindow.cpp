#include <QFile>

#include "edit_expanses.hpp"
#include "accountantmainwindow.hpp"
#include "table_statements.hpp"
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

void AccountantMainWindow::setDataBase(DataBase& db_)
{
    db = db_;

    m_users = db.getUsers();
    m_departments = db.getDepartments();
}

void AccountantMainWindow::setUser(User m_user_)
{
    m_user = m_user_;

    ui->fioLabel->setText(m_user.getSurname() + " " + m_user.getName() + " " + m_user.getPatronymic());
    ui->departmentLabel->setText(m_user.getDepartment());
}

void AccountantMainWindow::openEditExpenses()
{
    Edit_Expanses ee;
    ee.setDepartment(m_departments);
    ee.exec();
    db.save_expanses();
}

void AccountantMainWindow::openTableStatements()
{
    table_statements ts;
    ts.setStatements(*db.getStatements());
    ts.setDepartments(*db.getDepartments());
    ts.exec();
}
