/**
  * @copyright Universidad de La Laguna
  * @copyright Escuela Superior de Ingeniería y Tecnología
  * @copyright Grado en Ingeniería Informática
  * @copyright Asignatura: Diseño y Analisis de Algoritmos (DAA)
  * @copyright Curso: 3º Itinerario 1
  * @copyright Práctica 8. Algoritmos 
  * @author: Christian Torres Gonzalez alu0101137902@ull.edu.es
  * @description: Fichero de la clase Algoritmo_BusquedaLocal_, encargada de 
  * implementar el codigo que resuelve el problema
  * @since 23/04/2020 
  * @file Fichero de implementacion de la clase Algoritmo_BusquedaLocal_
  * @version 1.0.0
  * @see https://github.com/ChristianTorresGonzalez/DAA_P8.git
*/

#pragma once

#include <iostream>
#include <vector>

#include "./algoritmos.h"

class Algoritmo_Busqueda_Tabu_ : public Algoritmos_
{
    private:
        int iteraciones;
        int tiempo_tabu;
        vector<Nodo_> vector_inicial;

    public:
        Algoritmo_Busqueda_Tabu_(Grafo_ , int , int );

        void resolver_algoritmo(int );

        void preprocesamiento(int );
        void fase_constructiva(vector<Nodo_> & );
        void post_procesamiento(vector<Nodo_> & );
        void insertar_nodo(vector<Nodo_> & );
        void actualizar_tiempo_tabu(void);

        void imprimir_soluciones(void);
};