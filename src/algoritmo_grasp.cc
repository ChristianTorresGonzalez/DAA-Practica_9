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

#include "../include/algoritmo_grasp.h"    
    
    Algoritmo_GRASP_::Algoritmo_GRASP_(Grafo_ grafo, int size, int opcion, int iteraciones):
        iteraciones(iteraciones),
        opcion(opcion),
        dispersion(0),
        size_lrc(size),
        lrc(),
        Algoritmos_(grafo)
        {}

    void Algoritmo_GRASP_::resolver_algoritmo(void)
    {
        vector_solucion.resize(0);
        int repeticiones = 0;

        vector<Nodo_> vector_inicial;

        preprocesamiento(vector_inicial);
        vector_solucion = vector_inicial;

        dispersion = calcular_dispersion_media(vector_inicial);

        if (opcion == 0)
        {
            while(repeticiones < iteraciones)
            {
                lrc.resize(0);
                Nodo_ nodo;

                fase_constructiva(nodo);
                post_procesamiento(nodo, vector_inicial);
                actualizar_solucion(vector_inicial);

                repeticiones++;
            }
        }
        else
        {
            while(repeticiones < iteraciones)
            {
                lrc.resize(0);
                Nodo_ nodo;

                fase_constructiva(nodo);
                int salida = post_procesamiento(nodo, vector_inicial);
                actualizar_solucion(vector_inicial);
                
                if (salida == false)
                    repeticiones++;
            }
        }
    }

    void Algoritmo_GRASP_::preprocesamiento(vector<Nodo_> &vector_nodos)
    {
        Arista_ arista = calcular_arista_maxima();

        vector_nodos.push_back(grafo.get_nodo(arista.get_nodo_inicial() - 1));
        vector_nodos.push_back(grafo.get_nodo(arista.get_nodo_destino() - 1));

        grafo.vector_nodos.erase(grafo.vector_nodos.begin() + arista.get_nodo_inicial() - 1);
        grafo.vector_nodos.erase(grafo.vector_nodos.begin() + arista.get_nodo_destino() - 2);
    }

    void Algoritmo_GRASP_::fase_constructiva(Nodo_ &nodo)
    {
        while(lrc.size() < size_lrc && lrc.size() != grafo.vector_nodos.size())
        {
            int posicion = rand() % grafo.vector_nodos.size();
            if (!buscar_en_vector(grafo.get_nodo(posicion), lrc))
            {
                lrc.push_back(grafo.get_nodo(posicion));
            }            
        }

        nodo = lrc[rand() % lrc.size()];
    }

    bool Algoritmo_GRASP_::post_procesamiento(Nodo_ &nodo, vector<Nodo_> &vector_inicial)
    {
        vector_inicial.push_back(nodo);

        float nueva_dispersion = calcular_dispersion_media(vector_inicial);

        if (nueva_dispersion >= dispersion)
        {
            dispersion = nueva_dispersion;
            grafo.eliminar_nodo(vector_inicial[vector_inicial.size() - 1].get_identificador_nodo());

            return true;
        }
        else
        {
            vector_inicial.erase(vector_inicial.begin() + vector_inicial.size());

            return false;
        }
    }

    void Algoritmo_GRASP_::actualizar_solucion(vector<Nodo_> &vector_inicial)
    {
        vector_solucion = vector_inicial;
    }

    void Algoritmo_GRASP_::imprimir_solucion()
    {
        cout << "Solucion Algoritmo GRASP: {";
        for (int i = 0; i < vector_solucion.size(); i++)
        {
            cout << vector_solucion[i].get_identificador_nodo() << " | ";
        }

        cout << "}" << endl;
    }