/**
  * @copyright Universidad de La Laguna
  * @copyright Escuela Superior de Ingeniería y Tecnología
  * @copyright Grado en Ingeniería Informática
  * @copyright Asignatura: Diseño y Analisis de Algoritmos (DAA)
  * @copyright Curso: 3º Itinerario 1
  * @copyright Práctica 8. Algoritmos 
  * @author: Christian Torres Gonzalez alu0101137902@ull.edu.es
  * @description: Fichero de la clase Algoritmo_Voraz_Nuevo_, encargada de 
  * implementar el codigo que resuelve el problema de la maxima dispersion
  * media utilizando la tecnica de Algoritmo Voraz
  * @since 23/04/2020 
  * @file Fichero de implementacion de la clase Algoritmo_Voraz_Nuevo_
  * @version 1.0.0
  * @see https://github.com/ChristianTorresGonzalez/DAA_P8.git
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "../include/algoritmo_voraz_nuevo.h"    
    
    Algoritmo_Voraz_Nuevo_::Algoritmo_Voraz_Nuevo_(Grafo_ grafo):
        Algoritmos_(grafo)
        {}

    void Algoritmo_Voraz_Nuevo_::resolver_algoritmo(int tamano_soluciones)
    {
        cronometro.start();

        preprocesamiento(2);
        Nodo_ punto_referencia = grafo.get_nodo(rand() % grafo.get_vector_nodos().size());
        Nodo_ centro = calcular_centro(vector_inicial);

        while (vector_inicial.size() < tamano_soluciones)
        {
            Nodo_ nodo_lejano = calcular_punto_lejano(centro, punto_referencia);
            vector_inicial.push_back(nodo_lejano);

            centro = calcular_centro(vector_inicial);
        }

        vector_solucion = vector_inicial;
        calcular_diversidad(diversidad, vector_solucion);
        cronometro.end();
    }

    void Algoritmo_Voraz_Nuevo_::preprocesamiento(int tamano_soluciones)
    {
        for (int i = 0; i < tamano_soluciones; i++)
        {
            int nodo_aleatorio = rand() % grafo.get_vector_nodos().size();
            vector_inicial.push_back(grafo.get_nodo(nodo_aleatorio));
            grafo.vector_nodos.erase(grafo.vector_nodos.begin() + nodo_aleatorio);
        }
    }

    Nodo_ Algoritmo_Voraz_Nuevo_::calcular_punto_lejano(Nodo_ centro, Nodo_ &punto_referencia)
    {
        const int iteraciones_maximas = 10;
        float distancia_maxima = 0;
        int iteraciones = 0;
        float distancia_referencia = calcular_distancia(centro, punto_referencia);

        while (iteraciones < iteraciones_maximas)
        {
            int nodo_aleatorio = rand() % grafo.get_vector_nodos().size();
            Nodo_ nodo_candidato = grafo.get_nodo(nodo_aleatorio);
            float distancia_candidata = calcular_distancia(centro, nodo_candidato);

            if (distancia_candidata > distancia_referencia)
            {
                grafo.vector_nodos.erase(grafo.vector_nodos.begin() + nodo_aleatorio);

                return nodo_candidato;
            }

            iteraciones++;
        }

        if (iteraciones == iteraciones_maximas)
        {
            Nodo_ copia_referencia = punto_referencia;
            grafo.vector_nodos.erase(grafo.vector_nodos.begin() + calcular_posicion(punto_referencia));
            punto_referencia = grafo.get_nodo(rand() % grafo.get_vector_nodos().size());
            return copia_referencia;
        }
    }

    int Algoritmo_Voraz_Nuevo_::calcular_posicion(Nodo_ nodo)
    {
        int i = 0;
        while (i < grafo.vector_nodos.size())
        {
            if (grafo.get_nodo(i).get_identificador_nodo() == nodo.get_identificador_nodo())
            {
                return i;
            }

            i++;
        }
    }

    void Algoritmo_Voraz_Nuevo_::imprimir_soluciones(void)
    {
        imprimir_solucion("Voraz Nuevo");
    }