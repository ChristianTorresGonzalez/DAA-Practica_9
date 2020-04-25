/**
  * @copyright Universidad de La Laguna
  * @copyright Escuela Superior de Ingeniería y Tecnología
  * @copyright Grado en Ingeniería Informática
  * @copyright Asignatura: Diseño y Analisis de Algoritmos (DAA)
  * @copyright Curso: 3º Itinerario 1
  * @copyright Práctica 8. Algoritmos 
  * @author: Christian Torres Gonzalez alu0101137902@ull.edu.es
  * @description: Fichero de la clase gestora, encargada de leer los
  * datos del archivo, tratarlos, almacenarlos y pasarselos al grafo
  * que se utilizara para la resolucion de los algoritmos
  * @since 23/04/2020 
  * @file Fichero de implementacion de la clase Gestora
  * @version 1.0.0
  * @see https://github.com/ChristianTorresGonzalez/DAA_P8.git
*/

#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "./algoritmos.h"

class Algoritmo_Nuevo_ : public Algoritmos_
{
    private:
        vector<Nodo_> vector_solucion;

    public:
        Algoritmo_Nuevo_(Grafo_ );

        void resolver_algoritmo(void);
        
        Arista_ calcular_arista_maxima(void);
        float calcular_dispersion_media(vector<Nodo_> );
        float calcular_dispersion_maxima(vector<Nodo_> &, float );

        bool comparar_vectores(vector<Nodo_> , vector<Nodo_> );

        void imprimir_solucion(void);
};