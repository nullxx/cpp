#include <vector>
#include "Coche.h"
//#include "Extra.h" // not necessary to import because is imported inside Coche.h
#include <string>
#include <iostream>

class DeustoCar{
    public:
    void registrarVentas(vector<Coche> aCoches = {}, vector<Extra> aExtras = {}){
        int modelo; int motor; string pintura; bool descapotable;
        cout<<"Introduce el modelo: "; cin>>modelo; cout<<endl;
        cout<<"Introduce el motor: "; cin>>motor; cout<<endl;
        cout<<"Introduce la pintura elegida: "; cin>>pintura; cout<<endl;
        cout<<"Descapotable (true, false): "; cin>>descapotable; cout<<endl;

        cout<<"Seleccionado: \n    modelo: "<<modelo<<"\n    motor: "<<motor<<"\n    pintura"<<"\n    descapotable: "<<descapotable<<endl;
    }
    void mostrarIngresos(vector<Coche> aCoches = {}){
        for (Coche coche : aCoches){
           cout<< coche.getPrecioBase();
        }
    }
};



int main()
{
    vector<Extra> aExtras; 
    aExtras.push_back(*new Extra("Lunas tintadas", 1500, 0.8));
    aExtras.push_back(*new Extra("Faros de Xenón", 2000, 0.6));
    aExtras.push_back(*new Extra("Manos libres", 1000, 1));
    aExtras.push_back(*new Extra("Navegador GPS", 1000, 0.75));
    aExtras.push_back(*new Extra("Tracción total", 3000, 1));
    aExtras.push_back(*new Extra("Entretenimiento", 1200, 0.8));
    aExtras.push_back(*new Extra("Techo solar", 800, 1));
    aExtras.push_back(*new Extra("Tapicería de piel", 1400, 1));
    aExtras.push_back(*new Extra("Llantas", 1300, 0.65));
    aExtras.push_back(*new Extra("Sensores de aparcamiento", 2000, 0.75));
    aExtras.push_back(*new Extra("Bluetooth", 500, 1));
    aExtras.push_back(*new Extra("Internet", 1200, 1));
    aExtras.push_back(*new Extra("Piloto automático", 8000, 1));

    vector<Coche> aCoches = {};
    aCoches.push_back(new Coche(0, 0, "rojo", false, aExtras));
   // DeustoCar().registrarVentas(aCoches, aExtras);
   DeustoCar().mostrarIngresos(aCoches);
    return 0;
}
