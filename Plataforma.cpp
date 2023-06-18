/*
Autor: Vera Sofía Acevedo Gómez A01747156
Declara los métodos de la clase Plataforma
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Pelicula.h"
#include "Video.h"
#include "Episodio.h"
#include "Plataforma.h"
#define ARCHIVO "DatosPeliculas.csv"

// Fimra del método separar la tokenizar el flujo de datos
vector<string> separar(string linea);

// Constructor default
Plataforma::Plataforma()
{
}

// Lee el archivo
void Plataforma::leerPeliculas()
{
    ifstream entrada;
    entrada.open(ARCHIVO);
    string linea;

    // Contador para saltar la primera linea de datos del archivo
    int saltaLinea = 1;

    while (getline(entrada, linea))
    {
        if (saltaLinea > 1)
        {
            vector<string> datos = separar(linea);
            // De acuerdo al número de datos en el vector datos, crea Episodios o Series
            if (datos.size() == 6)
            {
                // Crea objetos de memoria de la clase Pelicula
                Pelicula *pelicula = new Pelicula(datos[0], datos[1], datos[2], datos[3], stod(datos[4]), datos[5]);
                peliculas.push_back(pelicula);
            }
            else if (datos.size() == 10)
            {
                // Crea objetos de memoria de la clase Episodio
                Episodio *episodio = new Episodio(datos[0], datos[1], datos[2], datos[3], stod(datos[4]), datos[5], datos[6], datos[7], datos[8], datos[9]);
                episodios.push_back(episodio);
            }
        }
        saltaLinea++;
    }

    entrada.close();
}

// Método para filtrar videos por calificación
void Plataforma::videosCal(double filCalif)
{
    for (int i = 0; i < peliculas.size(); i++)
    {
        if (peliculas[i]->getCalificacion() >= filCalif)
        {
            peliculas[i]->getInfo();
        }
    }
    for (int i = 0; i < episodios.size(); i++)
    {
        if (episodios[i]->getCalificacion() >= filCalif)
        {
            episodios[i]->getInfo();
        }
    }
}

// Método para filtrar videos por género
void Plataforma::videosGen(string gen)
{
    for (int i = 0; i < peliculas.size(); i++)
    {
        if (peliculas[i]->getGenero() == gen)
        {
            peliculas[i]->getInfo();
        }
    }
    for (int i = 0; i < episodios.size(); i++)
    {
        if (episodios[i]->getGenero() == gen)
        {
            episodios[i]->getInfo();
        }
    }
}

// Método para mostrar episodios por serie
void Plataforma::mostrarExS(string seri)
{
    for (int i = 0; i < episodios.size(); i++)
    {
        if (episodios[i]->getNombre() == seri)
        {
            episodios[i]->getInfo();
        }
    }
}

// Filtra la pelicula de acuerdo a su calificación
void Plataforma::filtrarPeliCal(double cal)
{
    for (int i = 0; i < peliculas.size(); i++)
    {
        if (peliculas[i]->getCalificacion() >= cal)
        {
            peliculas[i]->getInfo();
        }
    }
}

// Muestra los episodios de la serie que el usuario teclee
void Plataforma::mostrarEpi(string seri)
{
    for (int i = 0; i < episodios.size(); i++)
    {
        if (episodios[i]->getNombre() == seri)
        {
            episodios[i]->getInfo();
        }
    }
}

// Cambia la calificación de los videos que el usuario teclee
void Plataforma::calificarVid(string vidC, double newC)
{
    for (int i = 0; i < peliculas.size(); i++)
    {
        if (peliculas[i]->getNombre() == vidC)
        {
            cout << "La calificacion anterior era: " << peliculas[i]->getCalificacion() << endl;
            peliculas[i]->setCalificacion(newC);
            cout << "Los datos se actualizaron" << endl;
            peliculas[i]->getInfo();
        }
    }
    for (int i = 0; i < episodios.size(); i++)
    {
        if (episodios[i]->getnombreEp() == vidC)
        {
            cout << "La calificacion anterior era: " << episodios[i]->getCalificacion() << endl;
            episodios[i]->setCalificacion(newC);
            cout << "Los datos se actualizaron" << endl;
            episodios[i]->getInfo();
        }
    }
}

// Muestra el promedio de la serie que teclea el usuario (NO FUNCIONA)
void Plataforma::promedioC(string epProm)
{
    double suma = 0;
    double contador = 0;
    for (int i = 0; i < episodios.size(); i++)
    {
        if (episodios[i]->getNombre() == epProm)
        {
            suma = suma + episodios[i]->getCalificacion();
            contador++;
        }
    }
    double promedio = suma / contador;
    cout << "El promedio de la serie es: " << promedio << endl;
}

// Despliega el menú
void Plataforma::showMenu()
{
    int sel;
    cout << "STREAMING" << endl
         << "-----MENU-----" << endl
         << "Seleccione una opcion" << endl
         << "1. Cargar archivos" << endl
         << "2. Mostrar videos por calificación o género" << endl
         << "3. Mostrar episodios por serie" << endl
         << "4. Mostrar películas por calificacion" << endl
         << "5. Califica un video" << endl
         << "6. Promedio de calificación de una serie" << endl
         << "7. Salir" << endl;
    cin >> sel;

    // Llama a la función leerPeliculas()
    leerPeliculas();

    // Valida selecicón del usuario
    if (sel == 1)
    {
        cout << "El archivo se cargó correctamente" << endl;
    }
    // Mostrar videos por calificación o género
    else if (sel == 2)
    {
        int sele;
        cout << "Filtrar por calificación(1)/Género(2): " << endl;
        cin >> sele;
        if (sele == 1)
        {
            double filCalif;
            cout << "Mostrar videos con calificación mayor a: " << endl;
            cin >> filCalif;
            videosCal(filCalif);
        }
        else if (sele == 2)
        {
            string gen;
            cout << "Teclea el género: " << endl;
            cin >> gen;
            videosGen(gen);
        }
    }
    // Mostrar episodios por serie (NO FUNCIONA)
    else if (sel == 3)
    {
        string seri;
        cout << "Teclea la serie: " << endl;
        cin >> seri;
        mostrarEpi(seri);
    }
    // Mostrar películas por calificacion
    else if (sel == 4)
    {
        double cal;
        cout << "Mostrar películas con calificación mayor a: " << endl;
        cin >> cal;
        filtrarPeliCal(cal);
    }
    // Califica un video
    else if (sel == 5)
    {
        // No funciona para episodio
        double newC;
        string vidC;
        cout << "Teclea el video al que quieres cambiar calificación: " << endl;
        cin >> vidC;
        cout << "¿Cuál es la nueva calificación? (Calificacion entre 1 y 7)" << endl;
        cin >> newC;
        if (newC > 1 && newC < 7)
        {
            calificarVid(vidC, newC);
        }
        else
        {
            cout << "Calificación inválida" << endl;
        }
    }
    // Promedio de calificación de una serie (No devuelve promedio)
    else if (sel == 6)
    {
        string serieProm;
        cout << "De qué serie quieres obtener la calificación promedio: " << endl;
        cin >> serieProm;
        promedioC(serieProm);
    }
    // Salida
    else if (sel == 7)
    {
        cout << "Vuelve pronto" << endl;
    }
    else
    {
        cout << "Invalido" << endl;
    }
}

vector<string> separar(string linea)
{
    // Componentes de la línea
    vector<string> tokens;
    // Flujo de datos de string
    stringstream entrada(linea);
    // Tokenizar
    string dato;
    while (getline(entrada, dato, ','))
    {
        if (dato != "" && dato != "\n" && dato != "\r")
        {
            // guarda en el vector
            tokens.push_back(dato);
        }
    }
    // Regresa vector de tokens
    return tokens;
}
