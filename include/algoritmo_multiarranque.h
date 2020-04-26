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
#include "./algoritmo_grasp.h"

class Algoritmo_Multiarranque_ : public Algoritmos_
{
    private:
        float dispersion;

        vector<Nodo_> vector_solucion;

    public:
        Algoritmo_Multiarranque_(Grafo_ );

        void resolver_algoritmo_metodo1(void);
        void resolver_algoritmo_metodo2(void);

        void preprocesamiento_metodo1(vector<Nodo_> &);
        void preprocesamiento_metodo2(vector<Nodo_> &);

        void imprimir_solucion(void);
};