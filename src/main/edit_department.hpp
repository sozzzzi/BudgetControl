#ifndef EDIT_DEPARTMENT_HPP
#define EDIT_DEPARTMENT_HPP

#include <QDialog>
#include "department.hpp"

namespace Ui {
class Edit_Department;
}

class Edit_Department : public QDialog
{
    Q_OBJECT

public:
    explicit Edit_Department(QWidget *parent = nullptr);
    ~Edit_Department();
    void setDepartments(std::vector<Department> *);
public slots:
    void addDepartment();
    void delDepartment();

private:
    Ui::Edit_Department *ui;
    std::vector<Department> *m_departments;
};

#endif // EDIT_DEPARTMENT_HPP
