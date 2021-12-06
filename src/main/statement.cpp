#include "statement.hpp"

Statement::Statement()
{

}

void Statement::setEmployee(QString m_employee_)
{
    m_employee = m_employee_;
}

QString &Statement::getEmployee()
{
    return m_employee;
}

void Statement::setDepartment(QString m_department_)
{
    m_department = m_department_;
}

QString &Statement::getDepartment()
{
    return m_department;
}

void Statement::setExpenses(QString m_expenses_)
{
    m_expenses = m_expenses_;
}

QString &Statement::getExpenses()
{
    return m_expenses;
}

void Statement::setDate(QDate m_date_)
{
    m_date = m_date_;
}

QDate &Statement::getDate()
{
    return m_date;
}

void Statement::setCost(size_t m_cost_)
{
    m_cost = m_cost_;
}

size_t &Statement::getCost()
{
    return m_cost;
}

void Statement::save(QDataStream &ost) const
{
    ost << m_employee << m_department << m_expenses << m_date << m_cost;
}

void Statement::load(QDataStream &ist)
{
    ist >> m_employee >> m_department >> m_expenses >> m_date >> m_cost;
}
