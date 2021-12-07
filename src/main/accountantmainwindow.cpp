#include <QFile>

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

void AccountantMainWindow::save_departments()
{
    save_users();
    save_expenses();
}

void AccountantMainWindow::save_users()
{
    QFile outf("users.bin");
    outf.open(QIODevice::WriteOnly);
    QDataStream ost(&outf);
    for (size_t i = 0; i < m_departments.size(); i++)
    {
        std::vector<User> m_users = m_departments[i].getUsers();

        for (size_t j = 0; j < m_users.size(); j++)
        {
            if (m_users[j].getDepartment() != "Администрация")
                ost << m_users[j];
        }

    }
    outf.close();
}

void AccountantMainWindow::save_expenses()
{
    QFile outf("expenses.bin");
    outf.open(QIODevice::WriteOnly);
    QDataStream ost(&outf);
    for (size_t i = 0; i < m_departments.size(); i++)
    {
        std::vector<Expenses> m_expenses = m_departments[i].getExpense();

        for (size_t j = 0; j < m_expenses.size(); j++)
        {
            if (m_expenses.at(j).getDepartment() != "Администрация")
                ost << m_expenses[j];
        }

    }
    outf.close();
}

void AccountantMainWindow::setDepartment(std::vector<Department> m_departments_)
{
    m_departments = m_departments_;
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
    ee.setDepartment(&m_departments);
    ee.exec();
    save_departments();
}
