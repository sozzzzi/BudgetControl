#ifndef TABLE_STATEMENTS_HPP
#define TABLE_STATEMENTS_HPP

#include <QDialog>
#include <QStandardItemModel>

#include "department.hpp"

namespace Ui {
class table_statements;
}

class table_statements : public QDialog
{
    Q_OBJECT

public:
    explicit table_statements(QWidget *parent = nullptr);
    ~table_statements();
    void setStatements(std::vector<Statement>&);
    void setDepartments(std::vector<Department>&);
    void addColumns();
public slots:
    void updateTable(int);

private:
    Ui::table_statements *ui;
    QStandardItemModel *itemModel;
    std::vector<Statement> m_statements;
    std::vector<Department> m_departments;
};

#endif // TABLE_STATEMENTS_HPP
