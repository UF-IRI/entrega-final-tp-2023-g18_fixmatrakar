#include<limits>
#include "menu.h"
#include "Funciones.h"
#include "archivos.h"

int main() {

    //----variables---//
    Clases* misclases;
    Clientes* misclientes;
    Asistencia* asistencias;

    unsigned int cant_clases=0;
    unsigned int cant_clientes=0;
    unsigned int cant_asistencias=0;
    unsigned int idcliente;
    unsigned int eleccion1=0;
    unsigned int eleccion2=0;
    unsigned int eleccion3=0;

    //----apertura de archivos----//
    ifstream archivo;
    archivo.open("C:/Qt/clasesGYM.csv",ios::in);
    lecturaClases(archivo,misclases,cant_clases);
    archivo.close();
    archivo.open("c:/Qt/clientesGYM.csv",ios::in);
    lecturaClientes(archivo,misclientes,cant_clientes);
    archivo.close();
    archivo.open("c:/Qt/asistenciasGYM.dat",ios::binary);
    archivo.close();



    //------------------main--------------------//
    do{
        cout<<"--------GIMNASIO MUSCULITO----------"<<endl;
        cout<<"Ingrese su id:"<<endl;
        cin>>idcliente;
        if(cin.fail())// si no ingresa un numero
            LimpiarBuffer();

        if(!BuscarCliente(misclientes,idcliente,cant_clientes)){
            cout<<"Su id no es valido o su cuota esta impaga. Vuelva a intentarlo o comuniquese con el gimnasio"<<endl;
        }else{ int dia=diaDeHoy();
            switch(dia){
            case 0:{//domingo

            }
            case 1:{//lunes

            }
            case 2:{//martes

            }
            case 3:{//miercoles

            }
            case 4:{//jueves
                clienteNombre(misclientes,cant_clientes,idcliente);// le damos la bienvenida mostrando su nombre en pantalla
                do{
                    menuOpciones();//le mostramos las opciones
                    cin>>eleccion1;
                    if(cin.fail()||eleccion1>4){
                        LimpiarBuffer();
                        eleccion1=0;
                    }

                    switch(eleccion1){
                    case 1:{//anotarse
                        do{
                            menuClases(misclases,cant_clases);
                            cin>>eleccion2;
                            if(cin.fail()||eleccion2>8){
                                LimpiarBuffer();
                                eleccion2=0;
                            }
                            switch(eleccion2){//segun la clase que elije
                            case 1:{//spinning
                                do{
                                    menuHorarios(misclases,cant_clases,eleccion2);
                                    cin>>eleccion3;
                                    if(cin.fail()||eleccion3>6){
                                        LimpiarBuffer();
                                        eleccion3=0;
                                    }
                                    if(eleccion3==6);
                                    break;

                                }while(!cin.fail()&&eleccion3==0);
                                eleccion2=0;
                                //                    eleccion3=0;
                                break;
                            }

                            case 2:{//yoga
                                menuHorarios(misclases,cant_clases,eleccion2);

                            }
                            case 3:{//pilates
                                menuHorarios(misclases,cant_clases,eleccion2);

                            }
                            case 4:{//stretching
                                menuHorarios(misclases,cant_clases,eleccion2);

                            }
                            case 5:{//zumba
                                menuHorarios(misclases,cant_clases,eleccion2);

                            }
                            case 6:{//boxeo
                                menuHorarios(misclases,cant_clases,eleccion2);

                            }
                            case 7:{//musculacion
                                menuHorarios(misclases,cant_clases,eleccion2);

                            }
                            case 8:{

                                break;
                            }
                            }
                            eleccion1=0;


                        }while(!cin.fail()&&eleccion2==0||eleccion3!=0);

                    }
                    case 2:{//darse de baja

                    }
                    case 3:{//ver mis clases

                    }
                    case 4:{
                        break;
                    }
                    }
                }while(!cin.fail()&&eleccion1==0||eleccion2==8);




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
