#include"hashLL.h"
#include"hashDyn.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

void readData(string** &table, int row, int &line){
    ifstream myfile;
    myfile.open("data.txt");
    string mytext[36];//36 is the number of lines in data.txt
    for(int i=0;i<36;i++){
        getline(myfile,mytext[i]);
    }
    for(int i=0;i<4;i++){
        table[row][i]=mytext[line];line++;
    }
}

int main(){
    HashTable HLL;
    HashTabDyn HDyn;
    HLL.insert("Mina",30,10000,4);
    HLL.insert("Fawzy",45,5000,8);
    HLL.insert("Yara",19,2000,0);
    HLL.insert("Mariam",32,8000,2);
    HLL.insert("Ayman",33,4000,8);
    HLL.insert("Roshdy",28,9000,3);
    HLL.insert("Aya",26,6000,3);
    HLL.insert("Abdallah",29,7000,4);
    HLL.insert("Fatma",21,3000,1);
    HLL.print();
    cout<<"--------------------------------\n";
    HLL.remove("Mariam");
    HLL.print();
    cout<<"--------------------------------\n";

    string** table = new string*[9];
    for(int i=0;i<9;i++){
        table[i]=new string[4];
    }
    int line=0;
    for(int i=0;i<9;i++){
        readData(table,i,line);
    }

    for(int i=0;i<9;i++){
        HDyn.insert(table[i]);
    }

    HDyn.print();
    cout<<"--------------------------------\n";
    HDyn.remove(table[3]);
    HDyn.print();

    return 0;
}