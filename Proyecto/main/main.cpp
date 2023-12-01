#include<limits>
#include "archivos.h"
#include "menu.h"
#include "Funciones.h"

int main() {
//    ---declaracion de variables--//
    unsigned int cupomax[7] = {45, 25, 15, 40, 50, 30,35};
    unsigned int cant_clases=0;
    unsigned int cant_clientes=0;
    unsigned int idcliente;
    unsigned int cant_asistencias=0;
    Asistencia *asistencias= new Asistencia;
    Clases* misclases=nullptr;
    Clientes* misclientes=nullptr;

//    --apertura de archivos---//
    ifstream archivo;
    archivo.open("C:/Qt/clasesGYM.csv",ios::in); //archivo csv clases
    lecturaClases(archivo,misclases,cant_clases);
    archivo.close();
    archivo.open("c:/Qt/clientesGYM.csv",ios::in); //archivo csv binario
    lecturaClientes(archivo,misclientes,cant_clientes);
    archivo.close();


    //----Guardamos datos en Asistencias----//

     int cantAsistencias = 45;
    Asistencia dummyAsistencias[cantAsistencias];


    for (int i = 0; i < cantAsistencias; i++) {
        dummyAsistencias[i].idCliente = i+1;
        dummyAsistencias[i].cantInscriptos =4;
        dummyAsistencias[i].CursosInscriptos = new Inscripcion[dummyAsistencias[i].cantInscriptos];

        for (unsigned int j = 0; j < dummyAsistencias[i].cantInscriptos; j++) {
            dummyAsistencias[i].CursosInscriptos[j].idClase=4;
            dummyAsistencias[i].CursosInscriptos[j].fechaInscripcion=time(NULL);

        }

    }

    ofstream Earchibinr("archivito.dat", ios::binary);//Escribimos archivo con datos x
    if(Earchibinr.is_open()) {
        for (int i=0; i<cantAsistencias; i++) {
            Earchibinr.write((char*)&dummyAsistencias[i].idCliente, sizeof(unsigned int));
            Earchibinr.write((char*)&dummyAsistencias[i].cantInscriptos, sizeof(unsigned int));
            for(unsigned int j = 0; j < dummyAsistencias[i].cantInscriptos; j++) {
                Earchibinr.write((char*)&dummyAsistencias[i].CursosInscriptos[j],sizeof(Inscripcion));
            }
        }/*cout<<"se escribio archivo"<<endl;*/
    }
    Earchibinr.close();




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
                ifstream archivob("archivito.dat", ios::binary);
                cant_asistencias= lecturaAsistenciaB(archivob,asistencias);

                archivob.close();

                unsigned int eleccion1=0;
                bool continuar;


                do{

                    continuar=false;
                    //-----------
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

                            if(cin.fail()||eleccion2>8){
                                LimpiarBuffer();
                                eleccion2=0;
                            }
                            else{
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
                                        Clases aux= DevolverClase(misclases,cant_clases,eleccion2,eleccion3);
                                        cout<<"Usted eligio:"<<aux.idclase<<","<<aux.nombre<<" "<<aux.horario<<"hs"<<endl;
                                        if(!ClasesRepetidas(asistencias,cant_asistencias,aux.idclase,idcliente)){
                                            unsigned int cupoActual=cupoactual(asistencias,aux.idclase,cant_asistencias);
                                            if(HayCupo(eleccion2,cupoActual,cupomax)){
                                                inscribir(asistencias,cant_asistencias,aux.idclase,idcliente);
//                                                 ofstream nuevoArchivo("archivito.dat", ios::binary);
//                                                 EscrituraBinario(nuevoArchivo,asistencias,cant_asistencias);
                                                cout<<"Su clase se agrego exitosamente\n"<<endl;


                                                 continuar=true;

                                            }else{
                                                cout<<"Ya no hay cupo en esta clase\n"<<endl;
                                                 continuar=true;
                                            }

                                        }else{
                                            cout<<"Usted ya esta anotado en esta clase\n"<<endl;
                                            continuar=true;

                                        }



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
                }while(!(cin.fail())&&eleccion1==0||continuar);

            }
            case 5:{//viernes
                //--abrimos el archivo de clases del dia viernes y lo leemos---//
                ifstream archivob("archivito.dat", ios::binary);
                cant_asistencias= lecturaAsistenciaB(archivob,asistencias);

                archivob.close();

                unsigned int eleccion1=0;
                bool continuar,atras,atras2;


                do{
                    continuar=false;
                    atras=false;
                    //-----------
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


                            if(cin.fail()||eleccion2>8){
                                LimpiarBuffer();
                                eleccion2=0;

                            }
//
                            else{
                                if(eleccion2==8){
                                eleccion2=0;
                                atras=true;
                                break;
                                }

                                int cont=0;
                                int eleccion3=0;
                                do{
                                atras2=false;

                                menuHorarios(misclases,cont,cant_clases,eleccion2);
                                cin>>eleccion3;

                                if(cin.fail()||eleccion3>cont){
                                        LimpiarBuffer();
                                        eleccion3=0;
                                        cont=0;
                                }

                                else{
                                        if(eleccion3==cont){
                                            cont=0;
                                            eleccion3=0;
                                            atras2=true;
                                            break;
                                        }
                                        Clases aux= DevolverClase(misclases,cant_clases,eleccion2,eleccion3);
                                        cout<<"Usted eligio:"<<aux.idclase<<","<<aux.nombre<<" "<<aux.horario<<"hs"<<endl;
                                        if(!ClasesRepetidas(asistencias,cant_asistencias,aux.idclase,idcliente)){
                                            unsigned int cupoActual=cupoactual(asistencias,aux.idclase,cant_asistencias);
                                            if(HayCupo(eleccion2,cupoActual,cupomax)){
                                                 inscribir(asistencias,cant_asistencias,aux.idclase,idcliente);
                                                 ofstream nuevoArchivo("archivito.dat", ios::binary);
                                                 EscrituraBinario(nuevoArchivo,asistencias,cant_asistencias);
                                                 cout<<"Su clase se agrego exitosamente\n"<<endl;


                                                 continuar=true;

                                            }else{
                                                 cout<<"Ya no hay cupo en esta clase\n"<<endl;
                                                 continuar=true;
                                            }

                                        }else{
                                            cout<<"Usted ya esta anotado en esta clase\n"<<endl;
                                            continuar=true;

                                        }



                                }
                                } while(!(cin.fail())&&eleccion3==0);

                            }

                            }while(!(cin.fail())&&eleccion2==0||atras2);
                            break;
                        }
                        case 2:{// ver mis clases
                            VermisClases(asistencias,misclases,cant_asistencias,cant_clases,idcliente);
                            cout<<"\n";

                            continuar=true;
                            eleccion1=0;
                            break;


                        }
                        case 3:break;
                        }

                    }
                }while(!(cin.fail())&&eleccion1==0||continuar||atras);

            }
            case 6:{//sabado

            }


            }

        }

        }while(cin.fail()||!BuscarCliente(misclientes,idcliente,cant_clientes));















 return 0;

}

