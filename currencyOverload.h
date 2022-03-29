//
// Created by lee on 2021/12/27.
//

#ifndef UNTITLED_CURRRENYOVERLOAD_H
#define UNTITLED_CURRRENYOVERLOAD_H
#include <iostream>
enum signType{plus_, minus_};

class currency
{
    friend std::ostream& operator<<(std::ostream&, const currency&);
public:
    currency(signType theSign = plus_, unsigned long theDollars = 0, unsigned int theCents = 0);

    ~currency() {};
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
    currency operator+(const currency&) const;
    currency& operator+=(const currency& x) {
        amount += x.amount;
        return *this;
    }
    void output(std::ostream&) const;

private:
    long amount;
};

currency currency::operator+(const currency &x) const {
    currency result;
    result.amount = amount + x.amount;
    return result;
}

void currency::output(std::ostream &out) const {
    long theAmount = amount;
    if (theAmount < 0) {
        out << '-';
        theAmount = -theAmount;
    }
    long dollars = theAmount / 100;
    out << '$' << dollars << '.';
    int cents = theAmount - dollars * 100;
    if (cents < 10) out < '0';
    out << cents;
}

//overload <<
std::ostream& operator<<(std::ostream& out, const currency& x) {
    x.output(out);
    return out;
}

#endif //UNTITLED_CURRRENYOVERLOAD_H
