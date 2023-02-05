
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class StudentName
{
private:
    string name;
public:
    StudentName(string x)
    {
        int NumOfSpacesInString=0,j=0;
        string last;
        for(int i=0; i<x.length(); i++)
        {
            if (x[i]==' ')
                NumOfSpacesInString++;
        }

        if (NumOfSpacesInString<2)
        {
            if(NumOfSpacesInString==0)
                name=x+" "+x+" "+x;
            else
            {
                for(int i=0;i<x.length();i++){

                    if(x[i]==' '){
                        for(int m=i;m<x.length();m++,j++)
                            last.insert(j, 1, x[m+1]);
                        break;
                    }
                }
                name=x+" "+last;
            }
        }
        else
            name=x;
    }
    void print_Name()
    {
        string k;
        int b=0;
        vector <string> Names;
            for(int j=0; j<=name.length() ; j++){
                if (name[j]!=' '){
                    k.insert(b, 1, name[j]);
                    b++;
                    if (j==name.length())
                       Names.push_back(k);
                    }
                else{
                        Names.push_back(k);
                        k="";
                        b=0;
                }
            }

        for(int i=0; i<Names.size(); i++)
        {
            cout<<i+1<<") "<<Names[i]<<endl;

        }
        cout<<"-----------------------------\n";
    }
    string get_name(){
        return name;
    }

    bool Replace(int fir,int sec)
    {
        if(fir>=name.length()||fir<0||sec>=name.length()||sec<0)
                return false;
        string k,temp,tempp;
        int b=0;
        vector <string> Names;
            for(int j=0; j<=name.length() ; j++){
                if (name[j]!=' '){
                    k.insert(b, 1, name[j]);
                    b++;
                    if (j==name.length())
                       Names.push_back(k);
                    }
                else{
                        Names.push_back(k);
                        k="";
                        b=0;
                }
            }


            temp=Names[fir];
            Names[fir]=Names[sec];
            Names[sec]=temp;

        int p=0;
        for(int i=0;i<Names.size();i++){
            if (i==Names.size()-1){
                            tempp+=Names[i];
                            break;

            }
            tempp+=Names[i]+' ';
        }
        name=tempp;
        return true;
    }
};

int main()
{
        StudentName student1("Fouad Sayed");
        cout<<student1.get_name()<<endl;
        if(student1.Replace(0,2))
            student1.print_Name();

        StudentName student2("Khalid");
        cout<<student2.get_name()<<endl;
        if(student2.Replace(1,2))
            student2.print_Name();

        StudentName student3("Ahmed Hossam Mido Khalid");
        cout<<student3.get_name()<<endl;
        if(student3.Replace(0,3))
            student3.print_Name();

        StudentName student4("Mariam Osama Ahmed");
        cout<<student4.get_name()<<endl;
        if(student4.Replace(1,2))
            student4.print_Name();

        StudentName student5("Sama Hussien");
        cout<<student5.get_name()<<endl;
        if(student5.Replace(0,2))
            student5.print_Name();




    return 0;
}
