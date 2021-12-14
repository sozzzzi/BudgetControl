#include "edit_departments.hpp"
#include "edit_user.hpp"
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
        list_users << m_users->at(i).getName();
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
