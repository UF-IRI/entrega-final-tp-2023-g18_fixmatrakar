#include <catch2/catch.hpp>
#include "Estructuras.h"
#include "Funciones.h"
#include "menu.h"

//las funciones de menu las corroboramos directamente en el main.

//buscar cliente
TEST_CASE("false cuando no encuentra al cliente o tiene estado negativo") {
    // Datos de prueba
    Clientes misclientes[3] = {
        {1, "Natalia", "Matrakar", "nataliaM@gmail.com", "123456789", " ", 1},
        {2, "Agustina", "Fix", "agustinsfix@hotmail.com", "123456789", " ", 1},
        {3, "Lucila", "Caero", "caero_lucila@gmail.com", "123456789", " ", -3}

    };
    unsigned int cant_clientes =3;

    unsigned int idcliente1 = 4;
    unsigned int idcliente2 = 3;


    bool resultado1 = BuscarCliente(misclientes, idcliente1, cant_clientes);
    bool resultado2 = BuscarCliente(misclientes, idcliente2, cant_clientes);


    REQUIRE(resultado1 == false);
    REQUIRE(resultado2 == false);
}

TEST_CASE("true cuando encuentra al cliente con estado positivo") {
    // Datos de prueba
    Clientes misclientes[3] = {
        {1, "Natalia", "Matrakar", "nataliaM@gmail.com", "123456789", " ", 1},
        {2, "Agustina", "Fix", "agustinsfix@hotmail.com", "123456789", " ", 1},
        {3, "Lucila", "Caero", "caero_lucila@gmail.com", "123456789", " ", 0}
    };
    unsigned int cant_clientes = 3;

    unsigned int idcliente = 3;


    bool resultado = BuscarCliente(misclientes, idcliente, cant_clientes);


    REQUIRE(resultado == true);
}


