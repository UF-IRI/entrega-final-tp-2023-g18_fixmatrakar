#include "Funciones.h"
#include <cstring>
/*typedef struct{
    unsigned int idClase;
    time_t fechaInscripcion;
}Inscripcion;
typedef struct{
    unsigned  idCliente,cantInscriptos;
    Inscripcion* CursosInscriptos;
}Asistencias;
typedef struct{
    unsigned int idclase;
    string nombre,horario;
    unsigned int cupomax;//
} Clases;
typedef struct{
    unsigned int idcliente;
    string nombre,apellido,email,telefono,fechaNac;
    int estado;
}Clientes*/;
unsigned int cupoactual(Asistencia *asistencia, unsigned int idclase, unsigned int cantAsistencias) {
    unsigned int contador = 0;
    unsigned int i = 0 ;
    while (i < cantAsistencias) {
        if (asistencia->CursosInscriptos[i].idClase == idclase)
            contador = contador + 1;
        i++;
    }
    return contador;
}
unsigned int BuscarIdClases(Clases *clases, string horario, string nombre){
    int i = 0;
    while(i != 0){
        if(clases[i].horario == horario && clases[i].nombre==nombre)
            i = clases->idclase;
    }
    return i;
}
void incrementarClases(Clases* &misclases, unsigned int &tam){
    if(misclases==nullptr){
        if(tam<=0){
            misclases = new Clases[++tam];
        }
        return;
    }

    Clases* temporal = new Clases[++tam];

    for(unsigned int i = 0; i < tam-1; i++)
        temporal[i] = misclases[i];


    misclases = temporal;
}
void incrementarClientes(Clientes* &misclientes, unsigned int &tam){
    if(misclientes==nullptr){
        if(tam<=0){
            misclientes = new Clientes[++tam];
        }
        return;
    }

    Clientes* temporal = new Clientes[++tam];

    for(unsigned int i = 0; i < tam-1; i++)
        temporal[i] = misclientes[i];


    misclientes = temporal;

}


void incrementarAsistencias(Asistencia* &asistencias, unsigned int &tam){
    if(asistencias==nullptr){
        if(tam<=0){
            asistencias = new Asistencia[++tam];
        }
        return;
    }

    Asistencia* temporal = new Asistencia[++tam];

    for(unsigned int i = 0; i < tam-1; i++)
        temporal[i] = asistencias[i];


    asistencias = temporal;

}
void incrementarInscripciones(Asistencia* &asistencias, unsigned int &tam){
    if(asistencias->CursosInscriptos==nullptr){
        if(tam<=0){
            asistencias->CursosInscriptos = new Inscripcion[++tam];
        }
        return;
    }

    Inscripcion* temporal = new Inscripcion[++tam];

    for(unsigned int i = 0; i < tam-1; i++)
        temporal[i] = asistencias->CursosInscriptos[i];


    asistencias->CursosInscriptos = temporal;
}
