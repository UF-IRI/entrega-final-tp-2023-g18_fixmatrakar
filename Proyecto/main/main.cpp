#include<limits>
#include "archivos.h"
#include "menu.h"

int main() {
    //---declaracion de variables--//
    unsigned int cant_clases=0;
    unsigned int cant_clientes=0;
    unsigned int idcliente;
    Clases* misclases=nullptr;
    Clientes* misclientes=nullptr;

    //--apertura de archivos---//
    ifstream archivo;
    archivo.open("C:/Qt/clasesGYM.csv",ios::in); //archivo csv clases
    lecturaClases(archivo,misclases,cant_clases);
    archivo.close();
    archivo.open("c:/Qt/clientesGYM.csv",ios::in); //archivo csv binario
    lecturaClientes(archivo,misclientes,cant_clientes);
    archivo.close();


    //----Guardamos datos en Asistencias----//

    const int cantAsistencias = 2;
    Asistencia dummyAsistencias[cantAsistencias];

    for (int i = 0; i < cantAsistencias; i++) {
        dummyAsistencias[i].idCliente = i + 1;//id consecuente
        dummyAsistencias[i].cantInscriptos = 3; // creo 3 inscripciones
        dummyAsistencias[i].CursosInscriptos = new Inscripcion[dummyAsistencias[i].cantInscriptos];

        for (unsigned int j = 0; j < dummyAsistencias[i].cantInscriptos; j++) {
            dummyAsistencias[i].CursosInscriptos[j].idClase=1;
            dummyAsistencias[i].CursosInscriptos[j].fechaInscripcion=time(NULL);

        }

    }
    //menu//

    do{
        cout<<"--------GIMNASIO MUSCULITO----------"<<endl;
        cout<<"Ingrese su id:"<<endl;
        cin>>idcliente;
        if(cin.fail())// si no ingresa un numero
            LimpiarBuffer();

        if(!BuscarCliente(misclientes,idcliente,cant_clientes)){
            cout<<"Su id no es valido o su cuota esta impaga. Vuelva a intentarlo o comuniquese con el gimnasio"<<endl;
        } else{ int dia=diaDeHoy();
            clienteNombre(misclientes,cant_clientes,idcliente);
            switch (dia) {
            case 0:{//domingo


            }
            case 1:{//lunes

            }
            case 2:{//martes

            }
            case 3:{//miercoles

            }
            case 4:{//jueves
                //--abrimos el archivo de clases del dia viernes y lo leemos---//
                unsigned int eleccion1=0;
                do{

                    menuOpciones();
                    cin>>eleccion1;
                    if(cin.fail()||eleccion1>3){
                        LimpiarBuffer();
                        eleccion1=0;
                    }else{
                        switch(eleccion1){
                        case 1:{//anotarse
                            int eleccion2=0;
                            do{
                            menuClases(misclases,cant_clases);
                            cin>>eleccion2;
                            if(cin.fail()||eleccion2>7){
                                LimpiarBuffer();
                                eleccion2=0;
                            }else{
                                int cont=0;
                                int eleccion3=0;
                                do{
                                menuHorarios(misclases,cont,cant_clases,eleccion2);
                                    cin>>eleccion3;
                                if(cin.fail()||eleccion3>cont){
                                        LimpiarBuffer();
                                        eleccion3=0;
                                        cont=0;
                                    }
                                else{
                                        ClaseSeleccionada aux= DevolverClase(misclases,cant_clases,eleccion1,eleccion2);
                                        cout<<aux.nombre;

                                }
                                } while(!(cin.fail())&&eleccion3==0);
                            }

                            }while(!(cin.fail())&&eleccion2==0);

                        }
                        case 2:{// ver mis clases

                        }
                        case 3:break;
                        }

                    }
                }while(!(cin.fail())&&eleccion1==0);

            }
            case 5:{//viernes

            }
            case 6:{//sabado

            }


            }

        }

        }while(cin.fail()||!BuscarCliente(misclientes,idcliente,cant_clientes));






  return 0;
 }

/*escribo archivito*/

//ofstream Earchibinr("archivito.dat", ios::binary);//Escribimos archivo con datos x
//   if(Earchibinr.is_open()) {
//        for (int i=0; i<cantAsistencias; i++) {
//            Earchibinr.write((char*)&dummyAsistencias[i].idCliente, sizeof(unsigned int));
//            Earchibinr.write((char*)&dummyAsistencias[i].cantInscriptos, sizeof(unsigned int));
//            for(unsigned int j = 0; j < dummyAsistencias[i].cantInscriptos; j++) {
//            Earchibinr.write((char*)&dummyAsistencias[i].CursosInscriptos[j],sizeof(Inscripcion));}}cout<<"se escribio archivo";}
// Earchibinr.close();

//   /*-----------------Leo archivito.dat-------------*/
// ifstream Larchibinr("archivodemierda.dat", ios::binary);
// unsigned int cant=0;
// Asistencia *lectura=nullptr;
// cant= leerArchivoAsistenciaB(Larchibinr,lectura);
// cout<<cant;
