/**
  * @copyright Universidad de La Laguna
  * @copyright Escuela Superior de Ingeniería y Tecnología
  * @copyright Grado en Ingeniería Informática
  * @copyright Asignatura: Diseño y Analisis de Algoritmos (DAA)
  * @copyright Curso: 3º Itinerario 1
  * @copyright Práctica 8. Algoritmos 
  * @author: Christian Torres Gonzalez alu0101137902@ull.edu.es
  * @description: Fichero de la clase Arista_, encargada de almacenar
  * la informacion relevante a cada arista
  * @since 23/04/2020 
  * @file Fichero de implementacion de la clase Arista_
  * @version 1.0.0
  * @see https://github.com/ChristianTorresGonzalez/DAA_P8.git
*/

#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Arista_
{
    public:
        int nodo_inicial;
        int nodo_final;
        float coste;

    public:
        Arista_(void);
        Arista_(int , int , float );

        int get_nodo_inicial(void);
        int get_nodo_destino(void);
        float get_coste_arista(void);

        void set_nodo_inicial(int );
        void set_nodo_final(int );
        void set_coste(float );
        
        bool operator ==(Arista_ );

        void imprimir_arista(void);
};
