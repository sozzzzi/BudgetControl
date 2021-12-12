#ifndef EDIT_EXPANSES_H
#define EDIT_EXPANSES_H

#include <QDialog>
#include <QStandardItemModel>

#include "department.hpp"

namespace Ui {
class Edit_Expanses;
}

class Edit_Expanses : public QDialog
{
    Q_OBJECT

public:
    explicit Edit_Expanses(QWidget *parent = nullptr);
    ~Edit_Expanses();
    void setDepartment(std::vector<Department>*);

public slots:
    void updateTable(int);
    void addExpense();
    void editExpense();
    void deleteExpense();

private:
    void addColumns();
    Ui::Edit_Expanses *ui;
    QStandardItemModel *itemModel;
    std::vector<Department>* m_departments;
    std::vector<Expenses>* m_expenses;
};

#endif // EDIT_EXPANSES_H
