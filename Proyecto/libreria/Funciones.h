#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "global.h"
#include"Estructuras.h"

//enums//



Clases BuscarAux(Clases*misclases,unsigned int idclase, unsigned int cant_clases);
bool ClasesRepetidas(Asistencia *AsistUnica, unsigned int CantAsist, unsigned int idclase,unsigned int idcliente);//chequeada
unsigned int cupoactual(Asistencia* asistencias, unsigned int idclase, unsigned int cantAsistencias); //chequeada
void inscribir(Asistencia *&asistencias, unsigned int &cant_asistencias, unsigned int idclase,unsigned int idcliente);//chequeada

Clases DevolverClase(Clases*misclases,unsigned int cant_clases, unsigned int eleccion2,unsigned int eleccion3);//chequeada
bool HayCupo(unsigned int eleccion,unsigned int cupoActual, unsigned int* cupos_maximos);//chequeada
void VermisClases(Asistencia* asistencias,Clases* misclases,unsigned int cant_asistencias,unsigned int cant_clases,unsigned int idcliente);
/*--------funciones de resize--------*/
void incrementarClases(Clases* &misclases, unsigned int &tam);//chequeada
void incrementarClientes(Clientes* &misclientes, unsigned int &tam);//chequeada
void incrementarAsistencia(Asistencia*& asist, unsigned int &tam);//chequeada
void ResizeHorarios(unsigned int&tam,string*& mishorarios);//chequeda
void reducirMemoria(unsigned int&tam, Asistencia*& asistencias);
#endif // FUNCIONES_H
