#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H
#include <ctime>
#include <string>

using namespace std;
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
    unsigned int cupoactual;//
} Clases;

typedef struct{
    unsigned int idcliente;
    string nombre,apellido,email,telefono,fechaNac;
    int estado;
}Clientes;

#endif // ESTRUCTURAS_H
