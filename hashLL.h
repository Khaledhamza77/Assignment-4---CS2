#include<iostream>
#include<string>
using namespace std;

struct Node{
    string Name;
    int Age;
    int salary;
    int Exp;
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
    void insert(string Name, int a, int s, int e){
        Node* n = new Node;
        n->Name=Name; n->Age=a; n->salary=s; n->Exp=e; n->next=NULL;
        int index=Hash(Name);
        if(table[index]==NULL){
            table[index]=n;numElem++;
        }
        else{
            Node*p=table[index];
            while(p->Name!=Name && p->next!=NULL){p=p->next;}
            if(p->next==NULL){p->next=n;numElem++;numCollisions++;}
            else{cout<<"This entry already exists!\n";}
        }
    }
    void remove(string Name){
        int index=Hash(Name);
        Node*p=table[index];Node*previous=p;Node*next=p;
        if(table[index]==NULL){cout<<"There is nothing to remove\n";}
        else if(table[index]->Name==Name){
           previous->next=next;
           delete p;
           numElem--;  
        }
        else{
            while(p!=NULL && p->Name!=Name){
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
                    cout<< p->Name <<" ";
                    p=p->next;
                }
                cout<<endl;
            }
        }
    }
    float get_CollRate(){
        return static_cast<float>(numCollisions)/static_cast<float>(numElem);
    }
};