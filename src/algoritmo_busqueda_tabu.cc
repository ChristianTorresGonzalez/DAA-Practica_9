/**
  * @copyright Universidad de La Laguna
  * @copyright Escuela Superior de Ingeniería y Tecnología
  * @copyright Grado en Ingeniería Informática
  * @copyright Asignatura: Diseño y Analisis de Algoritmos (DAA)
  * @copyright Curso: 3º Itinerario 1
  * @copyright Práctica 8. Algoritmos 
  * @author: Christian Torres Gonzalez alu0101137902@ull.edu.es
  * @description: Fichero de la clase Algoritmo_Busqueda_Tabu_, encargada de 
  * implementar el codigo que resuelve el problema
  * @since 23/04/2020 
  * @file Fichero de implementacion de la clase Algoritmo_Busqueda_Tabu_
  * @version 1.0.0
  * @see https://github.com/ChristianTorresGonzalez/DAA_P8.git
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "../include/algoritmo_busqueda_tabu.h"    
    
    Algoritmo_Busqueda_Tabu_::Algoritmo_Busqueda_Tabu_(Grafo_ grafo, int iteraciones, int tiempo_tabu):
        iteraciones(iteraciones),
        tiempo_tabu(tiempo_tabu),
        Algoritmos_(grafo)
        {}

    void Algoritmo_Busqueda_Tabu_::resolver_algoritmo(int tamano_soluciones)
    {
        cronometro.start();
        vector_inicial.resize(0);
        int repeticiones = 0;

        preprocesamiento(tamano_soluciones);
        calcular_diversidad(diversidad, vector_inicial);
        vector<Nodo_> solucion_candidata;

        for (int i = 0; i < iteraciones; i++)
        {
            fase_constructiva(solucion_candidata);
            post_procesamiento(solucion_candidata);
            actualizar_tiempo_tabu();
        }

        diversidad = 0;
        vector_solucion = vector_inicial;
        calcular_diversidad(diversidad, vector_solucion);
        cronometro.end();
    }

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
    void Algoritmo_Busqueda_Tabu_::preprocesamiento(int tamano_soluciones)
    {
        for (int i = 0; i < tamano_soluciones; i++)
        {
            int nodo_aleatorio = rand() % grafo.get_vector_nodos().size();
            vector_inicial.push_back(grafo.get_nodo(nodo_aleatorio));
            grafo.vector_nodos.erase(grafo.vector_nodos.begin() + nodo_aleatorio);
        }
    }

    void Algoritmo_Busqueda_Tabu_::fase_constructiva(vector<Nodo_> &solucion_candidata)
    {
        float diversidad_maxima = -999999;

        for (int i = 0; i < vector_inicial.size(); i++)
        {
            vector<Nodo_> auxiliar = vector_inicial;

            for (int j = 0; j < grafo.get_vector_nodos().size(); j++)
            {
                if (grafo.vector_nodos[j].get_tiempo_tabu() == 0)
                {
                    float diversidad_parcial = 0;
                    auxiliar[i] = grafo.get_nodo(j);
                    calcular_diversidad(diversidad_parcial, auxiliar);

                    if (diversidad_parcial > diversidad_maxima)
                    {
                        diversidad_maxima = diversidad_parcial;
                        solucion_candidata = auxiliar;
                    }
                }
            }
        }
    }

    void Algoritmo_Busqueda_Tabu_::post_procesamiento(vector<Nodo_> &solucion_candidata)
    {
        float diversidad_parcial;
        calcular_diversidad(diversidad_parcial, solucion_candidata);

        if (diversidad_parcial > diversidad)
        {
            insertar_nodo(solucion_candidata);
        }
    }

    void Algoritmo_Busqueda_Tabu_::insertar_nodo(vector<Nodo_> &solucion_candidata)
    {
        for (int i = 0; i < solucion_candidata.size(); i++)
        {
            if (vector_inicial[i].get_identificador_nodo() != solucion_candidata[i].get_identificador_nodo())
            {
                vector_inicial[i].insertar_tiempo_tabu(tiempo_tabu);

                grafo.insertar_nodo(vector_inicial[i]);
                vector_inicial[i] = solucion_candidata[i];
            }
        }
    }

    void Algoritmo_Busqueda_Tabu_::actualizar_tiempo_tabu(void)
    {
        for (int i = 0; i < grafo.get_vector_nodos().size(); i++)
        {
            if (grafo.vector_nodos[i].get_tiempo_tabu() != 0)
            {
                grafo.vector_nodos[i].insertar_tiempo_tabu(grafo.vector_nodos[i].get_tiempo_tabu() - 1);
            }
        }
    }

    void Algoritmo_Busqueda_Tabu_::imprimir_soluciones(void)
    {
        imprimir_solucion("Busqueda Tabu");
    }