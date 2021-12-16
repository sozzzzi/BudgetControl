#include "edit_expanses.hpp"
#include "edit_expense.hpp"
#include "ui_edit_expanses.h"

#include <QMessageBox>

Edit_Expanses::Edit_Expanses(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Edit_Expanses)
{
    ui->setupUi(this);
    addColumns();
}

void Edit_Expanses::addColumns()
{
    itemModel = new QStandardItemModel(this);
    itemModel->setColumnCount(3);
    itemModel->setHorizontalHeaderLabels(QStringList() << "Название" << "Предел" << "Остаток");
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->setModel(itemModel);
}

void Edit_Expanses::updateTable(int index)
{
    addColumns();

    if (index == 0)
    {
        ui->addButton->setEnabled(false);
        ui->delButton->setEnabled(false);
        ui->editButton->setEnabled(false);
        return;
    }

    ui->addButton->setEnabled(true);
    ui->delButton->setEnabled(true);
    ui->editButton->setEnabled(true);

    m_expenses = m_departments->at(index-1).getExpenses();
    for (size_t i = 0; i < m_expenses->size(); i++)
    {
        QList<QStandardItem *> standardItemsList;
        standardItemsList.append(new QStandardItem(m_expenses->at(i).getName()));
        standardItemsList.append(new QStandardItem(QString("%1").arg(m_expenses->at(i).getLimit())));
        standardItemsList.append(new QStandardItem(QString("%1").arg(m_expenses->at(i).getRemainder())));
        itemModel->insertRow(itemModel->rowCount(), standardItemsList);
    }
}

Edit_Expanses::~Edit_Expanses()
{
    delete ui;
}

void Edit_Expanses::setDepartment(std::vector<Department>* m_departments_)
{
    m_departments = m_departments_;

    for (size_t i = 0; i < m_departments->size(); i++)
    {
        QString name = m_departments->at(i).getName();
        if (name != "Администрация" && name != "Бухгалтерия")
            ui->comboBox->addItem(m_departments->at(i).getName());
    }
}

void Edit_Expanses::addExpense()
{
    Edit_Expense ed_ex;
    Expenses ex;
    ex.setRemainder(0);
    ex.setLimit(0);
    ed_ex.setExpense(&ex);
    if (ed_ex.exec() != Edit_Expense::Accepted)
        return;
    ex.setRemainder(ex.getLimit());
    ex.setDepartment(m_departments->at(ui->comboBox->currentIndex() - 1).getName());
    m_departments->at(ui->comboBox->currentIndex() - 1).addExpense(ex);

    updateTable(ui->comboBox->currentIndex());
}

void Edit_Expanses::editExpense()
{
    if (!ui->tableView->selectionModel()->hasSelection())
    {
        QMessageBox::information(0, "BudgetControl", "Расход не выбран.");
        return;
    }

    QModelIndexList selection = ui->tableView->selectionModel()->selectedRows();
    QModelIndex index = selection.at(0);
    int i = index.row();

    Edit_Expense ed_ex;
    ed_ex.setExpense(&m_expenses->at(i));
    if (ed_ex.exec() != Edit_Expense::Accepted)
        return;
    m_expenses->at(i).setDepartment(m_departments->at(ui->comboBox->currentIndex() - 1).getName());
    updateTable(ui->comboBox->currentIndex());
}

void Edit_Expanses::deleteExpense()
{
    if (!ui->tableView->selectionModel()->hasSelection())
    {
        QMessageBox::information(0, "BudgetControl", "Расход не выбран.");
        return;
    }

    QModelIndexList selection = ui->tableView->selectionModel()->selectedRows();
    QModelIndex index = selection.at(0);
    int i = index.row();

    m_expenses->erase(m_expenses->begin() + i);

    updateTable(ui->comboBox->currentIndex());
}


