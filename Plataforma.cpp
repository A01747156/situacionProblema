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
#include "Plataforma.h"
#define ARCHIVO "DatosPeliculas.csv"
// #include "Episodio.h"

//Fimra del método separar la tokenizar el flujo de datos
vector<string> separar(string linea);

//Constructor default
Plataforma::Plataforma()
{
}

//Lee el archivo
void Plataforma::leerPeliculas()
{
    ifstream entrada;
    entrada.open(ARCHIVO);
    string linea;

    while (getline(entrada, linea))
    {
        vector<string> datos = separar(linea);
        //De acuerdo al número de datos en el vector datos, crea Episodios o Series
        if (datos.size() == 6)
        {
            Pelicula *pelicula = new Pelicula(datos[0], datos[1], (datos[2]), datos[3], stof(datos[4]), datos[5]);
            peliculas.push_back(pelicula);
        }
        else
        {
            // NO FUNCIONA LA CREACIÓN DEL EPISODIO
            // Episodio *episodio = new Episodio(datos[0], datos[1], stof(datos[2]), datos[3], stof(datos[4]), datos[5], datos[6], datos[7], datos[8], datos[9]);
            // episo.push_back(episodio);
        }
        cout << endl;
    }

    entrada.close();
}

//Filtra la la pelicula de acuerdo a su calificación
void Plataforma::filtrarPeliCal(float cal)
{
    for (int i = 0; i < peliculas.size(); i++)
    {
        if (peliculas[i]->getCalificacion() >= cal)
        {
            peliculas[i]->getInfo();
        }
    }
}

//Muestra las películas del género que el usuario teclee
void Plataforma::mostrarEpi(string ser)
{
    for (int i = 0; i < peliculas.size(); i++)
    {
        if (peliculas[i]->getGenero() == ser)
        {
            peliculas[i]->getInfo();
        }
    }
}

//Cambia la calificación de las películas que el usuario teclee
void Plataforma::calificarPeli(string peli, float ncal)
{
    for (int i = 0; i < peliculas.size(); i++)
    {
        if (peliculas[i]->getNombre() == peli)
        {
            cout << "La calificacion anterior era: " << peliculas[i]->getCalificacion() << endl;
            peliculas[i]->setCalificacion(ncal);
            cout << "Los datos se actualizaron" << endl;
            peliculas[i]->getInfo();
        }
    }
}

//Despliega el menú
void Plataforma::showMenu()
{
    int sel;
    cout << "STREAMING" << endl
    << "-----MENU-----" << endl
    << "Seleccione una opcion" << endl
    << "1. Cargar archivos" << endl
    << "2. Mostrar películas de un género" << endl
    << "3. Filtrar película por calificación" << endl
    << "4. Calificar una película" << endl
    << "5. Salir" << endl;
    cin >> sel;

    if (sel == 1)
    {
        leerPeliculas();
        cout << "El archivo se cargó correctamente" << endl;
    }
    else if (sel == 2)
    {
        leerPeliculas();
        string gen;
        cout << "Teclea el género: " << endl;
        cin >> gen;
        Plataforma::mostrarEpi(gen);
    }
    else if (sel == 3)
    {
        leerPeliculas();
        float calif;
        cout << "Mostrar películas con calificación mayor a: (Calificacion entre 1 y 7)" << endl;
        cin >> calif;
        Plataforma::filtrarPeliCal(calif);
    }
    else if (sel == 4)
    {
        leerPeliculas();
        float newC;
        string peliC;
        cout << "Teclea la película a la que quieres cambiar calificación: " << endl;
        cin >> peliC;
        cout << "¿Cuál es la nueva calificación? (Calificacion entre 1 y 7)" << endl;
        cin >> newC;
        if (newC > 1 && newC < 7)
        {
            calificarPeli(peliC, newC);
        } else{
            cout << "Calificación inválida" << endl;
        }
    }
    else if (sel == 5)
    {
        cout << "Vuelve pronto" << endl;
    }
    else{
        cout << "Invalido" << endl;
    }
}

vector<string> separar(string linea)
{
    // Componentes de la línea
    vector<string> tokens;      
    //Flujo de datos de string       
    stringstream entrada(linea);      
    //Tokenizar
    string dato;                        
    while (getline(entrada, dato, ',')) 
    {
        if (dato != "" && dato != "\n" && dato != "\r")
        {
            //guarda en el vector
            tokens.push_back(dato); 
        }
    }
    //Regresa vector de tokens
    return tokens;
}
