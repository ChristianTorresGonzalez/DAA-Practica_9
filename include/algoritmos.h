/**
  * @copyright Universidad de La Laguna
  * @copyright Escuela Superior de Ingeniería y Tecnología
  * @copyright Grado en Ingeniería Informática
  * @copyright Asignatura: Diseño y Analisis de Algoritmos (DAA)
  * @copyright Curso: 3º Itinerario 1
  * @copyright Práctica 8. Algoritmos 
  * @author: Christian Torres Gonzalez alu0101137902@ull.edu.es
  * @description: Fichero de la clase Algoritmo, encargada almacenar
  * la informacion comun a los diferentes algorimtos implementados
  * @since 23/04/2020 
  * @file Fichero de implementacion de la clase Algoritmo
  * @version 1.0.0
  * @see https://github.com/ChristianTorresGonzalez/DAA_P8.git
*/

#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>

#include "./grafo.h"
#include "./cronometro.h"

using namespace std;

class Algoritmos_ {
    public:
        float diversidad;
        int tiempo_cpu;

        vector<Nodo_> vector_inicial;
        vector<Nodo_> vector_solucion;
        
        Grafo_ grafo;

        Cronometro_ cronometro;

    public:
        Algoritmos_(Grafo_ );

        Nodo_ calcular_centro(vector<Nodo_> );
        Nodo_ calcular_distancia_maxima(Nodo_ , vector<Nodo_> );
        float calcular_distancia(Nodo_ , Nodo_ );
        float calcular_diversidad(float & , vector<Nodo_>);

        // Arista_ calcular_arista_maxima();
        // float calcular_dispersion_media(vector<Nodo_> );

        // bool comparar_vectores(vector<Nodo_> , vector<Nodo_> );
        // bool buscar_en_vector(Nodo_ , vector<Nodo_> );

        void imprimir_solucion(string );

        virtual void resolver_algoritmo(void);
};