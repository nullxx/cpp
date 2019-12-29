#include <iostream>
#include <string>
#include "Extra.h"
#include <vector>

using namespace std;

class Coche {
    public:
        //Coche();
        //using Coche::Coche;
    Coche(int modelop = 0, int motorp = 0, string pinturap = "rojo", bool descapotablep = false, vector<Extra> extrasp[] = {}){ 
            isModeloValid(modelop) ? setModelo(modelop) : throw invalid_argument("Invalid 'modelo'");
            isMotorValid(motorp) ? setMotor(motorp) : throw invalid_argument("Invalid 'motor'");
            isPinturaValid(pinturap) ? setPintura(pinturap) : throw invalid_argument("Invalid 'pintura'");
            isDescapotableValid(descapotablep) ? setDescapotable(descapotablep) : throw invalid_argument("Invalid 'descapotable'");
            isExtrasValid(*extrasp) ? setExtras(*extrasp) : throw invalid_argument("Invalid 'extras'");
        };
        //~Coche();
        void toString(){
            cout<<"Coche "<<getModeloString(modelo)<<" "<<getDescapotable(descapotable)<<" "<<pintura<<" con motor "<<getMotorString(motor)<<"."<<endl;
            cout<<"Extras: "<<_getExtras()<<endl;
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
        vector<Extra> getExtras(){
            return extras;
        }
        string getModeloString(int mod){
            switch(mod){
                case 0:
                    return "compacto"; break;
                case 1:
                    return "deportivo"; break;
                case 2:
                    return "berlina"; break;
                case 3:
                    return "familiar"; break;
                default:
                    return "compacto"; break;
            }
        };
        string getMotorString(int mot){
            switch(mot){
                case 0:
                    return "gasolina"; break;
                case 1:
                    return "diesel"; break;
                case 2:
                    return "hibrido"; break;
                case 3:
                    return "electrico"; break;
                default:
                    return "gasolina"; break;
            }
        }
        string getDescapotable(bool des){
            if (des){
                return "descapotable";
            }else{
                return "";
            }
        }
        void setModelo(int newModelo){
            modelo = isModeloValid(newModelo) ? newModelo : throw invalid_argument("Invalid 'modelo'");
        }
        void setMotor(int newMotor){
            motor = isMotorValid(newMotor) ? newMotor : throw invalid_argument("Invalid 'modelo'");
        }
        void setPintura(string newPintura){
            pintura = isPinturaValid(newPintura) ? newPintura : throw invalid_argument("Invalid 'pintura'");
        }
        void setDescapotable(bool newDescapotable){
            descapotable = isDescapotableValid(newDescapotable) ? newDescapotable : throw invalid_argument("Invalid 'descapotable'");
        }
        void setExtras(vector<Extra> extras){
            extras = isExtrasValid(extras) ? extras : throw invalid_argument("Invalid 'extras'");
        }
        bool isModeloValid(int mod){
            switch(mod){
                case 0:
                    return true; break;
                case 1:
                    return true; break;
                case 2:
                    return true; break;
                case 3:
                    return true; break;
                default:
                    return false; break;
            }
        }
        bool isMotorValid(int mot){
            switch(mot){
                case 0:
                    return true; break;
                case 1:
                    return true; break;
                case 2:
                    return true; break;
                case 3:
                    return true; break;
                default:
                    return false; throw invalid_argument("Invalid 'motor'"); break;
            }
        }
        bool isPinturaValid(string p){
            bool resultado = false;
            vector<string> availablePinturas = {"rojo", "negro", "azul", "azul metalizado", "gris metalizado"};
            for (string el : availablePinturas){
                if (p == el){
                    resultado = true; break;
                }
                string pr;
                pr.push_back(p.back());
                if (pr == el){
                    throw invalid_argument("Invalid 'pintura'");
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
    private:
        int modelo;
        int motor;
        string pintura;
        bool descapotable;
        vector<Extra> extras;
        
        
        
        string _getExtras(){
            string result;
            for (Extra element : extras){
                result += element.getNombre();
                result += ", ";
            }
            return result;
        }
        
        
        bool isExtrasValid(vector<Extra> extrasp){
            bool result = true;

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

