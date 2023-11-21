#ifndef ARCHIVO_H
#define ARCHIVO_H
#include <libreria_global.h>
#include<sstream>
#include <fstream>
#include <ctime>
#include"Estructuras.h"
typedef enum codArchivos{ErrorApertura=-1, ErrorEscritura=0, ExitoOperacion=1} eCodArchivos;
void escribirArchivoAsistencia( fstream	*archi, Asistencia *asistencias);
void lecturaClases(ifstream &archivo, Clases* &misclases, unsigned int &tam);
void lecturaClientes(ifstream &archivo, Clientes* &misclientes, unsigned int &tam);
void lecturaAsistencias(ifstream &archivo,Asistencia*asistencias,unsigned int &tam);
void leerArchivoAsistenciaB(fstream& archi, Asistencia *&asistencia);
#endif // ARCHIVOS_H
