#ifndef MENU_H
#define MENU_H
#include <global.h>
#include"Estructuras.h"
bool BuscarCliente(Clientes*misclientes,unsigned int idcliente, unsigned int tam);
void LimpiarBuffer();
void menuClases(Clases*misclases,unsigned int tam);
int diaDeHoy();
void menuHorarios(Clases*misclases,int&cont,unsigned int cant_clases, unsigned int eleccion);
void clienteNombre(Clientes*misclientes,unsigned int cant_clientes,unsigned int id);
void menuOpciones();
void VerMisClases(Asistencia*asistencias,Clases*misclases,int tam,int idcliente);
void BuscarMiClase(Clases*misclases,unsigned int tam,unsigned int id);
void ResizeHorarios(unsigned int&tam,string*& mishorarios);
ClaseSeleccionada DevolverClase(Clases*misclases,unsigned int cant_clases, unsigned int eleccion2,unsigned int eleccion3);

#endif // MENU_H
