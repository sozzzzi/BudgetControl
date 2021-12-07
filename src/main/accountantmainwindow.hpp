#ifndef ACCOUNTANTMAINWINDOW_HPP
#define ACCOUNTANTMAINWINDOW_HPP
#include "edit_expanses.hpp"

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
    void setDepartment(std::vector<Department>);
    void setUser(User);

public slots:
    void openEditExpenses();

    void save_departments();
    void save_users();
    void save_expenses();

private:
    Ui::AccountantMainWindow *ui;

    std::vector<Department> m_departments;
    User m_user;
};

#endif // ACCOUNTANTMAINWINDOW_HPP
