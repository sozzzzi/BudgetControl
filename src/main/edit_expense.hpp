#ifndef EDIT_EXPENSE_HPP
#define EDIT_EXPENSE_HPP

#include <QDialog>
#include "expenses.hpp"

namespace Ui {
class Edit_Expense;
}

class Edit_Expense : public QDialog
{
    Q_OBJECT

public:
    explicit Edit_Expense(QWidget *parent = nullptr);
    ~Edit_Expense();
    void setExpense(Expenses*);

public slots:
    void accept();

private:
    Ui::Edit_Expense *ui;

    Expenses* m_expense;
};

#endif // EDIT_EXPENSE_HPP
