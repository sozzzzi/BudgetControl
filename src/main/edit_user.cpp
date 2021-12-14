#include <QMessageBox>
#include "edit_user.hpp"
#include "ui_edit_user.h"

Edit_User::Edit_User(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Edit_User)
{
    ui->setupUi(this);
}

Edit_User::~Edit_User()
{
    delete ui;
}

void Edit_User::setDepartments(std::vector<Department> *m_departments_)
{
    m_departments = m_departments_;

    for (size_t i = 0; i < m_departments->size(); i++)
    {
        ui->departBox->addItem(m_departments->at(i).getName());
        if (m_user->getDepartment() != "" && m_user->getDepartment() == m_departments->at(i).getName()
                && m_user->getDepartment() != "Бухгалтерия")
        {
            ui->departBox->setCurrentIndex(i+1);
        }
    }
}

void Edit_User::setUser(User* m_user_)
{
    m_user = m_user_;

    if (m_user)
    {
        ui->surnameEdit->setText(m_user->getSurname());
        ui->nameEdit->setText(m_user->getName());
        ui->patrEdit->setText(m_user->getPatronymic());
        ui->passEdit->setText(m_user->getPassword());
    }
}

void Edit_User::accept()
{
    QString surname = ui->surnameEdit->text();
    QString name = ui->nameEdit->text();
    QString patr = ui->patrEdit->text();
    QString department = ui->departBox->currentText();
    QString password = ui->passEdit->text();

    if (surname.isEmpty())
    {
        QMessageBox::warning(0, "BudgerControl", "Поле фамилия пустое.");
        return;
    }
    if (name.isEmpty())
    {
        QMessageBox::warning(0, "BudgerControl", "Поле фамилия пустое.");
        return;
    }
    if (patr.isEmpty())
    {
        QMessageBox::warning(0, "BudgerControl", "Поле фамилия пустое.");
        return;
    }
    if (department.isEmpty())
    {
        QMessageBox::warning(0, "BudgerControl", "Поле фамилия пустое.");
        return;
    }
    if (password.isEmpty())
    {
        QMessageBox::warning(0, "BudgerControl", "Поле фамилия пустое.");
        return;
    }

    m_user->setSurname(surname);
    m_user->setName(name);
    m_user->setPatronymic(patr);
    m_user->setDepartment(department);
    m_user->setPassword(password);

    return QDialog::accept();
}
