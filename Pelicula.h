/*
Autor: Vera Sofía Acevedo Gómez A01747156
Declara la clase derivada Pelicula 
*/

#ifndef PELICULA_H
#define PELICULA_H

#include "Video.h"
#include <string>
#include <vector>
using namespace std;

//Clase Pelicula hereda de clase Video
class Pelicula : public Video {
public:
    //Constructor 
    Pelicula(string, string, string, string, float, string);
    //Sobreescribe método de clase base
    void getInfo();
};

#endif