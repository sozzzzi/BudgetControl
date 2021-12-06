#ifndef EMPLOYEEMAINWINDOW_HPP
#define EMPLOYEEMAINWINDOW_HPP

#include "department.hpp"

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
    void setDepartment(Department);
    void setUser(User);

private:
    Ui::EmployeeMainWindow *ui;
    Department m_department;
    User m_user;
};

#endif // EMPLOYEEMAINWINDOW_HPP
