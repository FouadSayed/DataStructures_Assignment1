#include <iosfwd>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;
void RecPermute(string soFar, string rest)
{
    set<string> ArrayOfString;
    if (rest == "") // No more characters          a b c b c c
        cout << soFar << endl; // Print the word
    else // Still more chars

        for (int i = 0; i < rest.length(); i++) {
            string next = soFar + rest[i]; // Glue next char
            string remaining = rest.substr(0, i)+ rest.substr(i+1);
            int CurrentSize=ArrayOfString.size();
            ArrayOfString.insert(next);
            if (ArrayOfString.size() > CurrentSize)
                RecPermute(next, remaining);

        }
}

void ListPermutations(string s) {
    RecPermute("", s);
}

int main()
{
    ListPermutations("makka");
    return 0;
}


