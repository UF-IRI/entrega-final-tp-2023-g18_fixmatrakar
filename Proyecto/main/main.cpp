#include<limits>
#include "archivos.h"

int main() {

    //----variables---//
//    Clases* misclases=nullptr;
//    Clientes* misclientes=nullptr;
//    misclases= NULL;
//    misclientes= NULL;
//    unsigned int cant_clases=0;
//    unsigned int cant_clientes=0;
//    unsigned int cant_asistencias=0;

//    unsigned int eleccion1=0;
//    unsigned int eleccion2=0;
//    unsigned int eleccion3=0;

    //----apertura de archivos----//

    const int cantAsistencias = 2;
    Asistencia dummyAsistencias[cantAsistencias];

    // Guardo la datos
    for (int i = 0; i < cantAsistencias; i++) {
        dummyAsistencias[i].idCliente = i + 1;//id consecuente
        dummyAsistencias[i].cantInscriptos = 3; // creo 3 inscripciones
        dummyAsistencias[i].CursosInscriptos = new Inscripcion[dummyAsistencias[i].cantInscriptos];

        for (unsigned int j = 0; j < dummyAsistencias[i].cantInscriptos; j++) {
            dummyAsistencias[i].CursosInscriptos[j].idClase=1;
            dummyAsistencias[i].CursosInscriptos[j].fechaInscripcion=time(NULL);

        }

    }
                             /*escribo archivito*/

ofstream Earchibinr("archivito.dat", ios::binary);//Escribimos archivo con datos x
   if(Earchibinr.is_open()) {
        for (int i=0; i<cantAsistencias; i++) {
            Earchibinr.write((char*)&dummyAsistencias[i].idCliente, sizeof(unsigned int));
            Earchibinr.write((char*)&dummyAsistencias[i].cantInscriptos, sizeof(unsigned int));
            for(unsigned int j = 0; j < dummyAsistencias[i].cantInscriptos; j++) {
            Earchibinr.write((char*)&dummyAsistencias[i].CursosInscriptos[j],sizeof(Inscripcion));}}cout<<"se escribio archivo";}
 Earchibinr.close();

   /*-----------------Leo archivito.dat-------------*/
 ifstream Larchibinr("archivodemierda.dat", ios::binary);
 unsigned int cant=0;
 Asistencia *lectura=nullptr;
 cant= leerArchivoAsistenciaB(Larchibinr,lectura);
 cout<<cant;

  return 0;
 }

