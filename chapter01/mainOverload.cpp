//
// Created by lee on 2022/3/30.
//

#include "currencyOverload.h"

using namespace std;

int main() {
    currencyOverload g,h(plus_,3,50),i,j;
    g.setValue(minus_,2,25);
    i.setValue(-6.45);

    j = h + g;
    cout << h << " + " << g << " = " << j << endl;

    j = i + g + h;
    cout << i << " + " << g << " + " << h << " = " << j <<endl;

    cout << "Increment " << i << " by " << g
         << " and then add " << h << endl;
    j = (i += g) + h;
    cout << "Result is " << j << endl;
    cout << "Increment object is " << i << endl;

    j = j * 10;
    cout << "Multiply Result is " << j << endl;
    j = j / -5;
    cout << "Divided Result is " << j << endl;
    j = j % 20;
    cout << "Percent Result is " << j << endl;

    cout << "Attempting to initialize with cents = 152" << endl;
    try {
        i.setValue(plus_,3,152);
    } catch (illegalParameterValue e) {
        cout << "Caught thrown exception" << endl;
        e.outputMessage();
    }

    return 0;
}