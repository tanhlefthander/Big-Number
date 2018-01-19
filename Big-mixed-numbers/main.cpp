#include <iostream>
#include <string>
#include "BigMixedNumbers.h"
#include "BigFraction.h"
using namespace std;
int main(){
    BigMixedNumbers b("89","67");
    BigMixedNumbers c("100","67");
    cout<<b<<" "<<c<<endl;
    cout<<b + c<<endl;
    return 0;
}
