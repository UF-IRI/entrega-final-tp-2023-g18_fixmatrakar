#include <iostream>
#include <sstream>
#include <fstream>
#include<limits>
#include <ctime>

using namespace std;

//-----------estructuras---------//
typedef struct{
    unsigned int idclase;
    string nombre,horario;
} Clases;

typedef struct{
    unsigned int idcliente;
    string nombre,apellido,email,telefono,fechaNac;
    int estado;
}Clientes;

typedef struct{
    unsigned int idcurso;
    time_t fechaIncripcion;
}Inscripcion;

typedef struct{
    unsigned int idcliente, cantInscriptos;
    Inscripcion* CursosInscriptos;
} Asistencia;

//----------funciones-----------//

void lecturaAsistencias(ifstream &archivo,Asistencia*asistencias,unsigned int &tam);
void incrementarAsistencias(Asistencia* &asistencias, unsigned int &tam);

int main(int argc, char *argv[]) {
    Asistencia* asistencias2=nullptr;

    unsigned int cant_asistencias=0;

    ifstream archivob2;

    archivob2.open("c:/Qt/archivob.dat",ios::binary); //nosotras creamos un archivo en esa ruta, que se creo bien con datos random.Anotamos 11 clientes. Usamos la funcion que esta en aclaraciones.

    lecturaAsistencias(archivob2,asistencias2,cant_asistencias);



    cout<<cant_asistencias;// imprime 11

    cout<<asistencias2[6].idcliente<<" "<<asistencias2[6].cantInscriptos;// process crashed.
    
    return 0;
}
 void lecturaAsistencias(ifstream &archivo,Asistencia*asistencias,unsigned int &tam){

        if(archivo.is_open()){

            archivo.seekg(0);

            while(!archivo.eof()){

                incrementarAsistencias(asistencias,tam);

                archivo.read((char*)&asistencias[tam-1].idcliente,sizeof(unsigned int));

                archivo.read((char*)&asistencias[tam-1].cantInscriptos,sizeof(unsigned int));



                asistencias[tam-1].CursosInscriptos= new Inscripcion[asistencias[tam-1].cantInscriptos];

                for(unsigned int i=0;i<asistencias[tam-1].cantInscriptos;i++){

                    archivo.read((char*)&asistencias[tam-1].CursosInscriptos[i],sizeof(Inscripcion));

                }



            }

        }

    }

    void incrementarAsistencias(Asistencia* &asistencias, unsigned int &tam){
        if(asistencias==nullptr){
            if(tam<=0){
                asistencias = new Asistencia[++tam];
            }
            return;
        }

        Asistencia* temporal = new Asistencia[++tam];

        for(unsigned int i = 0; i < tam-1; i++)
            temporal[i] = asistencias[i];

        delete[]asistencias;
        asistencias = temporal;

    }


