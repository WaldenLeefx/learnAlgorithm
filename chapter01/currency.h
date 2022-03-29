//
// Created by lee on 2021/12/21.
//

#ifndef UNTITLED_CURRENCY_H
#define UNTITLED_CURRENCY_H

#include "illegalParameterValue.h"

enum signType{plus_, minus_};

//new currency
/*class currency
{
public:
    currency(signType theSign = plus_,
             unsigned long theDollars = 0,
             unsigned int theCents = 0);

    ~currency() {};
    void setValue(signType, unsigned long, unsigned int);
    void setValue(double);
    signType getSign() const
    {
        if (amount < 0) return minus_;
        else return plus_;
    }
    unsigned long getDollars() const
    {
        if (amount < 0) return (-amount) / 100;
        else return amount / 100;
    }
    unsigned int getCents() const
    {
        if (amount < 0) return -amount - getDollars() * 100;
        else return amount - getDollars() * 100;
    }
    currency add(const currency&) const;
    currency& increment(const currency& x)
    {
        amount += x.amount;
        return *this;
    }
    void output() const;

private:
    long amount;
};

currency::currency(signType theSign, unsigned long theDollars, unsigned int theCents) {
    setValue(theSign, theDollars, theCents);
}

void currency::setValue(signType theSign, unsigned long theDollars, unsigned int theCents) {
    if (theCents > 99)
        throw illegalParameterValue("Cents should be < 100");

    amount = theDollars * 100 + theCents;
    if (theSign == minus_) amount = -amount;
}

void currency::setValue(double theAmount) {
    if (theAmount < 0)
        amount = (long) ((theAmount - 0.001) * 100);
    else
        amount = (long) ((theAmount + 0.001) * 100);
}

currency currency::add(const currency &x) const {
    currency y;
    y.amount = amount + x.amount;
    return y;
}

void currency::output() const {
    long theAmount = amount;
    if (theAmount < 0) {
        std::cout<<'-';
        theAmount = -theAmount;
    }

    long dollars = theAmount / 100;
    std::cout<<'$'<<dollars<<".";
    int cents = theAmount - dollars * 100;
    if (cents < 10) std::cout<<'0';
    std::cout<<cents;
}*/


class currency
{
public:
    //构造函数
    currency(signType theSign = plus_,
             unsigned long theDollars = 0,
             unsigned int theCents = 0);
    //析构函数
    ~currency() {};
    void setValue(signType, unsigned long, unsigned int);
    void setValue(double);
    signType getSign() const {return sign;}
    unsigned long getDollars() const {return dollars;}
    unsigned int getCents() const {return cents;}
    currency add(const currency&) const;
    currency& increment(const currency&);
    void input();
    void output() const;

private:
    signType sign;
    unsigned long dollars;
    unsigned int cents;
    long amount;
};

currency::currency(signType theSign, unsigned long theDollars, unsigned int theCents) {
    setValue(theSign,theDollars, theCents);
}

void currency::setValue(signType theSign, unsigned long theDollars, unsigned int theCents) {
    if (theCents > 99)
        throw illegalParameterValue("Cents should be < 100");

    sign = theSign;
    dollars = theDollars;
    cents = theCents;
}

void currency::setValue(double theAmount) {
    if (theAmount < 0) {sign = minus_; theAmount = -theAmount;}
    else sign = plus_;
    dollars = (unsigned long) theAmount;
    cents = (unsigned int) ((theAmount + 0.01 - dollars) * 100);
}

currency currency::add(const currency &x) const {
    long a1, a2, a3;
    currency result;

    a1 = dollars * 100 + cents;
    if (sign == minus_) a1 = -a1;

    a2 = x.dollars * 100 + x.cents;
    if (x.sign == minus_) a2 = -a2;

    a3 = a2 + a1;

    if (a3 < 0) {result.sign = minus_; a3 = -a3;}
    else result.sign = plus_;
    result.dollars = a3 / 100;
    result.cents = a3 - result.dollars * 100;

    return result;
}

currency& currency::increment(const currency &x) {
    *this = add(x);
    return *this;
}

void currency::input() {
    std::cout<<"Please enter the type of sign dollars and cents:"<<std::endl;
    signType theSign;
    unsigned long theDollars;
    unsigned int theCents;
    char temp;
    double tempMoney;
    std::scanf("%c%lf",&temp,&tempMoney);
    if (temp == '-')
        theSign = minus_;
    else
        theSign = plus_;
    //枚举类型不能使用cin

    theDollars = tempMoney;
    theCents = tempMoney * 100 - theDollars * 100;
    setValue(theSign,theDollars,theCents);
}

void currency::output() const {
    if (sign == minus_) std::cout << '-';
    std::cout << '$' << dollars << '.';
    if (cents < 10) std::cout << '0';
    std::cout << cents;
}
#endif //UNTITLED_CURRENCY_H
