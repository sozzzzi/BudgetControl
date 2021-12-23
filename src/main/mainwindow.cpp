#include <QDialog>
#include <QMessageBox>
#include <QFile>
#include <QTimer>

#include "mainwindow.hpp"
#include "employeemainwindow.hpp"
#include "accountantmainwindow.hpp"
#include "adminmainwindow.hpp"
#include "database.hpp"
#include "ui_mainwindow.h"
#include "ui_authForm.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db.load();
    m_users = db.getUsers();

    User admin;
    QString surname = "Халаманов";
    QString name = "Алексей";
    QString patr = "Павлович";
    QString depart = "Администрация";
    QString password = "12345678";

    admin.setSurname(surname);
    admin.setName(name);
    admin.setPatronymic(patr);
    admin.setDepartment(depart);
    admin.setPassword(password);
    m_users->push_back(admin);

    authorization();

    auto updateTimer = new QTimer;
    connect(updateTimer, SIGNAL(timeout()), this, SLOT(exit()));
    updateTimer->start();
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
        for (size_t i = 0; i < m_users->size(); i++)
        {
            if ((m_users->at(i).getSurname() == login) && (m_users->at(i).getPassword() == password))
            {
                m_auth_user = m_users->at(i);
                auth_succeful = true;
                break;
            }
        }
    }
    if (auth_succeful)
    {
        open_mainwindow();
    }
    else if (try_auth)
    {
        QMessageBox::information(0, "BudgetControl", "Неверно введены фамилия и/или пароль.\nПопробуйте еще раз.");
        authorization();
    }
}

void MainWindow::open_mainwindow()
{
    QMessageBox::information(0, "BudgetControl", QString("Вы успешно авторизированы, %1 %2 %3.")
                             .arg(m_auth_user.getSurname()).arg(m_auth_user.getName()).arg(m_auth_user.getPatronymic()));
    m_departments = db.getDepartments();
    if (m_auth_user.getDepartment() == "Администрация")
    {
        AdminMainWindow *admMW = new AdminMainWindow;
        admMW->setDataBase(db);
        admMW->setUser(m_auth_user);
        admMW->show();
    }
    else if (m_auth_user.getDepartment() == "Бухгалтерия")
    {
        AccountantMainWindow *accMW = new AccountantMainWindow;
        accMW->setDataBase(db);
        accMW->setUser(m_auth_user);
        accMW->show();
    }
    else
    {
        EmployeeMainWindow *empMW = new EmployeeMainWindow;
        empMW->setDataBase(db);
        empMW->setUser(m_auth_user);
        empMW->setDepartment(m_auth_user.getDepartment());
        empMW->show();
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

