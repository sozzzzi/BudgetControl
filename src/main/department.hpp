#ifndef DEPARTMENT_HPP
#define DEPARTMENT_HPP
#include "user.hpp"
#include "expenses.hpp"

class Department
{
public:
    Department();
    void setName(QString);
    QString &getName();
    void addUser(User);
    void addExpense(Expenses);

    QString m_name;
    std::vector<User> m_users;
    std::vector<Expenses> m_expenses;
};

#endif // DEPARTMENT_HPP