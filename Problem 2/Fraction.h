#ifndef UNTITLED_FRACTION_H
#define UNTITLED_FRACTION_H
#include <iostream>
using namespace std;
class Fraction {
private:
    int  num , den;
public:
    Fraction operator + (Fraction f2);
    Fraction operator - (Fraction f2);
    Fraction operator * (Fraction f2);
    Fraction operator / (Fraction f2);
    bool operator < (Fraction f2);
    bool operator > (Fraction f2);
    bool operator == (Fraction f2);
    bool operator <= (Fraction f2);
    bool operator >= (Fraction f2);
    friend istream& operator >> (istream& ip , Fraction& f1);
    friend ostream& operator << (ostream& op , Fraction& f1);
    Fraction redcution(Fraction f1);
    void operator = (Fraction f2);
};


#endif //UNTITLED_FRACTION_H
