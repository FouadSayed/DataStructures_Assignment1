#ifndef UNTITLED_BIGINT_H
#define UNTITLED_BIGINT_H
#include <iostream>
#include <vector>
using namespace std;

class BigInt {
private:
    string num;
    vector <int> v_num;
public:
    BigInt();
    BigInt(string decStr);
    BigInt(int decInt);
    BigInt operator +(BigInt anotherDec);
    BigInt operator =(BigInt anotherDec);
    bool operator >(BigInt anotherDec);
    friend ostream& operator << (ostream& out, BigInt& b);
    int size();
};
#endif //UNTITLED_BIGINT_H
