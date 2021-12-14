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
    ed.exec();
    db.save_users();
}
