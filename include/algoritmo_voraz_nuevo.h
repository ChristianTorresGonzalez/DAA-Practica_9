/**
  * @copyright Universidad de La Laguna
  * @copyright Escuela Superior de Ingeniería y Tecnología
  * @copyright Grado en Ingeniería Informática
  * @copyright Asignatura: Diseño y Analisis de Algoritmos (DAA)
  * @copyright Curso: 3º Itinerario 1
  * @copyright Práctica 8. Algoritmos 
  * @author: Christian Torres Gonzalez alu0101137902@ull.edu.es
  * @description: Fichero de la clase Algoritmo_Voraz_Nuevo_, encargada de 
  * implementar el codigo que resuelve el problema de la maxima dispersion
  * media utilizando la tecnica de Algoritmo Voraz
  * @since 23/04/2020 
  * @file Fichero de implementacion de la clase Algoritmo_Voraz_Nuevo_
  * @version 1.0.0
  * @see https://github.com/ChristianTorresGonzalez/DAA_P8.git
*/

#pragma once

#include <iostream>
#include <vector>

#include "./algoritmos.h"

class Algoritmo_Voraz_Nuevo_ : public Algoritmos_
{
    private:
        int iteraciones_maximas;
        vector<Nodo_> vector_inicial;

    public:
        Algoritmo_Voraz_Nuevo_(Grafo_ );

        void resolver_algoritmo(int );
        void preprocesamiento(int );
        
        int calcular_posicion(Nodo_ );
        Nodo_ calcular_punto_lejano(Nodo_ , Nodo_ &);

        void imprimir_soluciones(void);
};