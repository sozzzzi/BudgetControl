#ifndef TABLE_STATEMENTS_HPP
#define TABLE_STATEMENTS_HPP

#include <QDialog>
#include <QStandardItemModel>

#include "department.hpp"

namespace Ui {
class Table_Statements;
}

class Table_Statements : public QDialog
{
    Q_OBJECT

public:
    explicit Table_Statements(QWidget *parent = nullptr);
    ~Table_Statements();
    void setStatements(std::vector<Statement>&);
    void setDepartments(std::vector<Department>&);
    void addColumns();
public slots:
    void updateTable(int);

private:
    Ui::Table_Statements *ui;
    QStandardItemModel *itemModel;
    std::vector<Statement> m_statements;
    std::vector<Department> m_departments;
};

#endif // TABLE_STATEMENTS_HPP
