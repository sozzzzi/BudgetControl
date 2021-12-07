#include "edit_expense.hpp"
#include "ui_edit_expense.h"
#include <QMessageBox>

Edit_Expense::Edit_Expense(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Edit_Expense)
{
    ui->setupUi(this);
}

Edit_Expense::~Edit_Expense()
{
    delete ui;
}

void Edit_Expense::setExpense(Expenses* m_expense_)
{
    m_expense = m_expense_;

    if (m_expense)
    {
        ui->nameEdit->setText(m_expense->getName());
        ui->descriptionEdit->setText(m_expense->getDescription());
        ui->limitEdit->setText(QString("%1").arg(m_expense->getLimit()));
    }
}

void Edit_Expense::accept()
{
    QString name = ui->nameEdit->text();
    QString description = ui->descriptionEdit->text();
    size_t limit = ui->limitEdit->text().toUInt();

    if (name.size() == 0)
    {
        QMessageBox::information(0, "BudgetControl", "Поле название пустое.");
        return;
    }

    if (description.size() == 0)
    {
        QMessageBox::information(0, "BudgetControl", "Поле описание пустое.");
        return;
    }

    if (limit <= 0)
    {
        QMessageBox::information(0, "BudgetControl", "Предел меньше или равен 0.");
        return;
    }
    else if (m_expense->getRemainder() > limit)
    {
        QMessageBox::information(0, "BudgetControl", "Остаток больше предела.");
        return;
    }

    m_expense->setName(name);
    m_expense->setDescription(description);
    m_expense->setLimit(limit);

    return QDialog::accept();
}
