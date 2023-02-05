#include <iostream>
#include <string>
#include <chrono>
#include "PhoneDirectory.h"
using namespace std;

int main() {
    PhoneDirectory p1;
    while(true){
        cout<<"--------------------------------------"<<endl;
        cout<<"1. Add an entry to the directory"<<endl;
        cout<<"2. Look up a phone number"<<endl;
        cout<<"3. Look up by first name"<<endl;
        cout<<"4. Delete an entry from the directory"<<endl;
        cout<<"5. List All entries in phone directory"<<endl;
        cout<<"6. Exit form this program"<<endl;
        int x;
        cin>>x;
        if(x==1)
            p1.add_entry();
        else if(x==2){
            cout<<"enter phone number :";
            string phone_number;
            cin>>phone_number;
            p1.lp_number(phone_number);
        }
        else if(x==3){
            cout<<"enter first name :";
            string name;
            cin>>name;
            p1.lp_first_name(name);
        }
        else if(x==4){
            cout<<"enter first name :";
            string name;
            cin>>name;
            p1.del(name);
        }
        else if(x==5){
            p1.selection_sort();
            cout<<p1<<endl;
        }
        else if(x==6)
            break;
    }
}