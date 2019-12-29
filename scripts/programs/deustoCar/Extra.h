#include<string>
#include<iostream>

using namespace std;

class Extra {
    public:
        Extra(){ }; // default constructor without parameters
        //Extra(string nombrep, float preciop, float promocionp){ }; // constructor with parame
        Extra(string nombrep, float preciop, float promocionp){ // "copy" constructor
            nombre = nombrep;
            precio = preciop;
            promocion = promocionp;
        };
        string getNombre(){
            return nombre;
        };
        float getPrecio(){
            return precio;
        };
        float getPromocion(){
            return promocion;
        };

        void setNombre(string newNombre){
            nombre = newNombre;
        };
        void setPrecio(float newPrecio){
            precio = newPrecio;
        };
        void setPromocion(float newPromocion){
            promocion = newPromocion;
        };
        void toString(){
            cout<<"Nombre: "<<nombre<<endl<<"Precio: "<<precio<<endl<<"Promocion: "<<promocion<<endl;
        }
    private:
        string nombre;
        float precio;
        float promocion;
        
};