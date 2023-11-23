#ifndef MENU_H
#define MENU_H
#include <global.h>
#include"Estructuras.h"
bool BuscarCliente(Clientes*misclientes,unsigned int idcliente, unsigned int tam);//chequeada
void LimpiarBuffer();//chequeada
void menuClases(Clases*misclases,unsigned int tam);//chequeada
int diaDeHoy();//chequeada
void menuHorarios(Clases*misclases,int&cont,unsigned int cant_clases, unsigned int eleccion);//chequeada
void clienteNombre(Clientes*misclientes,unsigned int cant_clientes,unsigned int id);//chequeada
void menuOpciones();//chequeada
void VerMisClases(Asistencia*asistencias,Clases*misclases,int tam,int idcliente);




#endif // MENU_H
