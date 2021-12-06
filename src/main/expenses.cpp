#include "expenses.hpp"

Expenses::Expenses()
{

}

void Expenses::setName(QString m_name_)
{
    m_name = m_name_;
}

QString &Expenses::getName()
{
    return m_name;
}

void Expenses::setDescription(QString m_description_)
{
    m_description = m_description_;
}

QString &Expenses::getDescription()
{
    return m_description;
}

void Expenses::setDepartment(QString m_department_)
{
    m_department = m_department_;
}

QString &Expenses::getDepartment()
{
    return m_department;
}

void Expenses::setLimit(size_t m_limit_)
{
    m_limit = m_limit_;
}

size_t &Expenses::getLimit()
{
    return m_limit;
}

void Expenses::setRemainder(size_t m_remainder_)
{
    m_remainder = m_remainder_;
}

size_t &Expenses::getRemainder()
{
    return m_remainder;
}

void Expenses::save(QDataStream &ost) const
{
    ost << m_name << m_description << m_department << QString("%1").arg(m_remainder) << QString("%1").arg(m_limit);
}

void Expenses::load(QDataStream &ist)
{
    QString tmp1;
    QString tmp2;
    ist >> m_name >> m_description >> m_department >> tmp1 >> tmp2;
    m_remainder = tmp1.toUInt();
    m_limit = tmp2.toUInt();
}
