#ifndef DEPARTMENT_HPP
#define DEPARTMENT_HPP
#include "user.hpp"
#include "expenses.hpp"
#include "statement.hpp"

class Department
{
public:
    Department();
    void setName(QString);
    QString &getName();
    void addUser(User);
    void addExpense(Expenses);
    void addStatement(Statement);
    std::vector<Expenses>* getExpenses();
    std::vector<Expenses> getExpense();
    std::vector<User> &getUsers();
    Expenses searchExpense(QString);

private:
    QString m_name;
    std::vector<User> m_users;
    std::vector<Expenses> m_expenses;
    std::vector<Statement> m_statements;
};

#endif // DEPARTMENT_HPP
