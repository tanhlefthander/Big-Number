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
        void printf(){
            cout<<numerator;
            if(denominator != "1") cout<<'/'<<denominator;
        }
        void init(string a, string b){
            numerator= a;
            denominator= b;
        }
        BigFraction operator + (BigFraction b){
            BigFraction res;
            res.numerator = add( mul(numerator,b.denominator) , mul(b.numerator,denominator) );
            res.denominator = mul(b.denominator , denominator);
            return res;
        }
        BigFraction operator - (BigFraction b){
            BigFraction res;
            res.numerator = sub( mul(numerator,b.denominator) , mul(b.numerator,denominator) );
            res.denominator = mul(b.denominator , denominator);
            return res;
        }
        BigFraction operator * (BigFraction b){
            BigFraction res;
            res.numerator = mul(numerator, b.numerator);
            res.denominator = mul(b.denominator , denominator);
            return res;
        }
        BigFraction operator / (BigFraction b){
            BigFraction res;
            res.numerator = mul(numerator, b.denominator);
            res.denominator = mul(b.numerator , denominator);
            return res;
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
    BigFraction toFraction(){
        //return
    }
public:
    BigMixedNumbers(){
        bigInt="0";
    };
    BigMixedNumbers(string a){
        bigInt= a;
    }
    BigMixedNumbers(string a, string b){
        bigInt= BigInt();
        bigFrac.init(a,b);
        fix();
    }
    BigMixedNumbers(string a, string b, string c){
        bigInt= a;
        bigFrac.init(b,c);
        fix();
    }
     BigMixedNumbers operator + (BigMixedNumbers b){
         BigMixedNumbers res;
         res.bigInt = bigInt + b.bigInt;
         res.bigFrac = bigFrac + b.bigFrac;
         res.fix();
         return res;
     }
    // xuất
    friend ostream & operator << (ostream & out, BigMixedNumbers b) {
        if(b.bigInt != BigInt())out<<b.bigInt;
        if(!b.bigFrac.isZero()){
            out<<"/";
            b.bigFrac.printf();
        }
        return out;
    }

};
