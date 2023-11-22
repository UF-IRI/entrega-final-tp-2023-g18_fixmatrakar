#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <libreria_global.h>
#include"Estructuras.h"
const unsigned int cupomax[6] = {45, 25, 15, 40, 50, 30};
enum Clase { Spinning = 0, Yoga = 1, Pilates = 2, Stretching = 3, Zumba = 4, Boxeo = 5 };

bool hayEspacio(int nombre,unsigned int cupoActual, int*maximo);
unsigned int ClasesRepetidas(Asistencia *&AsistUnica, unsigned int CantAsist);
unsigned int cupoactual(Asistencia* asistencias, unsigned int idclase, unsigned int cantAsistencias);
unsigned int BuscarIdClases(Clases *clases, unsigned int horario, string nombre);
void inscribir(Asistencia *& asist, Clases *,unsigned int &CantAsistencias, unsigned int idcliente);
unsigned int buscarClase();


/*--------funciones de rezize--------*/
void incrementarClases(Clases* &misclases, unsigned int &tam);
void incrementarClientes(Clientes* &misclientes, unsigned int &tam);
void incrementarAsistencia(Asistencia* &asistencias, unsigned int &tam);
void incrementarInscripciones(Asistencia* &asistencias, unsigned int &tam);

#endif // FUNCIONES_H
