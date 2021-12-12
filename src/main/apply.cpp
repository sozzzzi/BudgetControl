#include <QValidator>
#include <QMessageBox>
#include "apply.hpp"
#include "ui_apply.h"

Apply::Apply(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Apply)
{
    ui->setupUi(this);
    ui->costEdit->setValidator(new QIntValidator);
}

Apply::~Apply()
{
    delete ui;
}

void Apply::setStatement(Statement* m_statement_)
{
    m_statement = m_statement_;
}

void Apply::setExpenses(std::vector<Expenses>* m_expenses_)
{
    m_expenses = m_expenses_;

    for (size_t i = 0; i < m_expenses->size(); i++)
    {
        ui->comboBox->addItem(m_expenses->at(i).getName());
    }
}

void Apply::accept()
{
    size_t index = ui->comboBox->currentIndex();
    size_t cost = ui->costEdit->text().toULong();

    size_t m_limit = m_expenses->at(index-1).getLimit();
    size_t m_remainder = m_expenses->at(index-1).getRemainder();

    if (cost < 0)
    {
        QMessageBox::warning(0, "BudgerControl", "Цена заявки не может быть меньше или равна нулю.");
        return;
    }
    else if (cost > m_limit)
    {
        QMessageBox::warning(0, "BudgerControl", "Цена заявки не может привышать предел.");
        return;
    }
    else if (cost > m_remainder)
    {
        QMessageBox::warning(0, "BudgerControl", "Цена заявки больше, чем остаток.");
        return;
    }
    m_expenses->at(index-1).setRemainder(m_remainder - cost);
    m_statement->setCost(cost);
    m_statement->setExpenses(ui->comboBox->currentData().toString());

    return QDialog::accept();
}


void Apply::on_comboBox_currentIndexChanged(int index)
{
    ui->costEdit->setText("0");
}

