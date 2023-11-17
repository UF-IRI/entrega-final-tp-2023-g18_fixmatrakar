#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <libreria_global.h>
const string nclases[6] = {"spinning", "yoga", "pilates", "stretching", "zumba", "boxeo"};// nombre de las clases
const int maximo [6]={45, 25, 15,  40, 50, 30};// cupo maximo por clase

typedef struct{
    unsigned int idClase;
    time_t fechaInscripcion;
}Inscripcion;

typedef struct{
    unsigned  idCliente,cantInscriptos;
    Inscripcion* CursosInscriptos;
}Asistencia;

typedef struct{
    unsigned int idclase;
    string nombre,horario;
    unsigned int cupomax;//
} Clases;

typedef struct{
    unsigned int idcliente;
    string nombre,apellido,email,telefono,fechaNac;
    int estado;
}Clientes;


unsigned int cupoactual(Asistencia* asistencias, unsigned int idclase, unsigned int cantAsistencias);
unsigned int BuscarIdClases(Clases *clases, unsigned int horario, string nombre);
void incrementarClases(Clases* &misclases, unsigned int &tam);
void incrementarClientes(Clientes* &misclientes, unsigned int &tam);
void incrementarAsistencias(Asistencia* &asistencias, unsigned int &tam);
void incrementarInscripciones(Asistencia* &asistencias, unsigned int &tam);

#endif // FUNCIONES_H
