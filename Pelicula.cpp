/*
Autor: Vera Sofía Acevedo Gómez A01747156
Declara los métodos clase derivada Pelicula
*/

#include "Pelicula.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Usa el constructor de la clase base
Pelicula::Pelicula(string id, string nombre, string duracion, string genero, double calificacion, string fecha)
    : Video(id, nombre, duracion, genero, calificacion, fecha)
{
}

// Usa el método de la clase base
void Pelicula::getInfo()
{
    Video::getInfo();
}
