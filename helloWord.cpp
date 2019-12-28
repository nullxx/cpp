#include<iostream>

using namespace std;


int askNumber(){
    int integer;
    
    cout<<"Introduce un entero: "; cin>>integer;
    return integer;
}
int main(){
    cout<<"Hello World"<<endl;
    int numIntroduced = askNumber();
    cout<<"Has introducido: "<<numIntroduced<<endl;
    return 0;
}