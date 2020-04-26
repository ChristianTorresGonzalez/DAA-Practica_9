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

class Algoritmo_GRASP_ : public Algoritmos_
{
    private:
        int opcion;
        int iteraciones;
        float dispersion;
        int size_lrc;
        vector<Nodo_> vector_solucion;
        vector<Nodo_> lrc;

    public:
        Algoritmo_GRASP_(Grafo_ , int , int , int );

        void resolver_algoritmo(void);
        void preprocesamiento(vector<Nodo_> &);
        void fase_constructiva(Nodo_ &);
        bool post_procesamiento(Nodo_ &, vector<Nodo_> &);
        void actualizar_solucion(vector<Nodo_> &);

        void imprimir_solucion(void);
};