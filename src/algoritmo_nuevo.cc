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

#include "../include/algoritmo_voraz.h"    
    
    Algoritmo_Voraz_::Algoritmo_Voraz_(Grafo_ grafo):
        Algoritmos_(grafo)
        {}

    void Algoritmo_Voraz_::resolver_algoritmo(void)
    {
        Arista_ arista = calcular_arista_maxima();
        vector<Nodo_> vector_inicial;

        vector_inicial.push_back(grafo.get_nodo(arista.get_nodo_inicial() - 1));
        vector_inicial.push_back(grafo.get_nodo(arista.get_nodo_destino() - 1));
        grafo.vector_nodos.erase(grafo.vector_nodos.begin() + arista.get_nodo_inicial() - 1);
        grafo.vector_nodos.erase(grafo.vector_nodos.begin() + arista.get_nodo_destino() - 2);

        float dispersion = calcular_dispersion_media(vector_inicial);

        while(comparar_vectores(vector_inicial, vector_solucion) == false)
        {
            vector_solucion = vector_inicial;
            float nueva_dispersion = calcular_dispersion_maxima(vector_inicial);

            if (nueva_dispersion >= dispersion)
            {
                dispersion = nueva_dispersion;
                grafo.eliminar_nodo(vector_inicial[vector_inicial.size() - 1].get_identificador_nodo());
            }
            else
            {
                vector_inicial.erase(vector_inicial.begin() + vector_inicial.size());
            }
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
                Arista_ arista = vector_nodos[i].find_arista(vector_nodos[j].get_identificador_nodo());
                suma += arista.get_coste_arista();
            }
        }
        
        return suma / vector_nodos.size();
    }

    float Algoritmo_Voraz_::calcular_dispersion_maxima(vector<Nodo_> &vector_nodos, int dispersion_actual)
    {
        Nodo_ nodo_maximo;

        for (int i = 0; i < grafo.vector_nodos.size(); i++)            
        {
            vector_nodos.push_back(grafo.get_nodo(i));
            float nueva_dispersion = calcular_dispersion_media(vector_nodos);

            if (nueva_dispersion > dispersion_actual)
            {
                nodo_maximo = grafo.get_nodo(i);
                vector_nodos.push_back(nodo_maximo);
                return nueva_dispersion;
            }

            vector_nodos.erase(vector_nodos.begin() + vector_nodos.size());
        }
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

    void Algoritmo_Voraz_::imprimir_solucion()
    {
        cout << "Solucion Algoritmo Voraz: {";
        for (int i = 0; i < vector_solucion.size(); i++)
        {
            cout << vector_solucion[i].get_identificador_nodo() << " | ";
        }

        cout << "}" << endl;
    }