#include<iostream>

using namespace std;


int askNumber(){
    int integer;
    
    cout<<"Introduce an integer: "; cin>>integer;
    return integer;
}
int main(){
    cout<<"Hello World"<<endl;
    int numIntroduced = askNumber();
    cout<<"You have introduced: "<<numIntroduced<<endl;
    return 0;
}