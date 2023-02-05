
#include "FractionCalculator.h"
FractionCalculator::FractionCalculator(){
    while(c !="E") {
        cout << "enter the operation (+ ,- ,* ,/ ,< ,> ,<= ,>= ,== ,R \"for reduction\" ,E \"for Exit\" ,P \"for previous results\")"<<endl;
        cin >> c;
        if (c == "+") {
            Fraction f1,f2,f3;
            cout << "enter the first fraction \n";
            cin >> f1;
            cout << "enter the second fraction \n";
            cin >> f2;
            f3 = f1 + f2;
            f3=redcution(f3);
            v.push_back(f3);
            cout <<f1<<" + "<<f2<<" = "<<f3<<endl;
        }
        else if(c == "-"){
            Fraction f1,f2,f3;
            cout << "enter the first fraction \n";
            cin >> f1;
            cout << "enter the second fraction \n";
            cin >> f2;
            f3 = f1 - f2;
            f3=redcution(f3);
            v.push_back(f3);
            cout <<f1<<" - "<<f2<<" = "<<f3<<endl;
        }
        else if(c == "*"){
            Fraction f1,f2,f3;
            cout << "enter the first fraction \n";
            cin >> f1;
            cout << "enter the second fraction \n";
            cin >> f2;
            f3 = f1 * f2;
            f3=redcution(f3);
            v.push_back(f3);
            cout <<f1<<" * "<<f2<<" = "<<f3<<endl;
        }
        else if(c == "/"){
            Fraction f1,f2,f3;
            cout << "enter the first fraction \n";
            cin >> f1;
            cout << "enter the second fraction \n";
            cin >> f2;
            f3 = f1 / f2;
            f3=redcution(f3);
            v.push_back(f3);
            cout <<f1<<" / "<<f2<<" = "<<f3<<endl;
        }
        else if(c == "<"){
            Fraction f1,f2;
            cout << "enter the first fraction \n";
            cin >> f1;
            cout << "enter the second fraction \n";
            cin >> f2;
            if(f1 < f2)
                cout<<f1<<" < "<<f2<<endl;
            else
                cout<<"NO"<<endl;
        }
        else if(c == ">"){
            Fraction f1,f2;
            cout << "enter the first fraction \n";
            cin >> f1;
            cout << "enter the second fraction \n";
            cin >> f2;
            if(f1 > f2)
                cout<<f1<<" > "<<f2<<endl;
            else
                cout<<"NO"<<endl;
        }
        else if(c == "=="){
            Fraction f1,f2;
            cout << "enter the first fraction \n";
            cin >> f1;
            cout << "enter the second fraction \n";
            cin >> f2;
            if(f1 == f2)
                cout<<f1<<" == "<<f2<<endl;
            else
                cout<<"NO"<<endl;
        }
        else if(c == "<="){
            Fraction f1,f2;
            cout << "enter the first fraction \n";
            cin >> f1;
            cout << "enter the second fraction \n";
            cin >> f2;
            if(f1 <= f2)
                cout<<f1<<" <= "<<f2<<endl;
            else
                cout<<"NO"<<endl;
        }
        else if(c == ">="){
            Fraction f1,f2;
            cout << "enter the first fraction \n";
            cin >> f1;
            cout << "enter the second fraction \n";
            cin >> f2;
            if(f1 >= f2)
                cout<<f1<<" >= "<<f2<<endl;
            else
                cout<<"NO"<<endl;
        }
        else if(c == "R"){
            Fraction f1 , f2;
            cout << "enter the fraction \n";
            cin >> f1;
            f2=redcution(f1);
            v.push_back(f2);
            cout<<f1<<" = "<<f2<<endl;
        }
        else if(c == "P"){
            for (int i = 0; i < v.size(); ++i) {
                cout<<(i+1)<<") "<<v[i]<<endl;
            }
        }
    }
    cout<<"BYE "<<endl;
}