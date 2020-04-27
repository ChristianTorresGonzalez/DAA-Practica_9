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

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "../include/algoritmo_voraz.h"    
    
    Algoritmo_Voraz_::Algoritmo_Voraz_(Grafo_ grafo):
        Algoritmos_(grafo)
        {}

    void Algoritmo_Voraz_::resolver_algoritmo(void)
    {
        cronometro.start();
        Arista_ arista = calcular_arista_maxima();

        vector_inicial.push_back(grafo.get_nodo(arista.get_nodo_inicial() - 1));
        vector_inicial.push_back(grafo.get_nodo(arista.get_nodo_destino() - 1));
        grafo.vector_nodos.erase(grafo.vector_nodos.begin() + arista.get_nodo_inicial() - 1);
        grafo.vector_nodos.erase(grafo.vector_nodos.begin() + arista.get_nodo_destino() - 2);

        dispersion_media = calcular_dispersion_media(vector_inicial);

        while(comparar_vectores(vector_inicial, vector_solucion) == false)
        {
            vector_solucion = vector_inicial;
            float nueva_dispersion = calcular_dispersion_maxima();

            if (nueva_dispersion >= dispersion_media)
            {
                dispersion_media = nueva_dispersion;
                grafo.eliminar_nodo(vector_inicial[vector_inicial.size() - 1].get_identificador_nodo());
            }
            else
            {
                vector_inicial.erase(vector_inicial.begin() + vector_inicial.size());
            }
        }

        cronometro.end();
    }

    float Algoritmo_Voraz_::calcular_dispersion_maxima()
    {
        float dispersion = 0;
        Nodo_ nodo_maximo;

        for (int i = 0; i < grafo.vector_nodos.size(); i++)            
        {
            vector_inicial.push_back(grafo.get_nodo(i));
            float nueva_dispersion = calcular_dispersion_media(vector_inicial);

            if (nueva_dispersion >= dispersion)
            {
                dispersion = nueva_dispersion;
                nodo_maximo = grafo.get_nodo(i);
            }

            vector_inicial.erase(vector_inicial.begin() + vector_inicial.size());
        }

        vector_inicial.push_back(nodo_maximo);

        return dispersion;
    }