#include "PhoneDirectory.h"
#include <chrono>
void PhoneDirectory::add_entry() {
    cout<<"enter (first name , last name , phone number) separated by space"<<endl;
    cin>>first_name>>last_name>>phone_num;
    list.push_back(*this);
}

void PhoneDirectory::lp_number(string num) {
    bool found=false;
    for (int i = 0; i < list.size(); ++i) {
        if(list[i].phone_num==num) {
            cout << list[i].first_name << " " << list[i].last_name << " " << list[i].phone_num << endl;
            found = true;
        }
    }
    if(!found)
        cout<<"Not Found!"<<endl;
}

void PhoneDirectory::lp_first_name(string s) {
    bool found=false;
    for (int i = 0; i < list.size(); ++i) {
        if(list[i].first_name==s) {
            cout << list[i].first_name << " " << list[i].last_name << " " << list[i].phone_num << endl;
            found = true;
        }
    }
    if(!found)
        cout<<"Not Found!"<<endl;
}

void PhoneDirectory::insertion_sort() {
    auto start = std::chrono::steady_clock::now();
    for (int i = 1; i < list.size(); ++i) {
        PhoneDirectory tmp=list[i];
        int j;
        for (j = i; j >0 && tmp.first_name<list[j-1].first_name ; j--)
                list[j]=list[j-1];
        list[j]=tmp;
    }
    auto end = std::chrono::steady_clock::now();
    double elapsed_time_ns = double(std::chrono::duration_cast <std::chrono::nanoseconds>(end - start).count());
    cout<<endl<<"time= "<<elapsed_time_ns / 1e9 <<endl;
}

void PhoneDirectory::selection_sort() {
    auto start = std::chrono::steady_clock::now();
    for (int i = 0; i < list.size()-1; i++) {
        int j , min;
        for (j = i+1 , min=i; j < list.size(); j++) {

            if(list[min].first_name > list[j].first_name)
                min=j;
        }
        swap(list[min],list[i]);
    }
    auto end = std::chrono::steady_clock::now();
    double elapsed_time_ns = double(std::chrono::duration_cast <std::chrono::nanoseconds>(end - start).count());
    cout<<endl<<"time= "<<elapsed_time_ns / 1e9 <<endl;
}

void PhoneDirectory::bubble_sort() {
    auto start = std::chrono::steady_clock::now();
    for (int i = 0; i < list.size()-1; ++i) {
        for (int j = 0; j < list.size()-1; ++j) {
            if (list[j].first_name > list[j + 1].first_name)
                swap(list[j].first_name, list[j + 1].first_name);
        }
    }
    auto end = std::chrono::steady_clock::now();
    double elapsed_time_ns = double(std::chrono::duration_cast <std::chrono::nanoseconds>(end - start).count());
    cout<<endl<<"time= "<<elapsed_time_ns / 1e9 <<endl;
}

void PhoneDirectory::del(string s) {
    insertion_sort();
    int size=list.size() , cnt=0;
    for (int i = 0; i < size; ++i) {
        if(list[i].first_name==s){
            cnt++;
            for (int j = i+1; j < size ; j++) {
                list[j-1]=list[j];
            }
            size--;
            i--;
        }
    }
    while(cnt--)
        list.pop_back();
}

ostream& operator << (ostream& op , PhoneDirectory& p1){
    for (int i = 0; i < p1.list.size(); ++i) {
        op << p1.list[i].first_name << " " << p1.list[i].last_name << " " << p1.list[i].phone_num << endl;
    }
    return op;
}