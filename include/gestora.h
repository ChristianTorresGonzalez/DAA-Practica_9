/**
  * @copyright Universidad de La Laguna
  * @copyright Escuela Superior de Ingeniería y Tecnología
  * @copyright Grado en Ingeniería Informática
  * @copyright Asignatura: Programación de Aplicaciones Interactivas (PAI)
  * @copyright Curso: 3º Itinerario 1
  * @copyright Práctica 7 PAI - Mandelbrot. Numero complejos
  * @author: Christian Torres Gonzalez alu0101137902@ull.edu.es
  * @description: Programa que dado un lienzo de canvas, va a calcular, dada
  * una coordenada X e Y, que dada un numro de iteraciones, para cada coordenada,
  * y utilizando la función f(Zn) = Z(n-1)^2 + c, donde c es un numero complejo dado,
  * y zn-1 es el resultado de elevar al cuadrado la funcion para valor Zn-1. Para poder
  * llegar a un resultado deseado, debemos partir de la copndicion de que x e y, que son
  * las coordenadas del punto del lienzo de canvas que estamos tratando.
  * @since 28/03/2020 
  * @file Fichero de implementacion de ejercicios
  * @version 1.0.0
  * @see https://github.com/ChristianTorresGonzalez/DAA_P8.git
*/

#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "arista.h"
#include "grafo.h"

using namespace std;

class Gestor_Archivos_
{
    private:
        ifstream archivo1;
        ofstream archivo2;
        vector<Arista_> vector_aristas;

    public:
        Gestor_Archivos_(string ,string ,Grafo_ &);

        void cargar_datos(Grafo_ &);
        void ordenar_aristas(int );
        void mostrar_aristas(void);
};
