#include <archivos.h>
#include <libreria_global.h>
#include <Funciones.h>
#include <sstream>
#include <fstream>
//typedef struct{
//unsigned int idClase;
//time_t fechaInscripcion;
//}Inscripcion;

//typedef struct{
//    unsigned  idCliente,cantInscriptos;
//    Inscripcion* CursosInscriptos;
//}Asistencia;

void leerArchivoAsistenciaB(fstream& archi, Asistencia *&asistencia, unsigned int CantAsistencia) {
    if (archi.is_open()) {
        archi.clear();//Limpio
        archi.seekg(0);//Busco inicio
        unsigned int i=0;
        while (i<CantAsistencia && !archi.eof()) {  // Mientras no se llegue al final del archivo

            archi.read(reinterpret_cast<char*>(&asistencia[i].idCliente), sizeof(unsigned int));
            archi.read(reinterpret_cast<char*>(&asistencia[i].cantInscriptos), sizeof(unsigned int));
            incrementarAsistencias(asistencia, CantAsistencia);

            for (unsigned int j = 0; j < asistencia->cantInscriptos; j++) {// Leer cada Inscripcion
                archi.read(reinterpret_cast<char*>(&asistencia[i].CursosInscriptos[j].idClase), sizeof(unsigned int));
                archi.read(reinterpret_cast<char*>(&asistencia[i].CursosInscriptos[j].fechaInscripcion), sizeof(time_t));
                incrementarInscripciones(asistencia,CantAsistencia);
            }

            i++;}
    }}

void escribirArchivoAsistencia( ofstream &archi, Asistencia *asistencia, unsigned int cantAsistencias){
    if(archi.is_open()){
        for (unsigned int i=0; i<cantAsistencias; i++) {
            archi.write(reinterpret_cast<char*>(&asistencia[i].idCliente), sizeof(unsigned int));
            archi.write(reinterpret_cast<char*>(&asistencia[i].cantInscriptos), sizeof(unsigned int));
            for(unsigned int j = 0; j < asistencia[i].cantInscriptos; j++) {
                archi.write(reinterpret_cast<char*>(&asistencia[i].CursosInscriptos[j]), sizeof(Inscripcion));
            } } }
    archi.close();

}

void lecturaClases(ifstream &archivo, Clases* &misclases, unsigned int &tam){
    string linea;
    stringstream s;

    if(archivo.is_open()){

        getline(archivo, linea);

        while(!archivo.eof() && getline(archivo, linea)){
            s.clear();
            s<<linea;

            incrementarClases(misclases,tam);

            getline(s, linea, ',');
            misclases[tam-1].idclase=stoi(linea);
            getline(s, linea, ',');
            misclases[tam-1].nombre=linea;
            getline(s,linea);
            misclases[tam-1].horario=linea;

        }
    }
}
void lecturaClientes(ifstream &archivo, Clientes* &misclientes, unsigned int &tam){
    string linea;
    stringstream s;

    if(archivo.is_open()){

        getline(archivo, linea);

        while(!archivo.eof() && getline(archivo, linea)){
            s.clear();
            s<<linea;

            incrementarClientes(misclientes,tam);

            getline(s, linea, ',');
            misclientes[tam-1].idcliente=stoi(linea);
            getline(s, linea, ',');
            misclientes[tam-1].nombre=linea;
            getline(s, linea, ',');
            misclientes[tam-1].apellido=linea;
            getline(s, linea, ',');
            misclientes[tam-1].email=linea;
            getline(s, linea, ',');
            misclientes[tam-1].telefono=linea;
            getline(s, linea, ',');
            misclientes[tam-1].fechaNac=linea;
            getline(s, linea);
            misclientes[tam-1].estado=stoi(linea);

        }
    }
}
