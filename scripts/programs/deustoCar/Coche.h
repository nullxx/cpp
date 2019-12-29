#include <iostream>
#include <string>
#include "Extra.h"
#include <vector>

using namespace std;

class Coche {
    public:
        Coche(int modelop = 0, int motorp = 0, string pinturap = "rojo", bool descapotablep = false, vector<Extra> *extrasp[] = {}){ 
            modelo = modelop;
            motor = motorp;
            pintura = isPinturaValid(pinturap) ? pinturap : throw invalid_argument("Please, provide a valid 'pintura' value.");
            descapotable = isDescapotableValid(descapotablep) ? descapotablep : throw invalid_argument("Please provide a valid 'descapotable' value.");
            extras = isExtrasValid(*extrasp) ? *extrasp : throw invalid_argument("Please provide a valid instance of extras.");

        };
        void toString(){
            cout<<"Coche "<<getModelo()<<" "<<getDescapotable()<<" "<<pintura<<" con motor "<<getMotor()<<"."<<endl;
            cout<<"Extras: "<<getExtras()<<endl;
        };
        double getPrecioBase(){
            double resultado;
            switch(modelo){
                case 0:
                    resultado += 6000.0; break;
                case 1:
                    resultado += 12000.0; break;
                case 2:
                    resultado += 18000.0; break;
                case 3:
                    resultado += 20000.0; break;
                default:
                    resultado += 0.0; break;
            }
            switch(motor){
                case 0:
                    resultado += 0.0; break;
                case 1:
                    resultado += 2000.0; break;
                case 2:
                    resultado += 3500.0; break;
                case 3:
                    resultado += 5000.0; break;
                default:
                    resultado += 0.0; break;
            }
            if (pintura == "metalizada"){
                resultado += 1000.0;
            }
            if (descapotable){
                resultado += 4000.0;
            }
            return resultado;
        }
    private:
        int modelo;
        int motor;
        string pintura;
        bool descapotable;
        vector<Extra> extras;
        string getModelo(){
            switch(modelo){
                case 0:
                    return "compacto"; break;
                case 1:
                    return "deportivo"; break;
                case 2:
                    return "berlina"; break;
                case 3:
                    return "familiar"; break;
                default:
                    return "unknow"; break;
            }
        };
        string getMotor(){
            switch(motor){
                case 0:
                    return "gasolina"; break;
                case 1:
                    return "diesel"; break;
                case 2:
                    return "hibrido"; break;
                case 3:
                    return "electrico"; break;
                default:
                    return "unknow"; break;
            }
        }
        string getDescapotable(){
            if (descapotable){
                return "descapotable";
            }else{
                return "";
            }
        }
        string getExtras(){
            string result;
            for (Extra element : extras){
                result += element.getNombre();
                result += ", ";
            }
            return result;
        }
        bool isPinturaValid(string p){
            bool resultado = false;
            vector<string> availablePinturas = {"rojo", "negro", "azul", "azul metalizado", "gris metalizado"};
            for (string el : availablePinturas){
                if (p == el){
                    resultado = true; break;
                }
            }
            return resultado;
        }
        bool isDescapotableValid(bool des){
            if (des == true || des == false){
                return true;
            }else{
                return false;
            }
        }
        bool isExtrasValid(vector<Extra> extrasp){
            bool result = false;
            for (Extra el : extrasp){
                if(dynamic_cast<Extra*>(&el)){
                    result = true; break;
                }else{
                    result = false;
                }
            }
            return result;

        }
};
