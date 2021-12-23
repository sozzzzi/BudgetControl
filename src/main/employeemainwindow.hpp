#ifndef EMPLOYEEMAINWINDOW_HPP
#define EMPLOYEEMAINWINDOW_HPP

#include "database.hpp"

#include <QMainWindow>

namespace Ui {
class EmployeeMainWindow;
}

class EmployeeMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit EmployeeMainWindow(QWidget *parent = nullptr);
    ~EmployeeMainWindow();
    void setDepartment(QString);
    void setUser(User&);
    void setDataBase(DataBase&);

public slots:
    void apply();

private:
    Ui::EmployeeMainWindow *ui;
    Department *m_department;
    User m_user;
    DataBase db;
};

#endif // EMPLOYEEMAINWINDOW_HPP
