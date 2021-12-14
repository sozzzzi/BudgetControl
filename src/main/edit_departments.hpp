#ifndef EDIT_DEPARTMENTS_HPP
#define EDIT_DEPARTMENTS_HPP

#include <QDialog>
#include "department.hpp"

namespace Ui {
class Edit_Departments;
}

class Edit_Departments : public QDialog
{
    Q_OBJECT

public:
    explicit Edit_Departments(QWidget *parent = nullptr);
    ~Edit_Departments();
    void setDepartments(std::vector<Department>*);

public slots:
    void changeDepartments(int);
    void addUser();
    void editUser();
    void delUser();

private:
    Ui::Edit_Departments *ui;
    std::vector<Department> *m_departments;
    std::vector<User>* m_users;
};

#endif // EDIT_DEPARTMENTS_HPP
