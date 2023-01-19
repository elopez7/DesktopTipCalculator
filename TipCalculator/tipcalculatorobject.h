#ifndef TIPCALCULATOROBJECT_H
#define TIPCALCULATOROBJECT_H

#include <QObject>

class TipCalculatorObject : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double billAmount READ getBillAmount WRITE setBillAmount NOTIFY billAmountChanged)
    Q_PROPERTY(double tipAmount READ getTipAmount WRITE setTipAmount NOTIFY tipAmountChanged)
    Q_PROPERTY(double tipRate READ getTipRate WRITE setTipRate NOTIFY tipRateChanged)
    Q_PROPERTY(int numberOfPeople READ getNumberOfPeople WRITE setNumberOfPeople NOTIFY numberOfPeopleChanged)
    Q_PROPERTY(double totalAmount READ getTotalAmount WRITE setTotalAmount NOTIFY totalAmountChanged)
public:
    explicit TipCalculatorObject(QObject *parent = nullptr);

    double getBillAmount() const;
    void setBillAmount(double newBillAmount);

    double getTipAmount() const;
    void setTipAmount(double newTipAmount);

    double getTipRate() const;
    void setTipRate(double newTipRate);

    int getNumberOfPeople() const;
    void setNumberOfPeople(int newNumberOfPeople);

    double getTotalAmount() const;
    void setTotalAmount(double newTotalAmount);

signals:

    void billAmountChanged();
    void tipAmountChanged();

    void tipRateChanged();

    void numberOfPeopleChanged();

    void totalAmountChanged();

public slots:
    void calculateTotal();
    void resetValues();

private:
    double m_billAmount{0};
    double m_tipAmount{0};
    double m_tipRate{15};
    int m_numberOfPeople{1};
    double m_totalAmount{0};
};

#endif // TIPCALCULATOROBJECT_H
