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

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "../include/algoritmo_busqueda_local.h"    
    
    Algoritmo_BusquedaLocal_::Algoritmo_BusquedaLocal_(Grafo_ grafo):
        Algoritmos_(grafo)
        {}

    void Algoritmo_BusquedaLocal_::resolver_algoritmo(int tamano_soluciones)
    {
        cronometro.start();
        vector_inicial.resize(0);
        int repeticiones = 0;

        preprocesamiento(tamano_soluciones);
        calcular_diversidad(diversidad, vector_inicial);
        vector_solucion = vector_inicial;

        for (int i = 0; i < vector_inicial.size(); i++)
        {
            for (int j = 0; j < grafo.get_vector_nodos().size(); j++)
            {
                float diversidad_parcial = 0;
                vector_solucion[i] = grafo.get_nodo(j);
                calcular_diversidad(diversidad_parcial, vector_solucion);

                if (diversidad_parcial >= diversidad)
                {
                    vector_inicial = vector_solucion;
                    diversidad = diversidad_parcial;
                }
                else
                {
                    vector_solucion = vector_inicial;
                }
            }
        }

        cronometro.end();
    }

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
    void Algoritmo_BusquedaLocal_::preprocesamiento(int tamano_soluciones)
    {
        for (int i = 0; i < tamano_soluciones; i++)
        {
            int nodo_aleatorio = rand() % grafo.get_vector_nodos().size();
            vector_inicial.push_back(grafo.get_nodo(nodo_aleatorio));
            grafo.vector_nodos.erase(grafo.vector_nodos.begin() + nodo_aleatorio);
        }
    }

    void Algoritmo_BusquedaLocal_::imprimir_soluciones(void)
    {
        imprimir_solucion("Busqueda Local");
    }