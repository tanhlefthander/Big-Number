#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "BigInt.h"
#include "AlgorithmBigInt.h"
using namespace std;

class BigMixedNumbers {
private:
    struct BigFraction { // phân sô lớn - dương
        string numerator; // tử số
        string denominator; // mẫu số
        bool isZero(){
            if(numerator == "0") return true;
            return false;
        }
    };
private:
    BigInt bigInt; // phần nguyên
    BigFraction bigFrac; // phần phân số
    void fix(){ // làm chuẩn
        QR qr= divide(bigFrac.numerator, bigFrac.denominator);
        if(bigInt.isMinus()) bigInt= bigInt- qr.first; // do (a+ b/c)
        else bigInt= bigInt+ qr.first;
        bigFrac.numerator= qr.second;
    }
public:
    BigMixedNumbers(){
        bigInt="0";
    };
    BigMixedNumbers(string a){
        bigInt= a;
    }
    BigMixedNumbers(string a, string b, string c){
        bigInt= a;
        bigFrac= BigFraction(b,c);
        fix();
    }
    // xuất
    friend ostream & operator << (ostream & out, BigMixedNumbers b) {
        if(b != BigInt())out<<b.bigInt;
        if(!b.bigFrac.isZero())
            out<<'('<<b.numerator<<'/'<<b.denominator<<')';
        return out;
    }
};
