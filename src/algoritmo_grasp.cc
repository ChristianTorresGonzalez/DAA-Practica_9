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

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "../include/algoritmo_grasp.h"    
    
    Algoritmo_GRASP_::Algoritmo_GRASP_(Grafo_ grafo, int size, int opcion, int iteraciones):
        iteraciones(iteraciones),
        size_lrc(size),
        lrc(),
        Algoritmos_(grafo)
        {}

    void Algoritmo_GRASP_::resolver_algoritmo(int tamano_soluciones)
    {
        cronometro.start();
        vector_solucion.resize(0);
        int repeticiones = 0;

        preprocesamiento();

        while (vector_inicial.size() < tamano_soluciones)
        {
            calcular_diversidad(diversidad, vector_inicial);

            while(repeticiones < iteraciones)
            {
                lrc.resize(0);
                Nodo_ nodo;

                fase_constructiva(nodo);
                post_procesamiento(nodo);
                actualizar_solucion();

                repeticiones++;
            }
        }

        cronometro.end();
    }

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
    void Algoritmo_GRASP_::preprocesamiento(int tamano_soluciones)
    {
        for (int i = 0; i < tamano_soluciones; i++)
        {
            int nodo_aleatorio = rand() % grafo.get_vector_nodos().size();
            vector_inicial.push_back(grafo.get_nodo(nodo_aleatorio));
            grafo.vector_nodos.erase(grafo.vector_nodos.begin() + nodo_aleatorio);
        }
    }

    void Algoritmo_GRASP_::fase_constructiva(Nodo_ &nodo)
    {
        int i, j = 0;
        while(j < grafo.vector_nodos.size())
        {
            if (i < size_lrc)
            {
                lrc.push_back(grafo.get_nodo(j));
                i++;
                j++;
            }
            else
            {
                i = 0;
                bool cambiado = false;
                while(!cambiado || i < lrc.size())
                {
                    vector_inicial.push_back(lrc[i]);
                    float diversidad_anterior = calcular_diversidad(vector_inicial);
                    vector_inicial.erase(vector_inicial.begin() + vector_inicial.size());

                    vector_inicial.push_back(grafo.get_nodo(j));
                    int diversidad_siguiente = calcular_diversidad(vector_inicial);
                    vector_inicial.erase(vector_inicial.begin() + vector_inicial.size());

                    if (diversidad_siguiente >= diversidad_anterior)
                    {
                        lrc[i] = grafo.get_nodo(j);
                        cambiado = true;
                    }                    

                    i++;
                }
            }     
        }

        nodo = lrc[rand() % lrc.size()];
    }

    bool Algoritmo_GRASP_::post_procesamiento(Nodo_ &nodo)
    {
        vector_inicial.push_back(nodo);

        float nueva_dispersion = calcular_dispersion_media(vector_inicial);

        if (nueva_dispersion >= dispersion_media)
        {
            dispersion_media = nueva_dispersion;
            grafo.eliminar_nodo(vector_inicial[vector_inicial.size() - 1].get_identificador_nodo());

            return true;
        }
        else
        {
            vector_inicial.erase(vector_inicial.begin() + vector_inicial.size());

            return false;
        }
    }

    void Algoritmo_GRASP_::actualizar_solucion()
    {
        vector_solucion = vector_inicial;
    }