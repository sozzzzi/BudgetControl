#ifndef EDIT_USER_HPP
#define EDIT_USER_HPP

#include <QDialog>
#include "department.hpp"

namespace Ui {
class Edit_User;
}

class Edit_User : public QDialog
{
    Q_OBJECT

public:
    explicit Edit_User(QWidget *parent = nullptr);
    ~Edit_User();
    void setUser(User*);
    void setDepartments(std::vector<Department> *);

public slots:
    void accept();

private:
    Ui::Edit_User *ui;

    User* m_user;
    std::vector<Department> *m_departments;
};

#endif // EDIT_USER_HPP
