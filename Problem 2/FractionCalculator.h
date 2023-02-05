#ifndef UNTITLED_FRACTIONCALCULATOR_H
#define UNTITLED_FRACTIONCALCULATOR_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "Fraction.h"
class FractionCalculator : public Fraction {
private:
    string c;
    vector<Fraction>v;
public:
    FractionCalculator();
};


#endif //UNTITLED_FRACTIONCALCULATOR_H
