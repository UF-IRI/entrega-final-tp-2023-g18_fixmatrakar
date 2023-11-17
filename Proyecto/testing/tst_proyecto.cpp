#include <catch2/catch.hpp>
#include "Funciones.h"
TEST_CASE("Cantidad de cupo")
{
    unsigned int cupos=0;
    Inscripcion inscripcion1 = {1, time(NULL)};
    Inscripcion inscripcion2 = {1, time(NULL)};
    Inscripcion inscripcion3 = {3, time(NULL)};
    Inscripcion inscripcion4 = {4, time(NULL)};
    Inscripcion inscripcion5 = {5, time(NULL)};
    Inscripcion inscripcion6 = {6, time(NULL)};
    Inscripcion inscripciones1[] = {inscripcion1, inscripcion2};
    Inscripcion inscripciones2[] = {inscripcion3, inscripcion4, inscripcion5};
    Inscripcion inscripciones3[] = {inscripcion6};
    Asistencias asistencia[3] = {
        {1, 2, inscripciones1},
        {2, 3, inscripciones2},
        {3, 1, inscripciones3}
    };
    unsigned int idclase=1;
    unsigned int cantAsistencias = 3;
    cupos=cupoactual(asistencia, idclase, cantAsistencias);
    REQUIRE(cupos == 2);
};
