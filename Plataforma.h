/*
Autor: Vera Sofía Acevedo Gómez A01747156
Declara la clase Plataforma
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Pelicula.h"
#include "Video.h"
//#include "Episodio.h"
using namespace std;

#ifndef PLATAFORMA_H
#define PLATAFORMA_H

class Plataforma{
    private: 
    //Vector de tipo apuntador de Pelicula
    vector<Pelicula*> peliculas;
    //vector<Episodio*> episodios;
    public:
    //Constructor default
    Plataforma();
    //Métodos
    void leerPeliculas();
    void filtrarPeliCal(float cal);
    void mostrarEpi(string ser);
    void calificarPeli(string peli, float ncal);
    void showMenu();
};

#endif