#include "menu.h"
#include "Funciones.h"
#include <limits>


void menuOpciones(){
    cout<<"Que desea hacer hoy?"<<endl;
    cout<<"1.Anotarme en una clase"<<endl;
    cout<<"2.Ver mis clases"<<endl;
    cout<<"3.Salir"<<endl;
}
void clienteNombre(Clientes*misclientes,unsigned int cant_clientes,unsigned int id){
    for(unsigned int i=0;i<cant_clientes;i++){
        if(misclientes[i].idcliente==id){
            cout<<"Bienvenido/a:"<<misclientes[i].nombre<<" "<<misclientes[i].apellido<<endl;

        }
    }
}// damos la bienvenida mostrando el nombre del cliente
int diaDeHoy(){
    time_t tiempo= time(0);
    tm* tiempoInfo= localtime(&tiempo); //+86400 para cambiar de dia
    return tiempoInfo->tm_wday;
}
bool BuscarCliente(Clientes*misclientes,unsigned int idcliente, unsigned int tam){
    for(unsigned int i=0;i<tam;i++){
        if(misclientes[i].idcliente==idcliente&&misclientes[i].estado>=0)
            return true;
    }
    return false;
}

void LimpiarBuffer(){
    cin.clear(); //
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
void menuClases(Clases*misclases,unsigned int tam){
    string variable=misclases[0].nombre;
    int numero=1;
    cout<<numero<<"-"<<misclases[0].nombre<<endl;
    for(unsigned int i=0;i<tam;i++){
        if(misclases[i].nombre!=variable){
            numero++;
            cout<<numero<<"-"<<misclases[i].nombre<<endl;
            variable=misclases[i].nombre;
        }
    }
    cout<<++numero<<"-ATRAS"<<endl;
}//imprimios el menu de clases desde la estructura de clases.
void menuHorarios(Clases*misclases,int&cont,unsigned int cant_clases, unsigned int eleccion){

    switch(eleccion){
    case 1:{
        for(unsigned int i=0;i<cant_clases;i++){
            if(misclases[i].nombre=="Spinning"){
                cout<<++cont<<"-"<<misclases[i].horario<<"hs"<<endl;
            }
        }
        cout<<++cont<<"-ATRAS"<<endl;
        break;
    }
    case 2:{
        for(unsigned int i=0;i<cant_clases;i++){
            if(misclases[i].nombre=="Yoga"){
                cout<<++cont<<"-"<<misclases[i].horario<<"hs"<<endl;
            }
        }
        cout<<++cont<<"-ATRAS"<<endl;
        break;
    }
    case 3:{
        for(unsigned int i=0;i<cant_clases;i++){
            if(misclases[i].nombre=="Pilates"){
                cout<<++cont<<"-"<<misclases[i].horario<<"hs"<<endl;
            }
        }
        cout<<++cont<<"-ATRAS"<<endl;
        break;
    }
    case 4: {
        for(unsigned int i=0;i<cant_clases;i++){
            if(misclases[i].nombre=="Stretching"){
                cout<<++cont<<"-"<<misclases[i].horario<<"hs"<<endl;
            }
        }
        cout<<++cont<<"-ATRAS"<<endl;
        break;
    }
    case 5: {
        for(unsigned int i=0;i<cant_clases;i++){
            if(misclases[i].nombre=="Zumba"){
                cout<<++cont<<"-"<<misclases[i].horario<<"hs"<<endl;
            }
        }
        cout<<++cont<<"-ATRAS"<<endl;
        break;
    }
    case 6: {
        for(unsigned int i=0;i<cant_clases;i++){
            if(misclases[i].nombre=="Boxeo"){
                cout<<++cont<<"-"<<misclases[i].horario<<"hs"<<endl;
            }
        }
        cout<<++cont<<"-ATRAS"<<endl;
        break;
    }
    case 7: {
        for(unsigned int i=0;i<cant_clases;i++){
            if(misclases[i].nombre=="Musculacion"){
                cout<<++cont<<"-"<<misclases[i].horario<<"hs"<<endl;
            }
        }
        cout<<++cont<<"-ATRAS"<<endl;
        break;
    }

    }

}
