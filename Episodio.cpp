/*
Autor: Vera Sofía Acevedo Gómez A01747156
Declara los métodos de la clase Episodio
*/
#include "Episodio.h"
#include <iostream>
using namespace std;

// Constructor de Episodio utiliza el constructor de Video y asigna valores de nuevos atributos a las variables de instancia
Episodio::Episodio(string idE, string nombreE, string duracionE, string generoE, double calificacionE, string fechaE, string idEp,
                   string nombreEp, string temporada, string numEp) : Video(idE, nombreE, duracionE, generoE, calificacionE, fechaE),
                                                                      idEp(idEp), nombreEp(nombreEp), temporada(temporada), numEp(numEp)
{
}

// Métodos get's para regresar datos
string Episodio::getidEp()
{
    return idEp;
}

string Episodio::getnombreEp()
{
    return nombreEp;
}

string Episodio::gettemporada()
{
    return temporada;
}

string Episodio::getnumEp()
{
    return numEp;
}

// Sobreescribe el método getInfo() para imprimir atributos de la clase Episodio
void Episodio::getInfo()
{
    Video::getInfo();
    cout << "ID ep: " << idEp
         << " Nombre Ep: " << nombreEp
         << " Temporada: " << temporada
         << " Numero de episodio: " << numEp << endl;
}