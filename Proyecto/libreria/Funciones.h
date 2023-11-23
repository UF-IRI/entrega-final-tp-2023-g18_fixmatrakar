#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <global.h>
#include"Estructuras.h"

//enums//

enum Clase { Spinning = 0, Yoga = 1, Pilates =2 , Stretching = 3, Zumba = 4, Boxeo = 5, Musculacion=6 };


unsigned int ClasesRepetidas(Asistencia *&AsistUnica, unsigned int CantAsist);
unsigned int cupoactual(Asistencia* asistencias, unsigned int idclase, unsigned int cantAsistencias); //chequeada
void inscribir(Asistencia *& asist, Clases *,unsigned int &CantAsistencias, unsigned int idcliente);
unsigned int buscarClase();
Clases DevolverClase(Clases*misclases,unsigned int cant_clases, unsigned int eleccion2,unsigned int eleccion3);//chequeada
bool HayCupo(unsigned int eleccion,unsigned int cupoActual, unsigned int* cupos_maximos);//chequeada

/*--------funciones de resize--------*/
void incrementarClases(Clases* &misclases, unsigned int &tam);//chequeada
void incrementarClientes(Clientes* &misclientes, unsigned int &tam);//chequeada
void incrementarAsistencia(Asistencia*& asist, unsigned int &tam);
void ResizeHorarios(unsigned int&tam,string*& mishorarios);//chequeda
#endif // FUNCIONES_H
