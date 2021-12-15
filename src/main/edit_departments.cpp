#include "edit_departments.hpp"
#include "edit_user.hpp"
#include "edit_department.hpp"
#include "ui_edit_departments.h"

Edit_Departments::Edit_Departments(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Edit_Departments)
{
    ui->setupUi(this);
}

Edit_Departments::~Edit_Departments()
{
    delete ui;
}

void Edit_Departments::setDepartments(std::vector<Department>* m_departments_)
{
    m_departments = m_departments_;

    changeDepartment();
}

void Edit_Departments::setAccountant(Department* m_department_)
{
    m_departments->push_back(*m_department_);

    changeDepartment();
}

void Edit_Departments::changeDepartment()
{
    size_t size = ui->comboBox->count();
    for (size_t i = 1; i < size; i++)
    {
        ui->comboBox->removeItem(1);
    }

    for (size_t i = 0; i < m_departments->size(); i++)
    {
        ui->comboBox->addItem(m_departments->at(i).getName());
    }
}

void Edit_Departments::changeDepartments(int index)
{
    ui->listWidget->clear();

    if (index == 0)
    {
        ui->addUserButton->setEnabled(false);
        ui->editUserButton->setEnabled(false);
        ui->delUserButton->setEnabled(false);
        return;
    }

    ui->addUserButton->setEnabled(true);
    ui->editUserButton->setEnabled(true);
    ui->delUserButton->setEnabled(true);

    m_users = &m_departments->at(index-1).getUsers();
    QStringList list_users;
    for (size_t i = 0; i < m_users->size(); i++)
    {
        list_users << QString("%1 %2 %3").arg(m_users->at(i).getSurname()).arg(m_users->at(i).getName()).arg(m_users->at(i).getPatronymic());
    }
    ui->listWidget->addItems(list_users);
}

void Edit_Departments::addUser()
{
    Edit_User au;
    User u;
    au.setUser(&u);
    au.setDepartments(m_departments);
    if (au.exec() != QDialog::Accepted)
        return;
    m_departments->at(ui->comboBox->currentIndex() - 1).addUser(u);
    changeDepartments(ui->comboBox->currentIndex());
}

void Edit_Departments::editUser()
{
    QModelIndexList selection = ui->listWidget->selectionModel()->selectedRows();
    QModelIndex index = selection.at(0);
    int i = index.row();

    Edit_User eu;
    eu.setUser(&m_users->at(i));
    eu.setDepartments(m_departments);
    if (eu.exec() != Edit_User::Accepted)
    {
        return;
    }
    changeDepartments(ui->comboBox->currentIndex());
}

void Edit_Departments::delUser()
{
    QModelIndexList selection = ui->listWidget->selectionModel()->selectedRows();
    QModelIndex index = selection.at(0);
    size_t ind = index.row();

    m_users->erase(m_users->begin() + ind);
    changeDepartments(ui->comboBox->currentIndex());
}

void Edit_Departments::editDepartments()
{
    Edit_Department ed;
    ed.setDepartments(m_departments);
    if (ed.exec() != Edit_Departments::Accepted)
        return;
    changeDepartment();
}
