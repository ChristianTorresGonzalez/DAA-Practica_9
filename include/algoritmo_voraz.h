/**
  * @copyright Universidad de La Laguna
  * @copyright Escuela Superior de Ingeniería y Tecnología
  * @copyright Grado en Ingeniería Informática
  * @copyright Asignatura: Diseño y Analisis de Algoritmos (DAA)
  * @copyright Curso: 3º Itinerario 1
  * @copyright Práctica 8. Algoritmos 
  * @author: Christian Torres Gonzalez alu0101137902@ull.edu.es
  * @description: Fichero de la clase Algoritmo_Voraz_, encargada de 
  * implementar el codigo que resuelve el problema de la maxima dispersion
  * media utilizando la tecnica de Algoritmo Voraz
  * @since 23/04/2020 
  * @file Fichero de implementacion de la clase Algoritmo_Voraz_
  * @version 1.0.0
  * @see https://github.com/ChristianTorresGonzalez/DAA_P8.git
*/

#pragma once

#include <iostream>
#include <vector>

#include "./algoritmos.h"

class Algoritmo_Voraz_ : public Algoritmos_
{
    private:
        vector<Nodo_> vector_inicial;

    public:
        Algoritmo_Voraz_(Grafo_ );

        void resolver_algoritmo(int );
        
        float calcular_dispersion_maxima();
        int calcular_posicion(Nodo_ , vector<Nodo_> );

        void imprimir_soluciones(void);
};