#ifndef APPLY_HPP
#define APPLY_HPP

#include <QDialog>
#include "statement.hpp"
#include "expenses.hpp"

namespace Ui {
class Apply;
}

class Apply : public QDialog
{
    Q_OBJECT

public:
    explicit Apply(QWidget *parent = nullptr);
    ~Apply();
    void setStatement(Statement*);
    void setExpenses(std::vector<Expenses>*);

public slots:
    void accept();

private slots:
    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::Apply *ui;
    Statement *m_statement;
    std::vector<Expenses> *m_expenses;
};

#endif // APPLY_HPP
