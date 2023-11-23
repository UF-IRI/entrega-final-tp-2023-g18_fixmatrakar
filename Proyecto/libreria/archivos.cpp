#include "archivos.h"
#include "Funciones.h"


 unsigned int leerArchivoAsistenciaB(ifstream& archi, Asistencia*& asistencias) {
    if (archi.is_open()) {
        archi.clear();
        archi.seekg(0);

        unsigned int cantAsistencia = 0; // Variable para saber cantidad de asistencias

        while (!archi.eof()) {
            Asistencia* nuevaAsistencia = new Asistencia; // Crear una nueva asistencia

            archi.read((char*)&nuevaAsistencia->idCliente, sizeof(unsigned int));
            archi.read((char*)&nuevaAsistencia->cantInscriptos, sizeof(unsigned int)); // leo cada asistencia

            nuevaAsistencia->CursosInscriptos = new Inscripcion[nuevaAsistencia->cantInscriptos]; // veo sus cursos y creo inscripciones de ese tamaño

            for (unsigned int j = 0; j < nuevaAsistencia->cantInscriptos; j++) {
                archi.read((char*)&nuevaAsistencia->CursosInscriptos[j], sizeof(Inscripcion)); // leo cada inscripcion
            }

             cantAsistencia++;
             incrementarAsistencia(asistencias, cantAsistencia); // Incrementar el tamaño
             asistencias[cantAsistencia - 1] = *nuevaAsistencia; // Guardar la nueva asistencia
        }
        cout << "Se leyó el archivo ";//BORRAR SOLO PARA VERIFICAR
            return cantAsistencia; // Devolver la cantidad de asistencias leídas
    }
    return 4; // No hizo takataka
}
void escribirArchivoAsistencia( ofstream &archi, Asistencia *asistencia, unsigned int cantAsistencias){
    if(archi.is_open()){
        for (unsigned int i=0; i<cantAsistencias; i++) {
            archi.write((char*)(&asistencia[i].idCliente), sizeof(unsigned int));
            archi.write((char*)(&asistencia[i].cantInscriptos), sizeof(unsigned int));
            for(unsigned int j = 0; j < asistencia[i].cantInscriptos; j++) {
                archi.write((char*)(&asistencia[i].CursosInscriptos[j]), sizeof(Inscripcion));
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
