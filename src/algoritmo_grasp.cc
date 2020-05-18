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
    
    Algoritmo_GRASP_::Algoritmo_GRASP_(Grafo_ grafo, int size, int iteraciones):
        iteraciones(iteraciones),
        size_lrc(size),
        lrc(),
        Algoritmos_(grafo)
        {}

    void Algoritmo_GRASP_::resolver_algoritmo(int tamano_soluciones)
    {
        cronometro.start();
        vector_inicial.resize(0);
        int repeticiones = 0;

        preprocesamiento(tamano_soluciones);
        vector_solucion = vector_inicial;
        calcular_diversidad(diversidad, vector_inicial);
        
        lrc.resize(tamano_soluciones);
        vector<Nodo_> solucion_candidata;
        bool cambio = false;

        fase_constructiva(solucion_candidata);
        post_procesamiento(solucion_candidata, cambio);
        actualizar_solucion();

        while(repeticiones < iteraciones - 1)
        {
            if (cambio == true)
            {
                lrc.resize(tamano_soluciones);
            }

            if (cambio == true)
            {
                fase_constructiva(solucion_candidata);
            }

            post_procesamiento(solucion_candidata, cambio);
            actualizar_solucion();

            repeticiones++;
        }

        diversidad = 0;
        calcular_diversidad(diversidad, vector_solucion);
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

    void Algoritmo_GRASP_::fase_constructiva(vector<Nodo_> &solucion_candidata)
    {
        vector<float> diversidades(lrc.size());

        for (int i = 0; i < vector_inicial.size(); i++)
        {
            vector<Nodo_> auxiliar = vector_inicial;

            for (int j = 0; j < grafo.get_vector_nodos().size(); j++)
            {
                float diversidad_parcial = 0;
                auxiliar[i] = grafo.get_nodo(j);
                calcular_diversidad(diversidad_parcial, auxiliar);

                int k = 0;
                while (k < diversidades.size())
                {
                    if (diversidad_parcial > diversidades[k])
                    {
                        diversidades[k] = diversidad_parcial;
                        lrc[k] = auxiliar;
                        break;
                    }

                    k++;
                }
            }
        }

        solucion_candidata = lrc[rand() % lrc.size()];
    }

    bool Algoritmo_GRASP_::post_procesamiento(vector<Nodo_> &solucion_candidata, bool &cambio)
    {
        float  diversidad_parcial;
        calcular_diversidad(diversidad_parcial, solucion_candidata);

        if (diversidad_parcial > diversidad)
        {
            cambio = true;
            vector_inicial = solucion_candidata;
        }
        else
        {
            cambio = false;
        }
        
    }

    void Algoritmo_GRASP_::actualizar_solucion()
    {
        vector_solucion = vector_inicial;
    }

    void Algoritmo_GRASP_::imprimir_soluciones(void)
    {
        imprimir_solucion("GRASP");
    }