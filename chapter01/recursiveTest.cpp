//
// Created by lee on 2022/3/30.
//

#include <iostream>
#include "recursiveFunction.h"

using namespace std;

int main() {
    cout<<"fibonacci(3) = "<<fibonacci(3)<<endl;
    cout<<"fibonacci(5) = "<<fibonacci(5)<<endl;
    cout<<"reFuc(3) = "<<recFuc(3)<<endl;
    cout<<"AckermannFuc(1,2) = "<<AckermannFuc(1,2)<<endl;
    cout<<"AckermannFuc(2,1) = "<<AckermannFuc(2,1)<<endl;
    cout<<"AckermannFuc(2,2) = "<<AckermannFuc(2,2)<<endl;
    cout<<"gcd(20,30) = "<<gcd(20,30)<<endl;
    cout<<"gcd(112,42) = "<<gcd(112,42)<<endl;
    int m[3];
    char a[3] = {'a','b','c'};
    subSetGeneration(a,m,0,3);
}
