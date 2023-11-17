#ifndef MENU_H
#define MENU_H
#include <libreria_global.h>
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
bool BuscarCliente(Clientes*misclientes,unsigned int idcliente, unsigned int tam);
void LimpiarBuffer();
void menuClases(Clases*misclases,unsigned int tam);
int diaDeHoy();
void menuHorarios(Clases*misclases, unsigned int eleccion1);
void clienteNombre(Clientes*misclientes,unsigned int cant_clientes,unsigned int id);
void menuOpciones();
void VerMisClases(Asistencia*asistencias,Clases*misclases,int tam,int idcliente);
void BuscarMiClase(Clases*misclases,int tam, int id);

#endif // MENU_H
