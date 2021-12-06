#ifndef EXPENSES_HPP
#define EXPENSES_HPP
#include <QString>

class Expenses
{
public:
    Expenses();
    void setName(QString);
    QString &getName();
    void setDescription(QString);
    QString &getDescription();
    void setDepartment(QString);
    QString &getDepartment();
    void setLimit(size_t);
    size_t &getLimit();
    void setRemainder(size_t);
    size_t &getRemainder();

    void save(QDataStream &ost) const;
    void load(QDataStream &ist);
private:
    QString m_name;
    QString m_description;
    QString m_department;
    size_t m_limit;
    size_t m_remainder;
};

inline QDataStream &operator<<(QDataStream &ost, const Expenses &e)
{
    e.save(ost);
    return ost;
}

inline QDataStream &operator>>(QDataStream &ist, Expenses &e)
{
    e.load(ist);
    return ist;
}

#endif // EXPENSES_HPP
