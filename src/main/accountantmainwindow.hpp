#ifndef ACCOUNTANTMAINWINDOW_HPP
#define ACCOUNTANTMAINWINDOW_HPP
#include "database.hpp"

#include <QMainWindow>

namespace Ui {
class AccountantMainWindow;
}

class AccountantMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AccountantMainWindow(QWidget *parent = nullptr);
    ~AccountantMainWindow();
    void setUser(User);
    void setDataBase(DataBase&);

public slots:
    void openEditExpenses();
    void openTableStatements();

private:
    Ui::AccountantMainWindow *ui;

    DataBase db;
    std::vector<Expenses> *m_expenses;
    std::vector<Statement> *m_statement;
    std::vector<Department> *m_departments;
    User m_user;
};

#endif // ACCOUNTANTMAINWINDOW_HPP
