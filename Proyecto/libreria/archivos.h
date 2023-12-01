#ifndef ARCHIVO_H
#define ARCHIVO_H
#include "global.h"
#include<sstream>
#include <fstream>
#include <ctime>
#include"Estructuras.h"


void lecturaClases(ifstream &archivo, Clases* &misclases, unsigned int &tam);//chequeada
void lecturaClientes(ifstream &archivo, Clientes* &misclientes, unsigned int &tam);//chequeada
unsigned int lecturaAsistenciaB(ifstream& archi, Asistencia*& asistencias);
void EscrituraBinario(ofstream& archivo, Asistencia* asistencias, unsigned int tam);

#endif // ARCHIVOS_H
