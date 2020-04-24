/**
  * @copyright Universidad de La Laguna
  * @copyright Escuela Superior de Ingeniería y Tecnología
  * @copyright Grado en Ingeniería Informática
  * @copyright Asignatura: Diseño y Analisis de Algoritmos (DAA)
  * @copyright Curso: 3º Itinerario 1
  * @copyright Práctica 8. Algoritmos 
  * @author: Christian Torres Gonzalez alu0101137902@ull.edu.es
  * @description: Fichero de la clase Algoritmo, encargada de leer los
  * datos del archivo, tratarlos, almacenarlos y pasarselos al grafo
  * que se utilizara para la resolucion de los algoritmos
  * @since 23/04/2020 
  * @file Fichero de implementacion de la clase Algoritmo
  * @version 1.0.0
  * @see https://github.com/ChristianTorresGonzalez/DAA_P8.git
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "../include/algoritmos.h"

    Algoritmos_::Algoritmos_(Grafo_ grafo):
        dispersion_media(0),
        tiempo_cpu(0),
        grafo(grafo)
        {}

    Algoritmo_Voraz_::Algoritmo_Voraz_(Grafo_ grafo):
        Algoritmos_(grafo)
        {}

    void Algoritmo_Voraz_::resolver_algoritmo(void)
    {
        Arista_ arista = calcular_arista_maxima();
        vector<Nodo_> vector_inicial;
        vector_inicial.push_back(grafo.get_nodo(arista.get_nodo_inicial() - 1));
        vector_inicial.push_back(grafo.get_nodo(arista.get_nodo_destino() - 1));

        float dispersion = calcular_dispersion_media(vector_inicial);
        vector<Nodo_> vector_solucion;

        // do
        // {
        //     vector_solucion = vector_solucion;
        // } while(!comparar_vectores(vector_inicial, vector_solucion));
    }

    bool Algoritmo_Voraz_::comparar_vectores(vector<Nodo_> vector_inicial, vector<Nodo_> vector_solucion)
    {
        if (vector_inicial.size() != vector_solucion.size())
        {
            return false;
        }
        else
        {
            for (int i = 0; i < vector_inicial.size(); i++)
            {
                if (vector_inicial[i].get_identificador_nodo() != vector_solucion[i].get_identificador_nodo())
                {
                    return false;
                }
            }
            return true;
        }
    }

    Arista_ Algoritmo_Voraz_::calcular_arista_maxima()
    {
        float coste = 0;
        Arista_ arista_maxima;

        for (int i = 0; i < this -> grafo.get_numero_nodos(); i++)
        {
            for (int j = 0; j < grafo.get_nodo(i).get_cantidad_aristas(); j++)
            {
                if (grafo.get_nodo(i).get_coste_arista(j) > coste)
                {
                    coste = grafo.get_nodo(i).get_coste_arista(j);
                    arista_maxima = grafo.get_nodo(i).get_arista(j);
                }
            }
        }

        return arista_maxima;
    }

    float Algoritmo_Voraz_::calcular_dispersion_media(vector<Nodo_> vector_nodos)
    {
        float suma = 0;
        for (int i = 0; i < vector_nodos.size() - 1; i++)
        {
            for (int j = i + 1; j < vector_nodos.size(); j++)
            {
                suma += vector_nodos[i].get_coste_arista(vector_nodos[j].get_identificador_nodo() - 2);
            }
        }

        return suma / vector_nodos.size();
    }