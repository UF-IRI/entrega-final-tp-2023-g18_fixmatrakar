#include "menu.h"
#include <limits>
//void menuHorarios(Clases*misclases, unsigned int eleccion1){
//    switch(eleccion1){

//    }
//}
void VerMisClases(Asistencia *asistencias,Clases* misclases,unsigned int cant_asistencias,unsigned int cant_clases,unsigned int idcliente){
    for(unsigned int i=0;i<cant_asistencias;i++){
        if(asistencias[i].idCliente==idcliente){
            for(unsigned int j=0;j<asistencias[i].cantInscriptos;j++){
                unsigned int idclase=asistencias[i].CursosInscriptos[j].idClase;
                BuscarMiClase(misclases,cant_clases,idclase);
            }
        }

    }
}
void BuscarMiClase(Clases*misclases,unsigned int tam, unsigned int idcurso){
    for(unsigned int i=0;i<tam;i++){
        if(misclases[i].idclase==idcurso){
            cout<<"-"<<misclases[i].nombre<<","<<misclases[i].horario<<endl;
        }
    }
}

void menuOpciones(){
    cout<<"Que desea hacer hoy?"<<endl;
    cout<<"1.Anotarme en una clase"<<endl;
    cout<<"2.Darme de baja"<<endl;
    cout<<"3.Ver mis clases"<<endl;
    cout<<"4.Salir"<<endl;
}
void clienteNombre(Clientes*misclientes,unsigned int cant_clientes,unsigned int id){
    for(unsigned int i=0;i<cant_clientes;i++){
        if(misclientes[i].idcliente==id){
            cout<<"Bienvenido/a:"<<misclientes[i].nombre<<" "<<misclientes[i].apellido<<endl;

        }
    }
}
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
}
