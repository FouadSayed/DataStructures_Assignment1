#include <iostream>
#include "BigInt.h"
#include "bits/stdc++.h"
using namespace std;

BigInt::BigInt() {
}

BigInt::BigInt(string decStr) {
    num=decStr;
    bool n=false;
    if(num[0]-'0'==-3)
        n=true;
    if(n){
        for (int i = 1; i < num.size(); ++i) {
            if(num[i]=='0' || num[i]=='1' || num[i]=='2' || num[i]=='3' || num[i]=='4' || num[i]=='5' || num[i]=='6' || num[i]=='7' || num[i]=='8' || num[i]=='9') {
                if(i==1)
                    v_num.push_back((num[i]-'0')*-1);
                else
                    v_num.push_back(num[i]-'0');
            }
            else
                continue;
        }
    }
    else{
        for (int i = 0; i < num.size(); ++i) {
            if(num[i]=='0' || num[i]=='1' || num[i]=='2' || num[i]=='3' || num[i]=='4' || num[i]=='5' || num[i]=='6' || num[i]=='7' || num[i]=='8' || num[i]=='9') {
                v_num.push_back(num[i]-'0');
            }
            else
                continue;
        }
    }
}

BigInt::BigInt(int decInt) {
    while(decInt!=0){
        v_num.push_back(decInt%10);
        decInt/=10;
    }
    reverse(v_num.begin(),v_num.end());
}

bool BigInt::operator>(BigInt anotherDec) {
    bool test= false;
    if(v_num.size() > anotherDec.v_num.size())
        test=true;
    else if(v_num.size() < anotherDec.v_num.size())
        test=false;
    else if(v_num.size() == anotherDec.v_num.size()){
        if(v_num > anotherDec.v_num)
            test = true;
        else if(v_num < anotherDec.v_num)
            test=false;
    }
    return test;
}

BigInt BigInt::operator+(BigInt anotherDec) {
    BigInt b1,b2,b3;
    b1.v_num=v_num;
    b2.v_num=anotherDec.v_num;
    bool first_neg =false , sec_neg=false;
    if(b1.v_num[0]<0) {
        first_neg = true;
        b1.v_num[0] *= -1;
    }
    if(b2.v_num[0]<0) {
        sec_neg = true;
        b2.v_num[0] *= -1;
    }
    //x+n or (-x)+(-n)
    if((first_neg && sec_neg) || (!first_neg && !sec_neg)){
        if(b2.v_num.size() > b1.v_num.size()){
            BigInt tmp;
            tmp.v_num=b1.v_num;
            b1.v_num=b2.v_num;
            b2.v_num=tmp.v_num;
        }
        reverse(b1.v_num.begin(),b1.v_num.end());
        reverse(b2.v_num.begin(),b2.v_num.end());
        int size=b1.v_num.size();
        for (int i = 0; i <size  ; i++) {
            if(i > b2.v_num.size()-1){
                b3.v_num.push_back(b1.v_num[i]);
            }
            else{
                int x=b1.v_num[i]+b2.v_num[i];
                if(x<=9){
                    b3.v_num.push_back(x);
                }
                else if(x>9){
                    b3.v_num.push_back(x-10);
                    if(i==b1.v_num.size()-1)
                        b3.v_num.push_back(1);
                    else{
                        b1.v_num[i+1]+=1;
                    }
                }
            }
        }
        if(first_neg && sec_neg)
            b3.v_num[b3.v_num.size()-1]*=-1;
        reverse(b1.v_num.begin(),b1.v_num.end());
        reverse(b2.v_num.begin(),b2.v_num.end());
        reverse(b3.v_num.begin(),b3.v_num.end());
    }
    //(-n)+x or n+(-x)
    if((first_neg && !sec_neg) || (!first_neg && sec_neg)){
        int sign=1;
        if(b2 > b1){
            BigInt tmp;
            tmp.v_num=b1.v_num;
            b1.v_num=b2.v_num;
            b2.v_num=tmp.v_num;
            sign=2;
        }
        reverse(b1.v_num.begin(),b1.v_num.end());
        reverse(b2.v_num.begin(),b2.v_num.end());
        int size=b1.v_num.size();
        for (int i = 0; i <size  ; i++) {
            if(i > b2.v_num.size()-1)
                b3.v_num.push_back(b1.v_num[i]);
            else{
                int x=b1.v_num[i]-b2.v_num[i];
                if(x<0){
                    int j=i+1;
                    while(b1.v_num[j]==0){
                        b1.v_num[j]+=9;
                        j++;
                    }
                    int c=(b1.v_num[i]+10)-b2.v_num[i];
                    b3.v_num.push_back(c);
                    b1.v_num[j]-=1;
                }
                else if(x>=0)
                    b3.v_num.push_back(x);
            }
        }
        if(b1.v_num==b2.v_num){
        }
        else{
            bool test= true;
            for (int i = b3.v_num.size()-1 ; i >=0 ; i--) {
                if(b3.v_num[i]!=0)
                    test= false;
                if(test)
                    b3.v_num.pop_back();
            }
        }
        reverse(b1.v_num.begin(),b1.v_num.end());
        reverse(b2.v_num.begin(),b2.v_num.end());
        reverse(b3.v_num.begin(),b3.v_num.end());
        if(sign==1){
            if(first_neg)
                b3.v_num[0]*=-1;
        }
        else if(sign==2){
            if(sec_neg)
                b3.v_num[0]*=-1;
        }
    }
    return b3;
}

BigInt BigInt::operator=(BigInt anotherDec) {
    v_num=anotherDec.v_num;
    return *this;
}

ostream& operator << (ostream& out , BigInt& b){
    for (int i = 0; i < b.v_num.size(); ++i) {
        out<<b.v_num[i];
    }
    return out;
}

int BigInt::size() {
    int size=v_num.size();
    return size;
}