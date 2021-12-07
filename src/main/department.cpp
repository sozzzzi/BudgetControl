#include "department.hpp"

Department::Department()
{

}

void Department::setName(QString m_name_)
{
    m_name = m_name_;
}

QString &Department::getName()
{
    return m_name;
}

void Department::addUser(User m_user_)
{
    m_users.push_back(m_user_);
}

void Department::addExpense(Expenses m_expenses_)
{
    m_expenses.push_back(m_expenses_);
}

std::vector<Expenses>* Department::getExpenses()
{
    return &m_expenses;
}

std::vector<Expenses> Department::getExpense()
{
    return m_expenses;
}

std::vector<User> Department::getUsers()
{
    return m_users;
}

