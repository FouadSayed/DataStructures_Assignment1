#include <iostream>
#include "BigInt.h"
#include <string>
#include <vector>
#include "bits/stdc++.h"
using namespace std;

int main() {
    cout<<"-->first test case"<<endl;
    BigInt num1("123456789012345678901234567890");
    BigInt num2("113456789011345678901134567890");
    BigInt res1;
    res1=num1+num2;
    cout<<"num1="<<num1<<" , "<<"num2="<<num2<<endl;
    cout<<"num1+num2= "<<res1<<endl<<endl;

    cout<<"-->second test case"<<endl;
    BigInt num3("-1230000000000000001");
    BigInt num4("30000000000000001");
    BigInt res2;
    res2=num3+num4;
    cout<<"num1="<<num3<<" , "<<"num2="<<num4<<endl;
    cout<<"num1+num2= "<<res2<<endl<<endl;

    cout<<"-->third test case"<<endl;
    BigInt num5("100000000005486521454");
    BigInt num6("-9999999999999");
    BigInt res3;
    res3=num5+num6;
    cout<<"num1="<<num5<<" , "<<"num2="<<num6<<endl;
    cout<<"num1+num2= "<<res3<<endl<<endl;

    cout<<"-->forth test case"<<endl;
    BigInt num7("-12345678901234567890123456780");
    BigInt num8("12345678901234567890123456780");
    BigInt res4;
    res4=num7+num8;
    cout<<"num1="<<num7<<" , "<<"num2="<<num8<<endl;
    cout<<"num1+num2= "<<res4<<endl<<endl;

    cout<<"-->fifth test case"<<endl;
    BigInt num9("-987654321654789753159");
    BigInt num10("-987654321654789753159");
    BigInt res5;
    res5=num9+num10;
    cout<<"num1="<<num9<<" , "<<"num2="<<num10<<endl;
    cout<<"num1+num2= "<<res5<<endl<<endl;
}