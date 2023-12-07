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
    Asistencia *asistencias= nullptr;
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
                            unsigned  int eleccion2=0;

                            do{

                                menuClases(misclases,cant_clases);
                                cin>>eleccion2;


                                if(cin.fail()||eleccion2>8||eleccion2<1){
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
                                    unsigned int eleccion3=0;
                                    do{
                                        atras2=false;

                                        menuHorarios(misclases,cont,cant_clases,eleccion2);
                                        cin>>eleccion3;

                                        if(cin.fail()||eleccion3>cont||eleccion3<1){
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
                                            Clases ClaseE= DevolverClase(misclases,cant_clases,eleccion2,eleccion3);
                                            cout<<"Usted eligio:"<<ClaseE.idclase<<","<<ClaseE.nombre<<" "<<ClaseE.horario<<"hs"<<endl;
                                            if(HorarioRepetido(asistencias,misclases,cant_asistencias,ClaseE,cant_clases,idcliente)&&!ClasesRepetidas(asistencias,cant_asistencias,ClaseE.idclase,idcliente)){
                                                cout<<"Ya tiene una clase registrada en ese horario\n"<<endl;
                                                continuar=true;
                                            }else{
                                                if(!ClasesRepetidas(asistencias,cant_asistencias,ClaseE.idclase,idcliente)){
                                                    unsigned int cupoActual=cupoactual(asistencias,ClaseE.idclase,cant_asistencias);
                                                    if(HayCupo(eleccion2,cupoActual,cupomax)){
                                                        inscribir(asistencias,cant_asistencias,ClaseE.idclase,idcliente);
                                                        ofstream nuevoArchivo("archivito.dat", ios::binary);
                                                        EscrituraBinario(nuevoArchivo,asistencias,cant_asistencias);
                                                        cout<<"Su clase se agrego exitosamente\n"<<endl;
                                                        nuevoArchivo.close();



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


                break;
            }
            case 1:{//lunes
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
                            unsigned  int eleccion2=0;

                            do{

                                menuClases(misclases,cant_clases);
                                cin>>eleccion2;


                                if(cin.fail()||eleccion2>8||eleccion2<1){
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
                                    unsigned int eleccion3=0;
                                    do{
                                        atras2=false;

                                        menuHorarios(misclases,cont,cant_clases,eleccion2);
                                        cin>>eleccion3;

                                        if(cin.fail()||eleccion3>cont||eleccion3<1){
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
                                            Clases ClaseE= DevolverClase(misclases,cant_clases,eleccion2,eleccion3);
                                            cout<<"Usted eligio:"<<ClaseE.idclase<<","<<ClaseE.nombre<<" "<<ClaseE.horario<<"hs"<<endl;
                                            if(HorarioRepetido(asistencias,misclases,cant_asistencias,ClaseE,cant_clases,idcliente)&&!ClasesRepetidas(asistencias,cant_asistencias,ClaseE.idclase,idcliente)){
                                                cout<<"Ya tiene una clase registrada en ese horario\n"<<endl;
                                                continuar=true;
                                            }else{
                                                if(!ClasesRepetidas(asistencias,cant_asistencias,ClaseE.idclase,idcliente)){
                                                    unsigned int cupoActual=cupoactual(asistencias,ClaseE.idclase,cant_asistencias);
                                                    if(HayCupo(eleccion2,cupoActual,cupomax)){
                                                        inscribir(asistencias,cant_asistencias,ClaseE.idclase,idcliente);
                                                        ofstream nuevoArchivo("archivito.dat", ios::binary);
                                                        EscrituraBinario(nuevoArchivo,asistencias,cant_asistencias);
                                                        cout<<"Su clase se agrego exitosamente\n"<<endl;
                                                        cout<<cant_asistencias<<endl;
                                                        nuevoArchivo.close();

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



                break;
            }
            case 2:{//martes
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
                            unsigned  int eleccion2=0;

                            do{

                                menuClases(misclases,cant_clases);
                                cin>>eleccion2;


                                if(cin.fail()||eleccion2>8||eleccion2<1){
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
                                    unsigned int eleccion3=0;
                                    do{
                                        atras2=false;

                                        menuHorarios(misclases,cont,cant_clases,eleccion2);
                                        cin>>eleccion3;

                                        if(cin.fail()||eleccion3>cont||eleccion3<1){
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
                                            Clases ClaseE= DevolverClase(misclases,cant_clases,eleccion2,eleccion3);
                                            cout<<"Usted eligio:"<<ClaseE.idclase<<","<<ClaseE.nombre<<" "<<ClaseE.horario<<"hs"<<endl;
                                            if(HorarioRepetido(asistencias,misclases,cant_asistencias,ClaseE,cant_clases,idcliente)&&!ClasesRepetidas(asistencias,cant_asistencias,ClaseE.idclase,idcliente)){
                                                cout<<"Ya tiene una clase registrada en ese horario\n"<<endl;
                                                continuar=true;
                                            }else{
                                                if(!ClasesRepetidas(asistencias,cant_asistencias,ClaseE.idclase,idcliente)){
                                                    unsigned int cupoActual=cupoactual(asistencias,ClaseE.idclase,cant_asistencias);
                                                    if(HayCupo(eleccion2,cupoActual,cupomax)){
                                                        inscribir(asistencias,cant_asistencias,ClaseE.idclase,idcliente);
                                                        ofstream nuevoArchivo("archivito.dat", ios::binary);
                                                        EscrituraBinario(nuevoArchivo,asistencias,cant_asistencias);
                                                        cout<<"Su clase se agrego exitosamente\n"<<endl;
                                                        cout<<cant_asistencias<<endl;
                                                        nuevoArchivo.close();


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


                break;
            }
            case 3:{//miercoles
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
                            unsigned  int eleccion2=0;

                            do{

                                menuClases(misclases,cant_clases);
                                cin>>eleccion2;


                                if(cin.fail()||eleccion2>8||eleccion2<1){
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
                                    unsigned int eleccion3=0;
                                    do{
                                        atras2=false;

                                        menuHorarios(misclases,cont,cant_clases,eleccion2);
                                        cin>>eleccion3;

                                        if(cin.fail()||eleccion3>cont||eleccion3<1){
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
                                            Clases ClaseE= DevolverClase(misclases,cant_clases,eleccion2,eleccion3);
                                            cout<<"Usted eligio:"<<ClaseE.idclase<<","<<ClaseE.nombre<<" "<<ClaseE.horario<<"hs"<<endl;
                                            if(HorarioRepetido(asistencias,misclases,cant_asistencias,ClaseE,cant_clases,idcliente)&&!ClasesRepetidas(asistencias,cant_asistencias,ClaseE.idclase,idcliente)){
                                                cout<<"Ya tiene una clase registrada en ese horario\n"<<endl;
                                                continuar=true;
                                            }else{
                                                if(!ClasesRepetidas(asistencias,cant_asistencias,ClaseE.idclase,idcliente)){
                                                    unsigned int cupoActual=cupoactual(asistencias,ClaseE.idclase,cant_asistencias);
                                                    if(HayCupo(eleccion2,cupoActual,cupomax)){
                                                        inscribir(asistencias,cant_asistencias,ClaseE.idclase,idcliente);
                                                        ofstream nuevoArchivo("archivito.dat", ios::binary);
                                                        EscrituraBinario(nuevoArchivo,asistencias,cant_asistencias);
                                                        cout<<"Su clase se agrego exitosamente\n"<<endl;
                                                        cout<<cant_asistencias<<endl;
                                                        nuevoArchivo.close();


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



                break;
            }
            case 4:{//jueves
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
                            unsigned  int eleccion2=0;

                            do{

                                menuClases(misclases,cant_clases);
                                cin>>eleccion2;


                                if(cin.fail()||eleccion2>8||eleccion2<1){
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
                                    unsigned int eleccion3=0;
                                    do{
                                        atras2=false;

                                        menuHorarios(misclases,cont,cant_clases,eleccion2);
                                        cin>>eleccion3;

                                        if(cin.fail()||eleccion3>cont||eleccion3<1){
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
                                            Clases ClaseE= DevolverClase(misclases,cant_clases,eleccion2,eleccion3);
                                            cout<<"Usted eligio:"<<ClaseE.idclase<<","<<ClaseE.nombre<<" "<<ClaseE.horario<<"hs"<<endl;
                                            if(HorarioRepetido(asistencias,misclases,cant_asistencias,ClaseE,cant_clases,idcliente)&&!ClasesRepetidas(asistencias,cant_asistencias,ClaseE.idclase,idcliente)){
                                                cout<<"Ya tiene una clase registrada en ese horario\n"<<endl;
                                                continuar=true;
                                            }else{
                                                if(!ClasesRepetidas(asistencias,cant_asistencias,ClaseE.idclase,idcliente)){
                                                    unsigned int cupoActual=cupoactual(asistencias,ClaseE.idclase,cant_asistencias);
                                                    if(HayCupo(eleccion2,cupoActual,cupomax)){
                                                        inscribir(asistencias,cant_asistencias,ClaseE.idclase,idcliente);
                                                        ofstream nuevoArchivo("archivito.dat", ios::binary);
                                                        EscrituraBinario(nuevoArchivo,asistencias,cant_asistencias);
                                                        cout<<"Su clase se agrego exitosamente\n"<<endl;
                                                        cout<<cant_asistencias<<endl;
                                                        nuevoArchivo.close();


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



                break;

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
                            unsigned  int eleccion2=0;

                            do{

                                menuClases(misclases,cant_clases);
                                cin>>eleccion2;


                                if(cin.fail()||eleccion2>8||eleccion2<1){
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
                                    unsigned int eleccion3=0;
                                    do{
                                        atras2=false;

                                        menuHorarios(misclases,cont,cant_clases,eleccion2);
                                        cin>>eleccion3;

                                        if(cin.fail()||eleccion3>cont||eleccion3<1){
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
                                            Clases ClaseE= DevolverClase(misclases,cant_clases,eleccion2,eleccion3);
                                            cout<<"Usted eligio:"<<ClaseE.idclase<<","<<ClaseE.nombre<<" "<<ClaseE.horario<<"hs"<<endl;
                                            if(HorarioRepetido(asistencias,misclases,cant_asistencias,ClaseE,cant_clases,idcliente)&&!ClasesRepetidas(asistencias,cant_asistencias,ClaseE.idclase,idcliente)){
                                                cout<<"Ya tiene una clase registrada en ese horario\n"<<endl;
                                                continuar=true;
                                            }else{
                                                if(!ClasesRepetidas(asistencias,cant_asistencias,ClaseE.idclase,idcliente)){
                                                    unsigned int cupoActual=cupoactual(asistencias,ClaseE.idclase,cant_asistencias);
                                                    if(HayCupo(eleccion2,cupoActual,cupomax)){
                                                        inscribir(asistencias,cant_asistencias,ClaseE.idclase,idcliente);
                                                        ofstream nuevoArchivo("archivito.dat", ios::binary);
                                                        EscrituraBinario(nuevoArchivo,asistencias,cant_asistencias);
                                                        cout<<"Su clase se agrego exitosamente\n"<<endl;
                                                        cout<<cant_asistencias<<endl;
                                                        nuevoArchivo.close();


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




                break;
            }
            case 6:{//sabado
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
                          unsigned  int eleccion2=0;

                            do{

                            menuClases(misclases,cant_clases);
                            cin>>eleccion2;


                            if(cin.fail()||eleccion2>8||eleccion2<1){
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
                                unsigned int eleccion3=0;
                                do{
                                atras2=false;

                                menuHorarios(misclases,cont,cant_clases,eleccion2);
                                cin>>eleccion3;

                                if(cin.fail()||eleccion3>cont||eleccion3<1){
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
                                        Clases ClaseE= DevolverClase(misclases,cant_clases,eleccion2,eleccion3);
                                        cout<<"Usted eligio:"<<ClaseE.idclase<<","<<ClaseE.nombre<<" "<<ClaseE.horario<<"hs"<<endl;
                                        if(HorarioRepetido(asistencias,misclases,cant_asistencias,ClaseE,cant_clases,idcliente)&&!ClasesRepetidas(asistencias,cant_asistencias,ClaseE.idclase,idcliente)){
                                            cout<<"Ya tiene una clase registrada en ese horario\n"<<endl;
                                            continuar=true;
                                        }else{
                                        if(!ClasesRepetidas(asistencias,cant_asistencias,ClaseE.idclase,idcliente)){
                                            unsigned int cupoActual=cupoactual(asistencias,ClaseE.idclase,cant_asistencias);
                                            if(HayCupo(eleccion2,cupoActual,cupomax)){
                                                 inscribir(asistencias,cant_asistencias,ClaseE.idclase,idcliente);
                                                 ofstream nuevoArchivo("archivito.dat", ios::binary);
                                                 EscrituraBinario(nuevoArchivo,asistencias,cant_asistencias);
                                                 cout<<"Su clase se agrego exitosamente\n"<<endl;
                                                 cout<<cant_asistencias<<endl;
                                                 nuevoArchivo.close();


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


                break;

            }


            }

        }

        }while(cin.fail()||!BuscarCliente(misclientes,idcliente,cant_clientes));




        delete[]misclases;
        delete[]misclientes;
        for(unsigned int k=0;k<cant_asistencias;k++){
        delete[]asistencias[k].CursosInscriptos;
        }
        delete[]asistencias;


 return 0;

}



