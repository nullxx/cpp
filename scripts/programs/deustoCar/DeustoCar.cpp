#include <vector>
#include "Coche.h"
//#include "Extra.h" // not necessary to import because is imported inside Coche.h
#include <string>
#include <iostream>

class DeustoCar{
    public:
        DeustoCar(){
             cout<<"DeustoCar, tu concesionario de confianza."<<endl;
        }
        vector<Coche> registrarVentas(vector<Coche> aCoches = {}, vector<Extra> aExtras = {}){
            int modelo = 0, motor = 0; string pintura = "rojo"; bool descapotable = true; vector<Extra> extras = {}; // inicializo
            bool modeloValid = false, motorValid = false, pinturaValid = false, descapotableValid = false, extrasSelectedAll = false;
            
            Coche startInstanceCoche = Coche(modelo, motor, pintura, descapotable, &extras);
            cout<<"Registro de ventas"<<endl;
            cout<<"Introduce los detalles del coche:"<<endl; 
            while (!modeloValid){cout<<"Modelo (0: compacto/1: deportivo/2: berlina/3: familiar): "; cin>>modelo; if (startInstanceCoche.isModeloValid(modelo)){startInstanceCoche.setModelo(modelo);modeloValid = !modeloValid;}}
            while (!motorValid){cout<<"Motor (0: gasolina/1: diesel/2: híbrido/3: eléctrico): "; cin>>motor; if (startInstanceCoche.isMotorValid(motor)){startInstanceCoche.setMotor(motor);motorValid = !motorValid;}}
            while (!pinturaValid){cout<<"Color (rojo, negro, azul, azul metalizado, gris metalizado): "; cin>>pintura; if (startInstanceCoche.isPinturaValid(pintura)){startInstanceCoche.setPintura(pintura);pinturaValid = !pinturaValid;}}
            while (!descapotableValid){cout<<"Descapotable (1/0): "; cin>>descapotable; if (startInstanceCoche.isDescapotableValid(descapotable)){startInstanceCoche.setDescapotable(descapotable);descapotableValid = !descapotableValid;}}
            
            int e = 0;
            
            while (!extrasSelectedAll){cout<<"Extras: "<<endl<<"Selecciona extra "<<e<<":"<<endl; for (size_t i = 0; i < aExtras.size(); i++)
            {
                cout<<i<<". "<<aExtras[i].getNombre()<<endl;
                if (i == aExtras.size()-1){
                    cout<<i+1<<". Salir"<<endl;
                }
            }
            cout<<"¿Opcion? "; int selected; cin>>selected; if (selected >= aExtras.size()){extrasSelectedAll = !extrasSelectedAll;}else{extras.push_back(aExtras[selected]);e++;};
            }
            
            //cout<<"Seleccionado: \n    modelo: "<<modelo<<"\n    motor: "<<motor<<"\n    pintura"<<"\n    descapotable: "<<descapotable<<endl;
            cochesRegistrados.push_back(startInstanceCoche);
            cout<<"Venta almacenada correctamente. ¿Quieres introducir otra? (S/N)?"; string otraVez; cin>>otraVez; if (otraVez == "S"){registrarVentas();}else if (otraVez == "N"){ }
            return cochesRegistrados;
        }

        void mostrarIngresos(vector<Coche> aCoches = {}){
            double total = 0;
            for (Coche coche : aCoches){
                total += coche.getPrecioBase();
                for (Extra extra: coche.getExtras()){
                    total += extra.getPrecio() * extra.getPromocion();
                }
            }
            cout<<"Ingresos totales:  "<<total<<" €"<<endl;
        }
        void mostrarMáximoIngreso(vector<Coche> aCoches = {}){
            double lastIngreso = 0;
            Coche lastIngresoCoche;
            for (Coche coche : aCoches){
                double total(0);
                total += coche.getPrecioBase();
                for (Extra extra: coche.getExtras()){
                    total += extra.getPrecio() * extra.getPromocion();
                }
                if (total > lastIngreso){
                    lastIngreso = total;
                    lastIngresoCoche = coche;
                    
                }
            }
            cout<<"Máximo ingreso:"<<endl;
            lastIngresoCoche.toString();
            cout<<endl<<"Ingreso: "<<lastIngreso<<" €";

        }
    private:
        vector<Coche> cochesRegistrados;
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
    aCoches.push_back(Coche(0, 0, "rojo", false, &aExtras));
    aCoches.push_back(Coche(0, 0, "rojo", false, &aExtras));
    aCoches.push_back(Coche(0, 0, "rojo", false, &aExtras));
    aCoches.push_back(Coche(0, 0, "rojo", false, &aExtras));
    aCoches = DeustoCar().registrarVentas(aCoches, aExtras);
    DeustoCar().mostrarIngresos(aCoches);
    return 0;
}
