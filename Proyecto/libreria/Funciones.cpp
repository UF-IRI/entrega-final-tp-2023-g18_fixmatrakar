#include "Funciones.h"
#include "global.h"

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
            for(unsigned int j=0;j<asistencia[i].cantInscriptos;j++){
            if(asistencia[i].CursosInscriptos[j].idClase==idclase)
                contador++;
            }
            i++;
    }
    return contador;
}

void incrementarClases(Clases* &misclases, unsigned int &tam){
    if(misclases==nullptr){
        if(tam<=0){
            misclases = new Clases[++tam];
        }
        return;
    }

    Clases* temporal = new Clases[++tam];

    for(unsigned int i = 0; i < tam-1; i++){
        temporal[i] = misclases[i];}

    delete[]misclases;


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

    for(unsigned int i = 0; i < tam-1; i++){
        temporal[i] = misclientes[i];}

    delete[] misclientes;

    misclientes = temporal;

}
Clases DevolverClase(Clases*misclases,unsigned int cant_clases, unsigned int eleccion2,unsigned int eleccion3){

    Clases claseElegida;
    switch(eleccion2){
    case 1:{
        claseElegida.nombre="Spinning";
        break;
    }
    case 2:{
        claseElegida.nombre="Yoga";
        break;
    }
    case 3:{
        claseElegida.nombre="Pilates";
        break;
    }
    case 4:{
        claseElegida.nombre="Stretching";
        break;
    }
    case 5:{
        claseElegida.nombre="Zumba";
        break;
    }
    case 6:{
        claseElegida.nombre="Boxeo";
        break;
    }
    case 7:{
        claseElegida.nombre="Musculacion";
        break;
    }

    }

    unsigned int cant_horarios=0;
    string* mishorarios=nullptr;

    for(unsigned int i=0;i<cant_clases;i++){
        if(misclases[i].nombre==claseElegida.nombre){
            ResizeHorarios(cant_horarios,mishorarios);
            mishorarios[cant_horarios-1]=misclases[i].horario;
        }
    }
    for(unsigned int j=0;j<cant_horarios;j++){
        if(j==eleccion3-1){
            claseElegida.horario=mishorarios[j];
        }
    }

    for(unsigned int i=0;i<cant_clases;i++){
        if(misclases[i].nombre==claseElegida.nombre&&misclases[i].horario==claseElegida.horario)
            claseElegida.idclase= misclases[i].idclase;
    }
    return claseElegida;
}

void ResizeHorarios(unsigned int&tam, string*& mishorarios){
    if(mishorarios==nullptr){
        if(tam<=0){
            mishorarios = new string[++tam];
        }
        return;
    }

    string* temporal = new string[++tam];

    for(unsigned int i = 0; i < tam-1; i++){
        temporal[i] = mishorarios[i];
    }

    delete[] mishorarios;

    mishorarios = temporal;

}



bool HayCupo(unsigned int eleccion,unsigned int cupoActual,unsigned int* cupos_maximos){
    int ok=0;
    switch(eleccion-1){
    case 0:{//spinning
        if(cupoActual<cupos_maximos[0]){
            return true;
        }else{
            return false;
        }
    }
    case 1:{//yoga
        if(cupoActual<cupos_maximos[1]){
            return true;
        }else{
            return false;
        }
    }
    case 2:{//pilates
        if(cupoActual<cupos_maximos[2]){
            return true;
        }else{
            return false;
        }


    }
    case 3:{//stretching
        if(cupoActual<cupos_maximos[3]){
            return true;
        }else{
            return false;
        }


    }
    case 4:{//zumba
        if(cupoActual<cupos_maximos[4]){
            return true;
        }else{
            return false;
        }


    }
    case 5:{//boxeo
        if(cupoActual<cupos_maximos[5]){
            return true;
        }else{
            return false;
        }


    }
    case 6:{//musculacion
        if(cupoActual<cupos_maximos[6]){
            return true;
        }else{
            return false;
        }


    }
    }

}

void incrementarAsistencia(Asistencia*& asist, unsigned int &tam){
    if(asist==nullptr){
        asist = new Asistencia[++tam];
        return;
    }

    Asistencia* temporal = new Asistencia[++tam];

    for(unsigned int i = 0; i < tam-1; i++){
        temporal[i] = asist[i];}


    asist = temporal;
}
