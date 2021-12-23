#ifndef ADMINMAINWINDOW_HPP
#define ADMINMAINWINDOW_HPP

#include <QMainWindow>
#include "database.hpp"

namespace Ui {
class AdminMainWindow;
}

class AdminMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminMainWindow(QWidget *parent = nullptr);
    ~AdminMainWindow();
    void setUser(User);
    void setDataBase(DataBase&);

public slots:
    void openEditDepartments();

    void exportUsers();
    void exportExpenses();
    void exportStatements();
    void importUsers();

private:
    Ui::AdminMainWindow *ui;

    DataBase db;
    User m_user;
    std::vector<User> *m_users;
    std::vector<Department> *m_departments;
};

#endif // ADMINMAINWINDOW_HPP
