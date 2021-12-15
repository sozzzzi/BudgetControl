#include "edit_department.hpp"
#include "ui_edit_department.h"

#include <QLineEdit>
#include <QLabel>

Edit_Department::Edit_Department(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Edit_Department)
{
    ui->setupUi(this);
}

Edit_Department::~Edit_Department()
{
    delete ui;
}

void Edit_Department::setDepartments(std::vector<Department> *m_departments_)
{
    m_departments = m_departments_;

    QStringList list_departments;
    for (size_t i = 0; i < m_departments->size(); i++)
    {
        list_departments << m_departments->at(i).getName();
    }
    ui->listWidget->addItems(list_departments);
}

void Edit_Department::addDepartment()
{
    QDialog *dialog = new QDialog();
    QGridLayout *gridLayout = new QGridLayout(dialog);
    dialog->setLayout(gridLayout);
    QLabel* label = new QLabel("Введите название нового отдела.");
    QLineEdit* nameEdit = new QLineEdit();
    QDialogButtonBox* btnBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    connect(btnBox, &QDialogButtonBox::accepted, dialog, &QDialog::accept);
    connect(btnBox, &QDialogButtonBox::rejected, dialog, &QDialog::reject);
    gridLayout->addWidget(label);
    gridLayout->addWidget(nameEdit);
    gridLayout->addWidget(btnBox);
    if (dialog->exec() != QDialog::Accepted)
    {
        return;
    }
    Department m_department;
    m_department.setName(nameEdit->text());
    m_departments->push_back(m_department);
}

void Edit_Department::delDepartment()
{
    QModelIndexList selection = ui->listWidget->selectionModel()->selectedRows();
    QModelIndex index = selection.at(0);
    size_t ind = index.row();

    m_departments->erase(m_departments->begin() + ind);
}

