#include "tipcalculatorobject.h"
#include <QDebug>
TipCalculatorObject::TipCalculatorObject(QObject *parent)
    : QObject{parent}
{

}

double TipCalculatorObject::getBillAmount() const
{
    return m_billAmount;
}

void TipCalculatorObject::setBillAmount(double newBillAmount)
{
    if (qFuzzyCompare(m_billAmount, newBillAmount))
        return;
    m_billAmount = newBillAmount;
    emit billAmountChanged();
}

double TipCalculatorObject::getTipAmount() const
{
    return m_tipAmount;
}

void TipCalculatorObject::setTipAmount(double newTipAmount)
{
    if (qFuzzyCompare(m_tipAmount, newTipAmount))
        return;
    m_tipAmount = newTipAmount;
    emit tipAmountChanged();
}

double TipCalculatorObject::getTipRate() const
{
    return m_tipRate;
}

void TipCalculatorObject::setTipRate(double newTipRate)
{
    qDebug() << newTipRate;
    if (qFuzzyCompare(m_tipRate, newTipRate))
        return;
    m_tipRate = newTipRate;
    emit tipRateChanged();
}

int TipCalculatorObject::getNumberOfPeople() const
{
    return m_numberOfPeople;
}

void TipCalculatorObject::setNumberOfPeople(int newNumberOfPeople)
{
    if (m_numberOfPeople == newNumberOfPeople)
        return;
    m_numberOfPeople = newNumberOfPeople;
    emit numberOfPeopleChanged();
}

double TipCalculatorObject::getTotalAmount() const
{
    return m_totalAmount;
}

void TipCalculatorObject::setTotalAmount(double newTotalAmount)
{
    if (qFuzzyCompare(m_totalAmount, newTotalAmount))
        return;
    m_totalAmount = newTotalAmount;
    emit totalAmountChanged();
}

void TipCalculatorObject::calculateTotal()
{
    m_tipAmount = (m_billAmount * (m_tipRate * 0.01)) / m_numberOfPeople;

    emit tipAmountChanged();
    m_totalAmount = (m_billAmount + m_tipAmount) / m_numberOfPeople;
    emit totalAmountChanged();
}

void TipCalculatorObject::resetValues()
{
    m_billAmount = {0};
    m_tipAmount = {0};
    m_tipRate = {15};
    m_numberOfPeople = {1};
    m_totalAmount = {0};

    emit billAmountChanged();
    emit tipAmountChanged();
    emit tipRateChanged();
    emit numberOfPeopleChanged();
    emit totalAmountChanged();
}
