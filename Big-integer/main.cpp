#include <iostream>
#include <string>
#include "BigInt.h"
using namespace std;
int main(){
    //cout<< BigInt("0") + BigInt("-2")<<endl;
    BigInt a("-10"), b("2");
    cout<<"a = "<<a<<" b = "<<b<<endl;
    cout<<"a + b = "<<(a+b)<<endl;
    cout<<"a - b = "<<(a-b)<<endl;
    cout<<"a * b = "<<(a*b)<<endl;
    cout<<"a / b = "<<(a/b)<<endl;
    cout<<"a % b = "<<(a%b)<<endl;
    cout<<"a ^ b = "<<(a^b)<<endl;
    a="3454";
    b=-234342;
    cout<<b.toString()<<endl;
    cout<<a+"344"<<endl;
    b[3]= '9';
    cout<<b<<endl;
    //b.random(2000);
    //cout<<b<<endl;

    return 0;
}
