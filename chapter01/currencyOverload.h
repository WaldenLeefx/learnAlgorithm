//
// Created by lee on 2021/12/27.
//

#ifndef UNTITLED_CURRRENYOVERLOAD_H
#define UNTITLED_CURRRENYOVERLOAD_H

#include "illegalParameterValue.h"

enum signType{plus_, minus_};

class currencyOverload
{
    friend std::istream& operator>>(std::istream&, currencyOverload&);
    friend std::ostream& operator<<(std::ostream&, const currencyOverload&);
public:
    currencyOverload(signType theSign = plus_, unsigned long theDollars = 0, unsigned int theCents = 0);

    ~currencyOverload() {};
    void setValue(signType, unsigned long , unsigned int );
    void setValue(double );
    signType getSign() const {
        if (amount < 0) return minus_;
        else return plus_;
    }
    unsigned long getDollars() const {
        if (amount < 0) return (-amount) / 100;
        else return amount / 100;
    }
    unsigned int getCents() const {
        if (amount < 0) return -amount - getDollars() * 100;
        else return amount - getDollars() * 100;
    }
    currencyOverload operator+(const currencyOverload&) const;
    currencyOverload operator-(const currencyOverload&) const;
    currencyOverload operator*(double) const;
    currencyOverload operator/(double) const;
    currencyOverload operator%(double) const;

    currencyOverload& operator+=(const currencyOverload& x) {
        amount += x.amount;
        return *this;
    }
    currencyOverload& operator-=(const currencyOverload& x) {
        amount -= x.amount;
        return *this;
    }
    void input(std::istream&);
    void output(std::ostream&) const;

private:
    long amount;
};

currencyOverload::currencyOverload(signType theSign, unsigned long theDollars, unsigned int theCents) {
    setValue(theSign,theDollars,theCents);
}

void currencyOverload::setValue(signType theSign, unsigned long theDollars, unsigned int theCents) {
    if (theCents > 99)
        throw illegalParameterValue("Cents should be < 100");

    amount = theDollars * 100 + theCents;
    if (theSign == minus_) amount = -amount;
}

void currencyOverload::setValue(double theAmount) {
    if (theAmount < 0)
        amount = (long) ((theAmount - 0.001) * 100);
    else
        amount = (long) ((theAmount + 0.001) * 100);
}

currencyOverload currencyOverload::operator+(const currencyOverload &x) const {
    currencyOverload result;
    result.amount = amount + x.amount;
    return result;
}

currencyOverload currencyOverload::operator-(const currencyOverload &x) const {
    currencyOverload result;
    result.amount = amount - x.amount;
    return result;
}

currencyOverload currencyOverload::operator*(double x) const {
    currencyOverload result;
    result.amount = (long) (amount * x);
    return result;
}

currencyOverload currencyOverload::operator/(double x) const {
    currencyOverload result;
    result.amount = (long) (amount / x);
    return result;
}

currencyOverload currencyOverload::operator%(double x) const {
    currencyOverload result;
    result.amount = (long) (amount * x / 100);
    return result;
}

void currencyOverload::input(std::istream& in) {
    std::cout<<"Please enter the type of sign dollars and cents:"<<std::endl;
    double theValue;
    in >> theValue;
    setValue(theValue);
}

void currencyOverload::output(std::ostream &out) const {
    long theAmount = amount;
    if (theAmount < 0) {
        out << '-';
        theAmount = -theAmount;
    }
    long dollars = theAmount / 100;
    out << '$' << dollars << '.';
    int cents = theAmount - dollars * 100;
    if (cents < 10) out << '0';
    out << cents;
}

//overload <<
std::istream& operator>>(std::istream& input, currencyOverload& x) {
    x.input(input);
    return input;
}
std::ostream& operator<<(std::ostream& out, const currencyOverload& x) {
    x.output(out);
    return out;
}

#endif //UNTITLED_CURRRENYOVERLOAD_H
