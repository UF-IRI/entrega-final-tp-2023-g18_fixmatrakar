#ifndef ARCHIVO_H
#define ARCHIVO_H
#include <global.h>
#include<sstream>
#include <fstream>
#include <ctime>
#include"Estructuras.h"


void lecturaClases(ifstream &archivo, Clases* &misclases, unsigned int &tam);//chequeada
void lecturaClientes(ifstream &archivo, Clientes* &misclientes, unsigned int &tam);//chequeada
unsigned int lecturaAsistencia(ifstream& archi, Asistencia*& asistencias);

#endif // ARCHIVOS_H
