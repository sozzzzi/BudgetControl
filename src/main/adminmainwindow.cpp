#include "adminmainwindow.hpp"
#include "ui_adminmainwindow.h"
#include "edit_departments.hpp"

AdminMainWindow::AdminMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminMainWindow)
{
    ui->setupUi(this);
}

AdminMainWindow::~AdminMainWindow()
{
    delete ui;
}

void AdminMainWindow::setDataBase(DataBase& db_)
{
    db = db_;

    m_departments = db.getDepartments();
}

void AdminMainWindow::setUser(User m_user_)
{
    m_user = m_user_;

    ui->fioLabel->setText(m_user.getSurname() + " " + m_user.getName() + " " + m_user.getPatronymic());
}

void AdminMainWindow::openEditDepartments()
{
    Edit_Departments ed;
    ed.setDepartments(m_departments);
    ed.setAccountant(db.getAccountant());
    ed.exec();
    db.save_users();
}

void AdminMainWindow::exportUsers()
{
    db.save_users_csv();
}

void AdminMainWindow::exportExpenses()
{
    db.save_expenses_csv();
}

void AdminMainWindow::exportStatements()
{
    db.save_statements_csv();
}

void AdminMainWindow::importUsers()
{
    db.load_users_csv();
}

void AdminMainWindow::importExpenses()
{
    db.load_expenses_csv();
}

void AdminMainWindow::importStatements()
{
    db.load_statements_csv();
}

