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

#include "../include/algoritmo_nuevo.h"    
    
    Algoritmo_Nuevo_::Algoritmo_Nuevo_(Grafo_ grafo):
        Algoritmos_(grafo)
        {}

    void Algoritmo_Nuevo_::resolver_algoritmo(void)
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
            float nueva_dispersion = calcular_dispersion_maxima(vector_inicial, dispersion);
            // cout << "Dispersion: " << dispersion << " - " << nueva_dispersion << endl;

            if (nueva_dispersion >= dispersion)
            {
                dispersion = nueva_dispersion;
                grafo.eliminar_nodo(vector_inicial[vector_inicial.size() - 1].get_identificador_nodo());
                imprimir_solucion();
            }
        }
    }

    Arista_ Algoritmo_Nuevo_::calcular_arista_maxima()
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

    float Algoritmo_Nuevo_::calcular_dispersion_media(vector<Nodo_> vector_nodos)
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
        
        return (suma / vector_nodos.size());
    }

    float Algoritmo_Nuevo_::calcular_dispersion_maxima(vector<Nodo_> &vector_nodos, float dispersion_actual)
    {
        cout << dispersion_actual << endl;
        for (int i = 0; i < grafo.vector_nodos.size(); i++)            
        {
            vector_nodos.push_back(grafo.get_nodo(i));
            float nueva_dispersion = calcular_dispersion_media(vector_nodos);
            cout << "Nueva dispersion: " << nueva_dispersion << endl;

            if (nueva_dispersion >= dispersion_actual)
            {
                // cout << "Sliendo"<< endl;
                return nueva_dispersion;
            }

            vector_nodos.erase(vector_nodos.begin() + vector_nodos.size());
        }

        return 0;
    }

    bool Algoritmo_Nuevo_::comparar_vectores(vector<Nodo_> vector_inicial, vector<Nodo_> vector_solucion)
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

    void Algoritmo_Nuevo_::imprimir_solucion()
    {
        cout << "Solucion Algoritmo Nuevo: {";
        for (int i = 0; i < vector_solucion.size(); i++)
        {
            cout << vector_solucion[i].get_identificador_nodo() << " | ";
        }

        cout << "}" << endl;
    }