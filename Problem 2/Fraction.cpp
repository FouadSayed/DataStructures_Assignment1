#include <iostream>
#include "Fraction.h"
#include <cmath>
using namespace std;
Fraction Fraction ::operator+(Fraction f2) {
    Fraction f3;
    f3.num = (num * f2.den)+(den * f2.num);
    f3.den = den * f2.den;
    return f3;
}

Fraction Fraction::operator-(Fraction f2) {
    Fraction f3;
    f3.num=(num * f2.den )-(den * f2.num );
    f3.den=den*f2.den;
    return f3;
}

Fraction Fraction::operator*(Fraction f2) {
    Fraction f3;
    f3.num=num * f2.num;
    f3.den=den * f2.den;
    return f3;
}

Fraction Fraction::operator/(Fraction f2) {
    Fraction f3;
    f3.num= num * f2.den;
    f3.den= den * f2.num;
    return f3;
}

bool Fraction::operator<(Fraction f2) {
    if((float)num/den < (float)f2.num/f2.den)
        return true;
    else
        return false;
}

bool Fraction::operator>(Fraction f2) {
    if((float)num/den > (float)f2.num/f2.den)
        return true;
    else
        return false;
}

bool Fraction::operator==(Fraction f2) {
    if((float)num/den == (float)f2.num/f2.den)
        return true;
    else
        return false;
}

bool Fraction::operator<=(Fraction f2) {
    if((float)num/den <= (float)f2.num/f2.den)
        return true;
    else
        return false;
}

bool Fraction::operator>=(Fraction f2) {
    if((float)num/den >= (float)f2.num/f2.den)
        return true;
    else
        return false;
}

istream& operator >>(istream& ip , Fraction& f1){
    cout<<"enter the numerator and the denominator seprated by space:";
    ip>>f1.num;
    ip>>f1.den;
}

ostream& operator << (ostream& op , Fraction& f1){
    op<<f1.num<<"/"<<f1.den;
}

Fraction Fraction::redcution(Fraction f1) {
    int x=min(abs(f1.num),abs(f1.den));
    for (int i = 1; i <= x; ++i) {
        if(abs(f1.num)%i==0 && abs(f1.den)%i==0){
            f1.num=f1.num/i;
            f1.den=f1.den/i;
            i=1;
        }
    }
    return f1;
}

void Fraction::operator=(Fraction f2) {
    num=f2.num;
    den=f2.den;
}