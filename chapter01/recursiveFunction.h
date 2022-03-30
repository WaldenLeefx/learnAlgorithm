//
// Created by lee on 2022/3/30.
//

#ifndef CHAPTER01_RECURSIVEFUNCTION_H
#define CHAPTER01_RECURSIVEFUNCTION_H
#include <cmath>
#include <vector>
//1-19
int factorial (int n) {
    if (n <= 1) return 1;
    int fact = 2;
    for (int i  = 3; i <= n; i++)
        fact *= i;
    return fact;
}
//1-20
int fibonacci (int n) {
    if (n <= 1) return n;
    else return fibonacci(n-1) + fibonacci(n-2);
}
//1-21
int recFuc (int n) {
    if (n % 2) return recFuc(3 * n + 1);
    else return n / 2;
}
//1-22
int AckermannFuc (int i, int j) {
    if (i == 1 && j >= 1) return pow(2,j);
    if (j == 1 && i >= 2) return AckermannFuc(i-1,2);
    if (i >= 2 && j >= 2) return AckermannFuc(i-1, AckermannFuc(i,j-1));
}
//1-23
int gcd (int x, int y) {
    if (y == 0) return x;
    else return gcd(y, x % y);
}
//1-24
template<class T>
bool isBelong (const std::vector<T>& a, T x, int i) {
    int n = a.size();
    if (i >= n) return false;
    if (x == a[i]) return true;
    else return isBelong(a,x,i+1);
}
//1-25
template<class T>
void subSetGeneration(T *a, int *m,int n, int i) {
    if (n == i) {
        std::cout << "{";
        for (int j = 0; j < i; ++j)
            if (m[j] == 1) std::cout << a[j];
        std::cout << "}" << std::endl;
        return;
    }
    m[n] = 0;
    subSetGeneration(a,m,n+1,i);
    m[n] = 1;
    subSetGeneration(a,m,n+1,i);
}
//1-26
void greyCode(int *a,int n) {
}

#endif //CHAPTER01_RECURSIVEFUNCTION_H
