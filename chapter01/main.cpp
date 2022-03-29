#include <vector>
#include <Eigen/Core>

#include "functions.h"
#include "currency.h"


int main() {
    std::cout << "Hello, World!" << std::endl;
    double x = abc(2,3.1,3.5);
    std::cout<<"x= "<<x<<std::endl;

    Eigen::Matrix2f m1 = Eigen::Matrix2f::Identity();
    Eigen::Matrix2f m2;
    m2 << 1,1,1,1;
    Eigen::Matrix2f m3;
    m3 << 0,0,0,1;
    Eigen::Matrix2f m4;
    m4 = abc(m1,m2,m3);
    cout<<"m4=\n"<<m4<<endl;
    //exercise 1
    int x1= 1;
    int x2 = 2;
    swap(x1,x2);
    cout<<"x1= "<<x1<<" x2= "<<x2<<endl;
    //exercise 2
    int a[] = {1,2,3,4};
    cout<<"count= "<<count(begin(a),end(a))<<endl;
    //exercise 3
    int a1[4] = {};
    fill(a1,1,2,3);
    int c = 0;
    for (auto i:a1) {
        cout<<"a1["<<c<<"]="<<i<<endl;
        c++;
    }
    //exercise 4
    float a2[] = {1,2,3,4.1};
    float a3[] = {4,3,2,1.0};
    float sum = inner_product(a2,a3,4);
    cout<<"sum= "<<sum<<endl;
    //exercise 5
    iota(a,4,1);
    for (auto i : a)
        cout<<"a[i]+i= "<<i<<endl;
    //exercise 6
    if (is_sorted2(begin(a3), end(a3)))
        cout<<"is_sorted2: true."<<endl;
    else
        cout<<"is_sorted2: false."<<endl;
    //exercise 7
    cout<<"return smallest i = "<<mismatch2(a2,a3,4)<< endl;
    //exercise 11
    cout<<count(a,4,2)<<endl;
    //exercise 12
    int ** x3;
    float ** x4;
    double ** x5;
    int *rowSize = new int [4];
    for (int i = 0; i < 5; ++i)
        rowSize[i] = i+1;//different dimensions for every row
    make2dArray1(x3,2,3);
    make2dArray2(x4,4,5);
    make2dArray3(x5,4,rowSize);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < rowSize[i]; ++j) {
            x5[i][j] = i + j;
            //cout<<"x5["<<i<<"]"<<"["<<j<<"]= "<< x4[i][j] << endl;
        }
    }
    vector<double> vec;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < rowSize[i]; ++j) {
            vec.push_back(x5[i][j]);
            cout<<"x5["<<i<<"]["<<j<<"]= "<<x5[i][j]<<endl;///??
        }
    }
    cout<<"rowsize[1]= "<<rowSize[1]<<endl;
    cout<<"x5[0][2]="<<x5[0][2]<<endl;
    //delete2dArray3(x5,4);
    //exercise 13
    int * x6 = new int [5];
    cout<<"x6[5] = ";
    for (int i = 0; i < 5; ++i) {
        x6[i] = i;
        cout<<x6[i]<<" ";
    }
    changeLength1D(x6,5,3);
    cout<<"\nx6[3] = ";
    for (int i = 0; i < 3; ++i)
        cout<<x6[i]<<" ";

    //exercise 14
    cout<<endl;
    char ** c1;
    int l1 = 5;
    int l2 = 3;
    int *rowSize1 = new int [l1];
    int *rowSize2 = new int [l2];
    for (int i = 0; i < l1; ++i)
        rowSize1[i] = 10;
    for (int i = 0; i < l2; ++i)
        rowSize2[i] = 5;
    createSize2D(c1,l1,10);
    showSize2D(c1,l1,10);
    char ** c2;
    c2 = changeLength2d(c1,l1,rowSize1,l2,rowSize2);
    cout<<"After change the 2d array size: "<<endl;
    showSize2D(c2,l2,5);
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////currency
    currency g,h(plus_,3,50),i,j,k;
    g.setValue(minus_,2,25);
    i.setValue(-6.45);
    j = h.add(g);
    h.output();
    cout << " + ";
    g.output();
    cout<< " = ";
    j.output();
    cout<<endl;

    j = i.add(g).add(h);
    j.output();cout<<endl;
    j = i.increment(g).add(h);
    j.output();cout<<endl;
    cout<< "Attempting to initialize with cents = 152"<<endl;
    try {
        i.setValue(plus_,3,152);
    } catch (illegalParameterValue e) {
        cout<<"Caught thrown exception"<<endl;
        e.outputMessage();
    }
    k.input();
    k.output();

    return 0;
}
