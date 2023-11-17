#ifndef MENU_H
#define MENU_H
#include <libreria_global.h>
#include"Estructuras.h"
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
