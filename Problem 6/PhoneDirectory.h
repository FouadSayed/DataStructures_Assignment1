#ifndef UNTITLED_PHONEDIRECTORY_H
#define UNTITLED_PHONEDIRECTORY_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class PhoneDirectory {
private:
    string first_name , last_name;
    string phone_num;
    vector <PhoneDirectory> list;
public:
    void add_entry();
    void lp_number(string num);
    void lp_first_name(string s);
    void insertion_sort();
    void selection_sort();
    void bubble_sort();
    void del(string s);
    friend ostream& operator << (ostream& op , PhoneDirectory& p1);
};


#endif //UNTITLED_PHONEDIRECTORY_H
