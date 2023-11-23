#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <global.h>
#include"Estructuras.h"
const unsigned int cupomax[6] = {45, 25, 15, 40, 50, 30};
//enums//

enum Clase { Spinning = 1, Yoga = 2, Pilates = 3, Stretching = 4, Zumba = 5, Boxeo = 6, Musculacion=7 };

bool hayEspacio(int nombre,unsigned int cupoActual, int*maximo);
unsigned int ClasesRepetidas(Asistencia *&AsistUnica, unsigned int CantAsist);
unsigned int cupoactual(Asistencia* asistencias, unsigned int idclase, unsigned int cantAsistencias);
unsigned int BuscarIdClases(Clases *clases, unsigned int horario, string nombre);
void inscribir(Asistencia *& asist, Clases *,unsigned int &CantAsistencias, unsigned int idcliente);
unsigned int buscarClase();


/*--------funciones de resize--------*/
void incrementarClases(Clases* &misclases, unsigned int &tam);
void incrementarClientes(Clientes* &misclientes, unsigned int &tam);
void incrementarAsistencia(Asistencia* &asistencias, unsigned int &tam);
void incrementarInscripciones(Asistencia* &asistencias, unsigned int &tam);

#endif // FUNCIONES_H
