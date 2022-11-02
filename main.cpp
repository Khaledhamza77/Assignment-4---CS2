#include"hashLL.h"
#include"hashDyn.h"
#include"employee.h"
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;

void readData(vector<Employee> &emp, int row, int &line){
    ifstream myfile;
    myfile.open("data.txt");
    string mytext[36];//36 is the number of lines in data.txt
    for(int i=0;i<36;i++) getline(myfile,mytext[i]);
    emp[row].set_Name(mytext[line]);line++;
    emp[row].set_age(mytext[line]);line++;
    emp[row].set_salary(mytext[line]);line++;
    emp[row].set_exp(mytext[line]);line++;
}

int main(){
    HashTable HLL;
    HashTabDyn HDyn;
    vector<Employee> emp;
    emp.resize(9);
    int line=0;
    for(int i=0;i<emp.size();i++){
        readData(emp,i,line);
    }

    for(int i=0;i<emp.size();i++) {HLL.insert(emp[i]);}
    HLL.print();
    cout<<"--------------------------------\n";
    HLL.remove(emp[3].get_Name());
    HLL.print();
    cout<<"--------------------------------\n";

    for(int i=0;i<emp.size();i++) HDyn.insert(emp[i]);

    HDyn.print();
    cout<<"--------------------------------\n";
    HDyn.remove("Mariam");
    HDyn.print();

    return 0;
}