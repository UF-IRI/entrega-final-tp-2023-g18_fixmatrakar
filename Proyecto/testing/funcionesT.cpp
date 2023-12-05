#include <catch2/catch.hpp>
#include "Estructuras.h"
#include "Funciones.h"
#include "menu.h"



//funcion horario repetido
TEST_CASE("true cuando hay un horario repetido", "[HorarioRepetido]") {
    // Datos de prueba
    Inscripcion inscripciones1[2] = {
        {1, time(nullptr)},
        {2, time(nullptr)}

    };
    Asistencia asistencia1 = {1, 2, inscripciones1}; // idCliente = 1, cantInscriptos = 2

    Clases clases[2] = {
        {1, "Clase1", "10"},
        {2, "Clase2", "14"}

    };
    Clases ClaseE = {3, "Clase3", "10"}; // Clase con horario repetido

    unsigned int cant_clases = 2;
    unsigned int idcliente = 1;

    // Llamada a la función
    bool resultado = HorarioRepetido(&asistencia1, clases, 1, ClaseE, cant_clases, idcliente);

    // Verificar el resultado
    REQUIRE(resultado == true);
}
TEST_CASE("devuelve false cuando no hay horario repetido", "[HorarioRepetido]") {
    // Datos de prueba
    Inscripcion inscripciones2[2] = {
        {3, time(nullptr)},
        {4, time(nullptr)}

    };
    Asistencia asistencia2 = {2, 2, inscripciones2}; // idCliente = 2, cantInscriptos = 2

    Clases clases[2] = {
        {1, "Clase1", "10"},
        {2, "Clase2", "14"}

    };
    Clases ClaseE = {3, "Clase3", "12"}; // Clase sin horario repetido

    unsigned int cant_clases = 2;
    unsigned int idcliente = 2;

    // Llamada a la función
    bool resultado = HorarioRepetido(&asistencia2, clases, 1, ClaseE, cant_clases, idcliente);

    // Verificar el resultado
    REQUIRE(resultado == false);
}
//funcion de inscripcion
TEST_CASE("agregar inscripcion para cliente ya existente", "[inscribir]") {
// Datos
Asistencia* asistencias = new Asistencia;
unsigned int cant_asistencias = 1;
asistencias->idCliente = 1;
asistencias->cantInscriptos = 2;
asistencias->CursosInscriptos = new Inscripcion[2];
asistencias->CursosInscriptos[0] = {1, time(nullptr)};
asistencias->CursosInscriptos[1] = {2, time(nullptr)};

unsigned int idclase = 3;
unsigned int idcliente = 1;


inscribir(asistencias, cant_asistencias, idclase, idcliente);

REQUIRE(asistencias->cantInscriptos == 3);
REQUIRE(asistencias->CursosInscriptos[2].idClase == idclase);


for (unsigned int i = 0; i < cant_asistencias; ++i) {
    delete[] asistencias[i].CursosInscriptos;
}
delete[] asistencias;
}

TEST_CASE("agregar inscripcion para nuevo cliente", "[inscribir]") {
// Datos
Asistencia* asistencias = nullptr;
unsigned int cant_asistencias = 0;

unsigned int idclase = 1;
unsigned int idcliente = 2;

// Llamada a la función
inscribir(asistencias, cant_asistencias, idclase, idcliente);


REQUIRE(cant_asistencias == 1);
REQUIRE(asistencias[0].idCliente == idcliente);
REQUIRE(asistencias[0].cantInscriptos == 1);
REQUIRE(asistencias[0].CursosInscriptos[0].idClase == idclase);


delete[] asistencias->CursosInscriptos;
delete[] asistencias;
}

//funcion de devolver clase
TEST_CASE("devuelve la clase según la elección del usuario") {
// Datos de prueba
Clases misclases[] = {
    {1, "Spinning", "10"},
    {2, "Yoga", "14"},
    {3, "Pilates", "18"},
    {4, "Stretching", "17"},
    {5, "Spinning", "12"},
    {6, "Spinning", "19"},
    {7, "Musculacion", "16"}
};
unsigned int cant_clases =7;

unsigned int eleccion2 = 1; // Spinning
unsigned int eleccion3 = 2; // 12hs
// Llamada a la función
Clases claseElegida = DevolverClase(misclases, cant_clases, eleccion2, eleccion3);


REQUIRE(claseElegida.nombre == "Spinning");
REQUIRE(claseElegida.horario == "12");


for (unsigned int i = 0; i < cant_clases; i++) {
if (misclases[i].nombre == claseElegida.nombre && misclases[i].horario == claseElegida.horario) {
    REQUIRE(claseElegida.idclase == misclases[i].idclase);
    break;
}
}
}


//funcion clase repetida

TEST_CASE("true cuando la clase está repetida para un cliente") {

Asistencia asistencias[2] = {
    {1, 2, new Inscripcion[2]{{1, time(nullptr)}, {2, time(nullptr)}}},
    {2, 3, new Inscripcion[3]{{3, time(nullptr)}, {4, time(nullptr)}, {5, time(nullptr)}}}

};
unsigned int cantAsist = 2;

unsigned int idclase = 2;
unsigned int idcliente = 1;


bool resultado = ClasesRepetidas(asistencias, cantAsist, idclase, idcliente);


REQUIRE(resultado == true);


for (unsigned int i = 0; i < cantAsist; ++i) {
delete[] asistencias[i].CursosInscriptos;
}
}

TEST_CASE("false cuando la clase no está repetida") {
// Datos de prueba
Asistencia asistencias[2] = {
    {1, 2, new Inscripcion[2]{{1, time(nullptr)}, {2, time(nullptr)}}},
    {2, 3, new Inscripcion[3]{{3, time(nullptr)}, {4, time(nullptr)}, {5, time(nullptr)}}}

};
unsigned int cantAsist = 2;

unsigned int idclase = 6;
unsigned int idcliente = 1;


bool resultado = ClasesRepetidas(asistencias, cantAsist, idclase, idcliente);


REQUIRE(resultado == false);


for (unsigned int i = 0; i < cantAsist; ++i) {
delete[] asistencias[i].CursosInscriptos;
}
}

//cupo actual

TEST_CASE(" cantidad de inscriptos para una clase") {
// Datos
Asistencia asistencias[2] = {
    {1, 2, new Inscripcion[2]{{1, time(nullptr)}, {2, time(nullptr)}}},
    {2, 3, new Inscripcion[3]{{2, time(nullptr)}, {4, time(nullptr)}, {5, time(nullptr)}}}

};
unsigned int cantAsistencias = 2;

unsigned int idclase = 2;


unsigned int resultado = cupoactual(asistencias, idclase, cantAsistencias);


REQUIRE(resultado == 2);


for (unsigned int i = 0; i < cantAsistencias; i++) {
delete[] asistencias[i].CursosInscriptos;
}
}

//Hay cupo

TEST_CASE("false cuando no hay cupo para la clase elegida") {
// Datos de prueba
unsigned int cupos_maximos[7] = {45, 25, 15, 40, 50, 30,35}; // Cupos máximos para cada clase
unsigned int cupoActual = 50; // Cupo actual
unsigned int eleccion = 5; //Zumba


bool resultado = HayCupo(eleccion, cupoActual, cupos_maximos);


REQUIRE(resultado == false);
}
