/*
Autor: Vera Sofía Acevedo Gómez A01747156
Declara la clase derivda Episodio
*/
#ifndef EPISODIO_H
#define EPISODIO_H

#include "Video.h"
#include <string>
#include <vector>
using namespace std;

// Clase Episodio hereda de Video
class Episodio : public Video
{
private:
    // Declara atributos únicos en episodios
    string idEp;
    string nombreEp;
    string temporada;
    string numEp;

public:
    // Constructor
    Episodio(string idE, string nombreE, string duracionE, string generoE, double calificacionE,
             string fechaE, string idEpE, string nombreEpE, string temporadaE, string numEpE);
    // get's para nuevos atributos
    string getidEp();
    string getnombreEp();
    string gettemporada();
    string getnumEp();
    void getInfo();
};

#endif