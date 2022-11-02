#include<iostream>
#include<string>
#include"employee.h"
using namespace std;

class HashTabDyn{
private:
    int numElem;
    Employee* table;
    int Hash(string Name){return int(Name[0])%10;}
    int numCollisions;
public:
    HashTabDyn(){
        numElem=0;
        numCollisions=0;
        table = new Employee[10];
    }
    ~HashTabDyn(){
        delete []table;
    }
    void insert(Employee x){
        int index=Hash(x.get_Name());
        if(table[index].get_Name()==""){
            table[index]=x;numElem++;
        }
        else{
            while(table[index].get_Name()!="" && table[index].get_Name()!=x.get_Name()){index=(index+1)%10;}
            if(table[index].get_Name()==""){table[index]=x;numElem++;numCollisions++;}
            else cout<<"This person is already in the table!\n";
        }
    }
    void remove(string Name){
        int index=Hash(Name);
        if(table[index].get_Name()=="")cout<<"There is nothing to remove!\n";
        else if(table[index].get_Name()==Name){
            table[index].set_Name("");table[index].set_age("");table[index].set_exp("");table[index].set_salary("");
            numElem--;
        }
        else{
            for(int i=0;i<10;i++){
                if(table[i].get_Name()==Name){
                    table[i].set_Name("");table[i].set_age("");table[i].set_exp("");table[i].set_salary("");
                    numElem--;
                }
            }
        }
    }
    void print(){
        for(int i=0;i<10;i++){
            cout<<i<<": ";
            if(table[i].get_Name()!="") cout<<table[i].get_Name()<<" ";
            cout<<endl;
        }
        cout<<"The collision rate is: "<<numCollisions<<"/"<<numElem<<" or "<<this->get_CollRate()<<endl;
    }
    float get_CollRate(){
        return static_cast<float>(numCollisions)/static_cast<float>(numElem);
    }
};