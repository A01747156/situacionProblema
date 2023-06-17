/*
Autor: Vera Sofía Acevedo Gómez A01747156
Declara la superclase Video
*/

#ifndef VIDEO_H
#define VIDEO_H
#include <string>
using namespace std;

class Video
{
private:
    //Declaración de atributos 
    string id;
    string nombre;
    string duracion;
    string genero;
    float calificacion;
    string fecha;

public:
    //Constructor por defecto
    Video();
    //Constructor que inicializa con los datos del Video
    Video(string id, string nombre, string duracion, string genero, float calificacion, string fecha);
    //setCalificación para cambiar la calificación
    void setCalificacion(float);
    //get's devuelven un dato específico
    string getId();
    string getNombre();
    string getDuracion();
    string getGenero();
    float getCalificacion();
    string getFecha();
    //Devuelve los datos con formato
    virtual void getInfo();
};

#endif