#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void BiasedSort(vector<string>&songs){
int c=0;
    for(int i=0;i<songs.size();i++){
        songs[i][0]=toupper(songs[i][0]);
    if(songs[i]=="Untitled")
        c++;

    }
   for (int j, i = 0; i < songs.size(); i++) {
        string tmp = songs[i];
        for (j = i; j > 0 &&(tmp<songs[j-1]); j--)
            songs[j] = songs [j-1];
        songs[j] = tmp;
    }
   for(int i=0;i<songs.size();i++){
       if(songs[i]=="Untitled"){
           songs.erase(songs.begin() + i);
       }
   }
    vector<string>::iterator new_end;
    new_end = remove(songs.begin(), songs.end(),"Untitled");
   for(int i=0;i<c;i++)
       songs.insert(songs.begin(),"Untitled");
}

int main()
{/*
vector <string> song;
song={"flames","untitled","suprnova","Untitled","Happier","lovely","alive","Cradles","crad","runaway","zay","Untitled"};
BiasedSort(song);
for(int i=0;i<song.size();i++){
    cout<<song[i]<<"\n";}*/
//vector for checking
    return 0;
}
