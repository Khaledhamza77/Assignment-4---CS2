#ifndef _XXX_
#define _XXX_
#include<iostream>
#include<string>
using namespace std;

class Employee{
private:
    string Name, age, experience, salary;
public:
    Employee(){Name="";age="";experience="";salary="";}
    Employee(string N,string a,string e,string s){
        Name=N;
        age=a;
        experience=e;
        salary=s;
    }
    string get_Name() const {return Name;}
    string get_age() const {return age;}
    string get_exp() const {return experience;}
    string get_salary() const {return salary;}
    void set_salary(string s){salary=s;}
    void set_exp(string e){experience=e;}
    void set_age(string a){age=a;}
    void set_Name(string N){Name=N;}
};
#endif