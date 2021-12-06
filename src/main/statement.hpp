#ifndef STATEMENT_HPP
#define STATEMENT_HPP
#include <QString>
#include <QDate>

class Statement
{
public:
    Statement();
    void setEmployee(QString);
    QString &getEmployee();
    void setDepartment(QString);
    QString &getDepartment();
    void setExpenses(QString);
    QString &getExpenses();
    void setDate(QDate);
    QDate &getDate();
    void setCost(size_t);
    size_t &getCost();

    void save(QDataStream &ost) const;
    void load(QDataStream &ist);
private:
    QString m_employee;
    QString m_department;
    QString m_expenses;
    QDate m_date;
    size_t m_cost;
};

#endif // STATEMENT_HPP
