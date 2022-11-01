#include<iostream>
#include<string>
using namespace std;

template<typename T, typename Q>
class HashTabDyn{
private:
    int numElem;
    T** table;
    int Hash(string Name){return int(Name[0])%10;}
public:
    HashTabDyn(){
        numElem=0;
        table = new T*[10];
        for(int i=0;i<10;i++){
            table[i]=new Q[4];
        }
        for(int i=0;i<10;i++){
            for(int j=0;j<4;j++){
                table[i][j]="";
            }
        }
    }
    ~HashTabDyn(){
        for(int i=0;i<9;i++){
            delete []table[i];
        }
        delete []table;
    }
    void insert(T* data){
        int index=Hash(data[0]);
        if(table[index][0]==""){
            table[index]=data;numElem++;
        }
        else{
            while(table[index][0]!="" && table[index][0]==data[0]){index=(index+1)%10;index++;}
            if(table[index][0]==""){table[index]=data;numElem++;}
            else cout<<"This person is already in the table!\n";
        }
    }
    void remove(T* data){
        
    }

};