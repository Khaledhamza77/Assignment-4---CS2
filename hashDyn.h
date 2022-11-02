#include<iostream>
#include<string>
using namespace std;

class HashTabDyn{
private:
    int numElem;
    string** table;
    int Hash(string Name){return int(Name[0])%10;}
    int numCollisions;
public:
    HashTabDyn(){
        numElem=0;
        numCollisions=0;
        table = new string*[10];
        for(int i=0;i<10;i++){
            table[i]=new string[4];
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
    void insert(string* data){
        int index=Hash(data[0]);
        if(table[index][0]==""){
            table[index]=data;numElem++;
        }
        else{
            while(table[index][0]!="" && table[index][0]!=data[0]){index=(index+1)%10;numCollisions++;}
            if(table[index][0]==""){table[index]=data;numElem++;}
            else cout<<"This person is already in the table!\n";
        }
    }
    void remove(string* data){
        int index=Hash(data[0]);
        if(table[index][0]=="")cout<<"There is nothing to remove!\n";
        else if(table[index][0]==data[0]){
            table[index][0]="";numElem--;
        }
        else{
            for(int i=0;i<10;i++){
                if(table[i][0]==data[0]){
                    for(int j=0;j<4;j++) table[i][j]="";
                    numElem--;
                }
            }
        }
    }
    void print(){
        for(int i=0;i<10;i++){
            cout<<i<<": ";
            for(int j=0;j<4;j++){
                if(table[i][j]!="")
                    cout<<table[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    float get_CollRate(){
        return static_cast<float>(numCollisions)/static_cast<float>(numElem);
    }
};