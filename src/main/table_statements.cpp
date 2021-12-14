#include "table_statements.hpp"
#include "ui_table_statements.h"

Table_Statements::Table_Statements(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Table_Statements)
{
    ui->setupUi(this);
    addColumns();
}

void Table_Statements::addColumns()
{
    itemModel = new QStandardItemModel(this);
    itemModel->setColumnCount(5);
    itemModel->setHorizontalHeaderLabels(QStringList() << "Отдел" << "Работник" << "Расход" << "Цена" << "Дата" );
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->setModel(itemModel);
}

void Table_Statements::updateTable(int index)
{
    addColumns();
    QString department = m_departments[index-1].getName();

    for (size_t i = 0; i < m_statements.size(); i++)
    {
        if (m_statements[i].getDepartment() == department)
        {
            QList<QStandardItem *> standardItemsList;
            standardItemsList.append(new QStandardItem(m_statements[i].getDepartment()));
            standardItemsList.append(new QStandardItem(m_statements[i].getEmployee()));
            standardItemsList.append(new QStandardItem(m_statements[i].getExpenses()));
            standardItemsList.append(new QStandardItem(QString("%1").arg(m_statements[i].getCost())));
            standardItemsList.append(new QStandardItem(m_statements[i].getDate().toString()));            
            itemModel->insertRow(itemModel->rowCount(), standardItemsList);
        }
    }
}

void Table_Statements::setStatements(std::vector<Statement>& m_statements_)
{
    m_statements = m_statements_;
}

void Table_Statements::setDepartments(std::vector<Department>& m_departments_)
{
    m_departments = m_departments_;

    for (size_t i = 0; i < m_departments.size(); i++)
    {
        ui->comboBox->addItem(m_departments[i].getName());
    }
}

Table_Statements::~Table_Statements()
{
    delete ui;
}
