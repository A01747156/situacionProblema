/*
Autor: Vera Sofía Acevedo Gómez A01747156
Declaración de Métodos de clase Video
*/

#include "Video.h"
#include <iostream>
#include <string>
using namespace std;

Video::Video()
{
    //Constructor por defecto de Video
}

Video::Video(string id, string nombre, float duracion, string genero, float calificacion, string fecha)
    : id(id), nombre(nombre), duracion(duracion), genero(genero), calificacion(calificacion), fecha(fecha)
{
    //Constructor con parámetros de Video
}

void Video::setCalificacion(float num)
{
    calificacion = num;
}

std::string Video::getId()
{
    return id;
}

std::string Video::getNombre()
{
    return nombre;
}

float Video::getDuracion()
{
    return duracion;
}

std::string Video::getGenero()
{
    return genero;
}

float Video::getCalificacion()
{
    return calificacion;
}

string Video::getFecha()
{
    return fecha;
}

//Da formato a la salida de información
void Video::getInfo()
{
    std::cout << "ID: " << id << 
    " Nombre: " << nombre 
    << " Duracion: " << duracion 
    << " Genero: " << genero
    << " Calificacion: " << calificacion 
    << " Fecha estreno: " << fecha << endl;
}
