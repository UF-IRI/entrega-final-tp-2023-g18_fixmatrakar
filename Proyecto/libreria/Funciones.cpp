#include "Funciones.h"
#include "global.h"

bool HorarioRepetido(Asistencia* asistencias,Clases* misclases, unsigned int cantAsist,Clases ClaseE,unsigned int cant_clases,unsigned int idcliente){
    unsigned int i=0;
    Clases aux;
    while(i<cantAsist){
        if(asistencias[i].idCliente==idcliente){
            unsigned int j=0;
            while(j<asistencias[i].cantInscriptos){
                aux=BuscarAux(misclases,asistencias[i].CursosInscriptos[j].idClase,cant_clases);
                if(ClaseE.horario==aux.horario){
                    return true;
                }
                j++;
            }
        }
        i++;
    }
    return false;
}
Clases BuscarAux(Clases*misclases,unsigned int idclase, unsigned int cant_clases){
    Clases aux;
    for(unsigned int i=0;i<cant_clases;i++){
        if(misclases[i].idclase==idclase){

            aux=misclases[i];
            break;
        }
    }
    return aux;//esta funcion la usamos en ver mis clases para no imprimir solo el id, y para horario repetidos
}
void VermisClases(Asistencia* asistencias,Clases*misclases,unsigned int cant_asistencias,unsigned int cant_clases,unsigned int idcliente){
    bool hayclases=false;
    for(unsigned int i=0;i<cant_asistencias;i++){
        if(asistencias[i].idCliente==idcliente){
            cout<<"----MIS CLASES-----"<<endl;
            hayclases=true;
            for(unsigned int j=0;j<asistencias[i].cantInscriptos;j++){
                Clases aux= BuscarAux(misclases,asistencias[i].CursosInscriptos[j].idClase,cant_clases);
                cout<<j+1<<"-"<<aux.nombre<<","<<aux.horario<<"hs"<<",ID:"<<aux.idclase<<endl;

            }
            break;

        }
    }
    if(!hayclases){
        cout<<"Todavia no esta inscripto en ninguna clase"<<endl;
    }

}
bool ClasesRepetidas(Asistencia *AsistUnica, unsigned int CantAsist, unsigned int idclase,unsigned int idcliente){
    unsigned int i=0;
    while(i<CantAsist){
        if(AsistUnica[i].idCliente==idcliente){
            unsigned int j=0;
            while(j<AsistUnica[i].cantInscriptos){
                if(AsistUnica[i].CursosInscriptos[j].idClase==idclase){
                    return true;
                }
                j++;
            }
        }
        i++;
    }

    return false;

}



void inscribir(Asistencia *&asistencias, unsigned int &cant_asistencias, unsigned int idclase, unsigned int idcliente) {
    bool clienteEncontrado = false;
    for(unsigned int i = 0; i < cant_asistencias; i++) {
        if(asistencias[i].idCliente == idcliente) {
            clienteEncontrado=true;
            asistencias[i].cantInscriptos++;

            Inscripcion *nuevoArray = new Inscripcion[asistencias[i].cantInscriptos];

            // Copiamos las inscripciones anteriores
            for(unsigned int j = 0; j < asistencias[i].cantInscriptos - 1; j++) {
                nuevoArray[j] = asistencias[i].CursosInscriptos[j];
            }

            // Liberamos la memoria del array antiguo
            delete[] asistencias[i].CursosInscriptos;

            // Agregamos la nueva inscripción
            nuevoArray[asistencias[i].cantInscriptos - 1].idClase = idclase;
            nuevoArray[asistencias[i].cantInscriptos - 1].fechaInscripcion = time(0);

            // Asignamos el nuevo array
            asistencias[i].CursosInscriptos = nuevoArray;
            break;
        }

    }

    // Si el cliente no existe, incrementamos la asistencia y agregamos la inscripción
    if(!clienteEncontrado){
    incrementarAsistencia(asistencias, cant_asistencias);
    asistencias[cant_asistencias - 1].idCliente = idcliente;
    asistencias[cant_asistencias - 1].cantInscriptos = 1;
    asistencias[cant_asistencias - 1].CursosInscriptos = new Inscripcion;
    asistencias[cant_asistencias - 1].CursosInscriptos->idClase = idclase;
    asistencias[cant_asistencias - 1].CursosInscriptos->fechaInscripcion = time(0);
    }
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
}//solo leemos el cupo actual de la clase de interes

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

    }//segun la eleccion 2(eleccion de la clase) guardamos el nombre correspondiente en un auxiliar

    unsigned int cant_horarios=0;
    string* mishorarios=nullptr;

    for(unsigned int i=0;i<cant_clases;i++){
        if(misclases[i].nombre==claseElegida.nombre){
            ResizeHorarios(cant_horarios,mishorarios);
            mishorarios[cant_horarios-1]=misclases[i].horario;
        }
    }//guardamos en un array todos los horarios que le correspondan a la clase elegida
    for(unsigned int j=0;j<cant_horarios;j++){
        if(j==eleccion3-1){
            claseElegida.horario=mishorarios[j];
        }
    }//como la cantidad y el orden de los horarios es igual a la que mostramos en pantalla al usuario
    //cuando coincida la posicion con eleccion3-1, guardamos en el aux.
    //eleccion3-1 porque en pantalla se imprime a partir del 1

    for(unsigned int i=0;i<cant_clases;i++){
        if(misclases[i].nombre==claseElegida.nombre&&misclases[i].horario==claseElegida.horario)
            claseElegida.idclase= misclases[i].idclase;
    }
    delete[]mishorarios;
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

    delete[]asist;

    asist = temporal;
}
void reducirMemoria(unsigned int&tam, Asistencia*& asistencias){
    Asistencia* temporal = new Asistencia[--tam];

    for(unsigned int i = 0; i < tam; i++){
        temporal[i] = asistencias[i];}

    delete[]asistencias;

    asistencias = temporal;
}
