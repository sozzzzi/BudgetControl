#include "employeemainwindow.hpp"
#include "ui_employeemainwindow.h"

EmployeeMainWindow::EmployeeMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EmployeeMainWindow)
{
    ui->setupUi(this);
}

EmployeeMainWindow::~EmployeeMainWindow()
{
    delete ui;
}

void EmployeeMainWindow::setDepartment(Department m_department_)
{
    m_department = m_department_;
}

void EmployeeMainWindow::setUser(User m_user_)
{
    m_user = m_user_;

    ui->fioLabel->setText(m_user.getSurname() + " " + m_user.getName() + " " + m_user.getPatronymic());
    ui->departmentLabel->setText(m_user.getDepartment());
}
