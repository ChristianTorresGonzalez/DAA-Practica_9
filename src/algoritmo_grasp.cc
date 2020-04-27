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
        opcion(opcion),
        size_lrc(size),
        lrc(),
        Algoritmos_(grafo)
        {}

    void Algoritmo_GRASP_::resolver_algoritmo(int metodo)
    {
        cronometro.start();
        vector_solucion.resize(0);
        int repeticiones = 0;

        if (metodo == 0)
            preprocesamiento();

        dispersion_media = calcular_dispersion_media(vector_inicial);

        if (opcion == 0)
        {
            while(repeticiones < iteraciones)
            {
                lrc.resize(0);
                Nodo_ nodo;

                if (metodo == 0 || metodo == 1)
                {
                    fase_constructiva(nodo);
                    post_procesamiento(nodo);
                    actualizar_solucion();
                }
                else if (metodo == 2)
                {
                    fase_constructiva_multiarranque(nodo);
                    post_procesamiento_multiarranque(nodo);
                    actualizar_solucion();
                }

                repeticiones++;
            }

            cronometro.end();
        }
        else
        {
            while(repeticiones < iteraciones)
            {
                lrc.resize(0);
                Nodo_ nodo;

                fase_constructiva(nodo);
                int salida = post_procesamiento(nodo);
                actualizar_solucion();
                
                if (salida == false)
                    repeticiones++;
            }

            cronometro.end();
        }
    }

    vector<Nodo_> Algoritmo_GRASP_::resolver_algoritmo(vector<Nodo_> &vector_inicio, int metodo)
    {
        cronometro.start();
        vector_inicial = vector_inicio;
        resolver_algoritmo(metodo);

        return vector_solucion;
        cronometro.end();
    }

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
    void Algoritmo_GRASP_::preprocesamiento()
    {
        Arista_ arista = calcular_arista_maxima();

        vector_inicial.push_back(grafo.get_nodo(arista.get_nodo_inicial() - 1));
        vector_inicial.push_back(grafo.get_nodo(arista.get_nodo_destino() - 1));

        grafo.vector_nodos.erase(grafo.vector_nodos.begin() + arista.get_nodo_inicial() - 1);
        grafo.vector_nodos.erase(grafo.vector_nodos.begin() + arista.get_nodo_destino() - 2);
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
                    int dispersion_anterior = calcular_dispersion_media(vector_inicial);
                    vector_inicial.erase(vector_inicial.begin() + vector_inicial.size());

                    vector_inicial.push_back(grafo.get_nodo(j));
                    int dispersion_siguiente = calcular_dispersion_media(vector_inicial);
                    vector_inicial.erase(vector_inicial.begin() + vector_inicial.size());

                    if (dispersion_siguiente >= dispersion_anterior)
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

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
    void Algoritmo_GRASP_::fase_constructiva_multiarranque(Nodo_ &nodo)
    {
        int i = 0;
        while(lrc.size() < size_lrc && i < grafo.vector_nodos.size())
        {
            vector_inicial.push_back(grafo.get_nodo(i));
            float nueva_dispersion = calcular_dispersion_media(vector_inicial);

            if (nueva_dispersion >= dispersion_media)
            {
                dispersion_media = nueva_dispersion;
                lrc.push_back(grafo.get_nodo(i));
            }

            vector_inicial.erase(vector_inicial.begin() + vector_inicial.size());

            i++;
        }

        if (lrc.size() > 0)
            nodo = lrc[rand() % lrc.size()];
        else
            nodo.insertar_identificador(-1);
    }
    
    bool Algoritmo_GRASP_::post_procesamiento_multiarranque(Nodo_ &nodo)
    {
        if (nodo.get_identificador_nodo() != -1)
        {
            vector_inicial.push_back(nodo);
            float nueva_dispersion = calcular_dispersion_media(vector_inicial);
            dispersion_media = nueva_dispersion;
            grafo.eliminar_nodo(nodo.get_identificador_nodo());
        }
    }