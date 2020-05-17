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

    void Algoritmo_Voraz_::resolver_algoritmo(int tamano_soluciones)
    {
        cronometro.start();
        
        vector<Nodo_> elementos = grafo.get_vector_nodos();
        vector_inicial.resize(0);

        Nodo_ centro = calcular_centro(elementos);

        while (vector_inicial.size() < tamano_soluciones)
        {
            Nodo_ nodo_lejano = calcular_distancia_maxima(centro, elementos);
            int posicion = calcular_posicion(nodo_lejano, elementos);

            vector_inicial.push_back(nodo_lejano);
            elementos.erase(elementos.begin() + posicion);
            
            centro = calcular_centro(vector_inicial);
        }

        vector_solucion = vector_inicial;
        calcular_diversidad(diversidad, vector_solucion);
        cronometro.end();
    }

    int Algoritmo_Voraz_::calcular_posicion(Nodo_ nodo, vector<Nodo_> elementos)
    {
        int i = 0;
        while (i < elementos.size())
        {
            if (elementos[i].get_identificador_nodo() == nodo.get_identificador_nodo())
            {
                return i;
            }

            i++;
        }
    }

    void Algoritmo_Voraz_::imprimir_soluciones(void)
    {
        imprimir_solucion("Voraz");
    }

    // float Algoritmo_Voraz_::calcular_dispersion_maxima()
    // {
    //     float dispersion = 0;
    //     Nodo_ nodo_maximo;

    //     for (int i = 0; i < grafo.vector_nodos.size(); i++)            
    //     {
    //         vector_inicial.push_back(grafo.get_nodo(i));
    //         float nueva_dispersion = calcular_dispersion_media(vector_inicial);

    //         if (nueva_dispersion >= dispersion)
    //         {
    //             dispersion = nueva_dispersion;
    //             nodo_maximo = grafo.get_nodo(i);
    //         }

    //         vector_inicial.erase(vector_inicial.begin() + vector_inicial.size());
    //     }

    //     vector_inicial.push_back(nodo_maximo);

    //     return dispersion;
    // }