#include <QDialog>
#include <QMessageBox>
#include <QFile>
#include <QTimer>

#include "mainwindow.hpp"
#include "employeemainwindow.hpp"
#include "accountantmainwindow.hpp"
#include "ui_mainwindow.h"
#include "ui_auth.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    load_users();
    load_expenses();

    User admin;
    admin.setSurname("Халаманов");
    admin.setName("Алексей");
    admin.setPatronymic("Павлович");
    admin.setDepartment("Администрация");
    admin.setPassword("халаманов_папочка");
    m_users.push_back(admin);

//    User user1;
//    user1.setSurname("Абобов");
//    user1.setName("Абоба");
//    user1.setPatronymic("Абобович");
//    user1.setDepartment("Бухгалтерия");
//    user1.setPassword("я лучший тупа");
//    m_users.push_back(user1);

//    User user2;
//    user2.setSurname("Биба");
//    user2.setName("Бибович");
//    user2.setPatronymic("Бибов");
//    user2.setDepartment("Преподаватели");
//    user2.setPassword("я бибка ы");
//    m_users.push_back(user2);

//    User user3;
//    user3.setSurname("Лупов");
//    user3.setName("Лупа");
//    user3.setPatronymic("Лупович");
//    user3.setDepartment("Охрана");
//    user3.setPassword("за мной пупа");
//    m_users.push_back(user3);

//    User user4;
//    user4.setSurname("Пупов");
//    user4.setName("Пупа");
//    user4.setPatronymic("Пупович");
//    user4.setDepartment("Охрана");
//    user4.setPassword("я иду после лупы");
//    m_users.push_back(user4);
    authorization();

    auto updateTimer = new QTimer;
    connect(updateTimer, SIGNAL(timeout()), this, SLOT(exit()));
    updateTimer->start();
}

void MainWindow::load_users()
{
    QFile inf("users.bin");
    inf.open(QIODevice::ReadOnly);
    QDataStream ist(&inf);
    m_users.clear();
    while (!ist.atEnd())
    {
        User u;
        ist >> u;
        m_users.push_back(u);
    }
}

void MainWindow::load_expenses()
{
    QFile inf("expenses.bin");
    inf.open(QIODevice::ReadOnly);
    QDataStream ist(&inf);
    m_expenses.clear();
    while (!ist.atEnd())
    {
        Expenses e;
        ist >> e;
        m_expenses.push_back(e);
    }
}

void MainWindow::getDepartments()
{
    for (size_t i = 0; i < m_users.size(); i++)
    {
        bool find = false;
        for (size_t j = 0; j < m_departments.size(); j++)
        {
            if (m_users[i].getDepartment() == m_departments[j].getName())
            {
                m_departments[j].addUser(m_users[i]);
                find = true;
            }
        }
        if (!find)
        {
            Department d;
            d.setName(m_users[i].getDepartment());
            d.addUser(m_users[i]);
            m_departments.push_back(d);
        }
    }

    for (size_t i = 0; i < m_expenses.size(); i++)
    {
        for (size_t j = 0; j < m_departments.size(); j++)
        {
            if (m_expenses[i].getDepartment() == m_departments[j].getName())
            {
                m_departments[j].addExpense(m_expenses[i]);
                break;
            }
        }
    }
}

void MainWindow::authorization()
{
    QDialog *authForm = new QDialog;
    Ui::authForm ui_authform;
    ui_authform.setupUi(authForm);

    bool try_auth = false; bool auth_succeful = false;
    if (authForm->exec() == QDialog::Accepted)
    {
        try_auth = true;
        QString login = ui_authform.surnameEdit->text();
        QString password = ui_authform.passwordEdit->text();
        for (size_t i = 0; i < m_users.size(); i++)
        {
            if ((m_users[i].getSurname() == login) && (m_users[i].getPassword() == password))
            {
                m_auth_user = m_users[i];
                auth_succeful = true;
            }
        }

    }

    if (auth_succeful)
    {
        QMessageBox::information(0, "BudgetControl", QString("Вы успешно авторизированы, %1 %2 %3.")
                                 .arg(m_auth_user.getSurname()).arg(m_auth_user.getName()).arg(m_auth_user.getPatronymic()));
        getDepartments();
        if (m_auth_user.getDepartment() == "Администрация" || m_auth_user.getDepartment() == "Бухгалтерия")
        {
            AccountantMainWindow *accMW = new AccountantMainWindow;
            accMW->setDepartment(m_departments);
            accMW->setUser(m_auth_user);
            accMW->show();
            this->close();
        }
        else
        {
            EmployeeMainWindow *empMW = new EmployeeMainWindow;
            size_t index = 0;
            for (index = 0; index < m_departments.size(); index++)
            {
                if (m_departments[index].getName() == m_auth_user.getDepartment())
                    break;

            }
            empMW->setDepartment(m_departments[index]);
            empMW->setUser(m_auth_user);
            empMW->show();
            this->close();
        }
    }
    else if (try_auth)
    {
        QMessageBox::information(0, "BudgetControl", "Неверно введены фамилия и/или пароль.\nПопробуйте еще раз.");
        authorization();
    }
}

void MainWindow::exit()
{
    MainWindow::close();
}

MainWindow::~MainWindow()
{
    delete ui;
}

