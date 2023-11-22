#include "Funciones.h"
/*typedef struct{
    unsigned int idClase;
    time_t fechaInscripcion;
}Inscripcion;
typedef struct{
    unsigned  idCliente,cantInscriptos;
    Inscripcion* CursosInscriptos;
}Asistencias;
typedef struct{
    unsigned int idclase;
    string nombre,horario;
    unsigned int cupomax;//
} Clases;
typedef struct{
    unsigned int idcliente;
    string nombre,apellido,email,telefono,fechaNac;
    int estado;
}Clientes*/

//bool hayEspacio(string nombre, Clases*clase, unsigned int idclase){

//}
bool hayEspacio(unsigned int nombre, unsigned int cupoActual, unsigned int* maximo) {
    switch (nombre) {
    case Spinning:
        return (cupoActual < maximo[Spinning]);
    case Yoga:
        return (cupoActual < maximo[Yoga]);
    case Pilates:
        return (cupoActual < maximo[Pilates]);
    case Stretching:
        return (cupoActual < maximo[Stretching]);
    case Zumba:
        return (cupoActual < maximo[Zumba]);
    case Boxeo:
        return (cupoActual < maximo[Boxeo]);
    default:
        cout << "   Flashiaste ura " << endl;
        return false; // Retorna un valor por defecto en caso de error
    }


}
unsigned int ClasesRepetidas(Asistencia *&AsistUnica, unsigned int CantAsist) {
    Asistencia *aux = new Asistencia;
    aux->idCliente = AsistUnica->idCliente;
    aux->cantInscriptos = AsistUnica->cantInscriptos;
    aux->CursosInscriptos = new Inscripcion[AsistUnica->cantInscriptos];
    for(unsigned int i = 0; i < aux->cantInscriptos; i++) {
        for(unsigned int j = i + 1; j < aux->cantInscriptos; j++) {
            if(aux->CursosInscriptos[i].idClase == aux->CursosInscriptos[j].idClase) {
                aux->CursosInscriptos[i].idClase = aux->CursosInscriptos[j].idClase;// Tapo la clase
                aux->CursosInscriptos[j].idClase = aux->CursosInscriptos[aux->cantInscriptos - 1].idClase;
                aux->cantInscriptos--; // Resto 1 a cantidad total de inscripciones
                CantAsist--;
                j--;
            }
        }
    }
    delete[] AsistUnica->CursosInscriptos;
    delete AsistUnica;

    // Asignar la estructura auxiliar a AsistUnica
    AsistUnica = aux;

    return CantAsist;
}


void inscribir(Asistencia *& asist,unsigned int &CantAsistencias, unsigned int idcliente){

        Asistencia* nuevasAsistencias = new Asistencia[CantAsistencias + 1];


        for (unsigned int i = 0; i < CantAsistencias ; i++) {
            nuevasAsistencias[i] = asist[i];
        }

        // Agrega la nueva asistencia al final
        nuevasAsistencias[CantAsistencias ].idCliente = idcliente;
        nuevasAsistencias[CantAsistencias ].cantInscriptos = asist->cantInscriptos++;
        nuevasAsistencias[CantAsistencias ].CursosInscriptos = new Inscripcion[asist->cantInscriptos];
        for (unsigned int i = 0; i < CantAsistencias; i++) {
            nuevasAsistencias[CantAsistencias].CursosInscriptos[i] = asist->CursosInscriptos[i];       }


        CantAsistencias++;


        delete[] asist;

        asist = nuevasAsistencias;
    }


unsigned int cupoactual(Asistencia *asistencia, unsigned int idclase, unsigned int cantAsistencias) {
    unsigned int contador = 0;
    unsigned int i = 0 ;
    while (i < cantAsistencias) {
        if (asistencia->CursosInscriptos[i].idClase == idclase)
            contador = contador + 1;
        i++;
    }
    return contador;
}
unsigned int BuscarIdClases(Clases *clases, string horario, string nombre){
    int i = 0;
    while(i != 0){
        if(clases[i].horario == horario && clases[i].nombre==nombre)
            i = clases->idclase;
    }
    return i;
}
void incrementarClases(Clases* &misclases, unsigned int &tam){
    if(misclases==nullptr){
        if(tam<=0){
            misclases = new Clases[++tam];
        }
        return;
    }

    Clases* temporal = new Clases[++tam];

    for(unsigned int i = 0; i < tam-1; i++)
        temporal[i] = misclases[i];


    misclases = temporal;
}
void incrementarClientes(Clientes* &misclientes, unsigned int &tam){
    if(misclientes==nullptr){
        if(tam<=0){
            misclientes = new Clientes[++tam];
        }
        return;
    }

    Clientes* temporal = new Clientes[++tam];

    for(unsigned int i = 0; i < tam-1; i++)
        temporal[i] = misclientes[i];


    misclientes = temporal;

}


void incrementarAsistencia(Asistencia* &asistencias, unsigned int &tam){
    if(asistencias == nullptr){
        tam = 1;
        asistencias = new Asistencia[tam];
        return;
    }

    Asistencia* temporal = new Asistencia[tam + 1];

    for(unsigned int i = 0; i < tam-1; i++)
        temporal[i] = asistencias[i];
    asistencias = temporal;

}

void incrementarInscripciones(Asistencia* &asistencias, unsigned int &tam) {
    if (asistencias->CursosInscriptos == nullptr) {
        asistencias->CursosInscriptos = new Inscripcion[tam];
        return;
    }

    Inscripcion* aux = new Inscripcion[tam];

     for(unsigned int i = 0; i < tam; i++)
        aux[i] = asistencias->CursosInscriptos[i];
    asistencias->CursosInscriptos = aux;
}
