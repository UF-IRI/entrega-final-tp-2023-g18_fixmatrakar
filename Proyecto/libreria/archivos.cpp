#include "archivos.h"
#include "Funciones.h"



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
unsigned int lecturaAsistencia(ifstream& archi, Asistencia*& asistencias) {
    if (archi.is_open()) {
        archi.clear();
        archi.seekg(0);

        unsigned int cantAsistencia = 0; // Variable para saber cantidad de asistencias

        while (!archi.eof()) {
            incrementarAsistencia(asistencias, cantAsistencia);

            Asistencia* nuevaAsistencia = &asistencias[cantAsistencia - 1]; // Obtener la dirección de la nueva asistencia

            archi.read((char*)&nuevaAsistencia->idCliente, sizeof(unsigned int));
            archi.read((char*)&nuevaAsistencia->cantInscriptos, sizeof(unsigned int)); // Leer cada asistencia

            nuevaAsistencia->CursosInscriptos = new Inscripcion[nuevaAsistencia->cantInscriptos]; // Crear inscripciones de ese tamaño

            for (unsigned int j = 0; j < nuevaAsistencia->cantInscriptos; j++) {
                archi.read((char*)&nuevaAsistencia->CursosInscriptos[j], sizeof(Inscripcion)); // Leer cada inscripcion
            }
        }

        return cantAsistencia; // Devolver la cantidad de asistencias leídas
    }
}


