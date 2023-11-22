#ifndef ARCHIVO_H
#define ARCHIVO_H
#include <libreria_global.h>
#include<sstream>
#include <fstream>
#include <ctime>
#include"Estructuras.h"
typedef enum codArchivos{ErrorApertura=-1, ErrorEscritura=0, ExitoOperacion=1} eCodArchivos;
void  escribirArchivoAsistencia( ofstream &archi, Asistencia *asistencia, unsigned int cantAsistencias);
void lecturaClases(ifstream &archivo, Clases* &misclases, unsigned int &tam);
void lecturaClientes(ifstream &archivo, Clientes* &misclientes, unsigned int &tam);
void lecturaAsistencias(ifstream &archivo,Asistencia*asistencias,unsigned int &tam);
unsigned int leerArchivoAsistenciaB(ifstream& archi, Asistencia *&asistencia);

#endif // ARCHIVOS_H
