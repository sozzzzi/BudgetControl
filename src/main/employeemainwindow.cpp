#include "employeemainwindow.hpp"
#include "ui_employeemainwindow.h"
#include "apply.hpp"

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

void EmployeeMainWindow::setDataBase(DataBase& db_)
{
    db = db_;
}

void EmployeeMainWindow::setDepartment(QString m_department_name)
{
    m_department = db.getDepartment(m_department_name);
    ui->departmentLabel->setText(m_department->getName());
}

void EmployeeMainWindow::setUser(User &m_user_)
{
    m_user = m_user_;

    ui->fioLabel->setText(m_user.getSurname() + " " + m_user.getName() + " " + m_user.getPatronymic());
}

void EmployeeMainWindow::apply()
{
    Apply ap;
    Statement st;
    ap.setExpenses(m_department->getExpenses());
    ap.setStatement(&st);
    if (ap.exec() != Apply::Accepted)
        return;
    st.setDate(QDate::currentDate());
    st.setDepartment(m_department->getName());
    st.setEmployee(m_user.getSurname() + " " + m_user.getName() + " " + m_user.getPatronymic());
    m_department->addStatement(st);
    db.add_statement(st);
    db.save_expanses();
}
