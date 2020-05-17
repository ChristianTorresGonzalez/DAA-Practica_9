/**
  * @copyright Universidad de La Laguna
  * @copyright Escuela Superior de Ingeniería y Tecnología
  * @copyright Grado en Ingeniería Informática
  * @copyright Asignatura: Diseño y Analisis de Algoritmos (DAA)
  * @copyright Curso: 3º Itinerario 1
  * @copyright Práctica 8. Algoritmos 
  * @author: Christian Torres Gonzalez alu0101137902@ull.edu.es
  * @description: Fichero de la clase Algoritmo_GRASP_, encargada de 
  * implementar el codigo que resuelve el problema
  * @since 23/04/2020 
  * @file Fichero de implementacion de la clase Algoritmo_GRASP_
  * @version 1.0.0
  * @see https://github.com/ChristianTorresGonzalez/DAA_P8.git
*/

#pragma once

#include <iostream>
#include <vector>

#include "./algoritmos.h"

class Algoritmo_GRASP_ : public Algoritmos_
{
    private:
        int iteraciones;
        int size_lrc;
        vector<Nodo_> vector_inicial;
        vector<Nodo_> lrc;

    public:
        Algoritmo_GRASP_(Grafo_ , int , int , int );

        void resolver_algoritmo(int );
        void preprocesamiento(int );
        void fase_constructiva(Nodo_ &);
        bool post_procesamiento(Nodo_ &);
        void actualizar_solucion();

        vector<Nodo_> resolver_algoritmo(vector<Nodo_> &, int metodo);
        void fase_constructiva_multiarranque(Nodo_ &);
        bool post_procesamiento_multiarranque(Nodo_ &);
};