#include<iostream>
#include<string>
#include"employee.h"
using namespace std;

struct Node{
    Employee e;
    Node* next;
};

class HashTable
{
private:
    int numElem;
    Node* table[10];
    int Hash(string Name){return int(Name[0])%10;}
    int numCollisions;
public:
    HashTable(){
        numElem=0;
        numCollisions=0;
        for(int i=0;i<10;i++){table[i]=NULL;}
    }
    void insert(Employee x){
        Node* n = new Node;
        n->e=x;n->next=NULL;
        int index=Hash(x.get_Name());
        if(table[index]==NULL){
            table[index]=n;numElem++;
        }
        else{
            Node*p=table[index];
            while(p->e.get_Name()!=x.get_Name() && p->next!=NULL){p=p->next;}
            if(p->next==NULL){p->next=n;numElem++;numCollisions++;}
            else{cout<<"This entry already exists!\n";}
        }
    }
    void remove(string Name){
        int index=Hash(Name);
        Node*p=table[index];Node*previous=p;Node*next=p;
        if(table[index]==NULL){cout<<"There is nothing to remove\n";}
        else if(table[index]->e.get_Name()==Name){
           previous->next=next;
           delete p;
           numElem--;  
        }
        else{
            while(p!=NULL && p->e.get_Name()!=Name){
                previous=p;p=p->next;next=p->next;
            }
            if(p==NULL){cout<<"Name isn't found!\n";}
            else{
                previous->next=next;
                delete p;
                numElem--;
            }
        }
    }
    void print(){
        for(int i=0;i<10;i++){
            if(table[i]!=NULL){
                cout<< i <<": ";
                Node* p=table[i];
                while(p!=NULL){
                    cout<<p->e.get_Name()<<" ";
                    p=p->next;
                }
                cout<<endl;
            }
        }
        cout<<"The collision rate is: "<<numCollisions<<"/"<<numElem<<" or "<<this->get_CollRate()<<endl;
    }
    float get_CollRate(){
        return static_cast<float>(numCollisions)/static_cast<float>(numElem);
    }
};