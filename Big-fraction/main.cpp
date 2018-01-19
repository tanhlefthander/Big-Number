#include <iostream>
#include <string>
#include "BigFraction.h"
using namespace std;
int main(){
    BigFraction b("99","-36");
    BigFraction c("100","-50");
    cout<<b<<" "<<c<<endl;
    cout<<b + c<<endl;
    cout<<b - c<<endl;
    cout<<b * c<<endl;
    cout<<b / c<<endl;
    cout<<(b ^ c)<<endl;
    b.getMixedNumber();
    cout<<getFromDouble("5.125")<<endl;
    return 0;
}
