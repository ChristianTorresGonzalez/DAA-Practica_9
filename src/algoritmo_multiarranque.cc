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

#include "../include/algoritmo_multiarranque.h"    
    
    Algoritmo_Multiarranque_::Algoritmo_Multiarranque_(Grafo_ grafo):
        Algoritmos_(grafo)
        {}

    void Algoritmo_Multiarranque_::resolver_algoritmo_metodo1(void)
    {
        vector_solucion.resize(0);

        vector<Nodo_> vector_inicial;
        preprocesamiento_metodo1(vector_inicial);

        Algoritmo_GRASP_ algoritmo(grafo, 3, 1, 1000);
        vector_solucion = algoritmo.resolver_algoritmo(vector_inicial, 1);
    }

    void Algoritmo_Multiarranque_::resolver_algoritmo_metodo2(void)
    {
        vector<Nodo_> vector_inicial;
        preprocesamiento_metodo2(vector_inicial);

        Algoritmo_GRASP_ algoritmo(grafo, 5, 0, 1000);
        vector_solucion = algoritmo.resolver_algoritmo(vector_inicial, 2);
    }

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
    void Algoritmo_Multiarranque_::preprocesamiento_metodo1(vector<Nodo_> &vector_nodos)
    {
        int nodo = rand() % grafo.get_numero_nodos();
        int arista = rand() % grafo.get_nodo(nodo).get_cantidad_aristas();
        
        Arista_ arista_inicial = grafo.get_nodo(nodo).get_arista(arista);

        vector_nodos.push_back(grafo.get_nodo(arista_inicial.get_nodo_inicial() - 1));
        vector_nodos.push_back(grafo.get_nodo(arista_inicial.get_nodo_destino() - 1));

        grafo.eliminar_nodo(arista_inicial.get_nodo_inicial());
        grafo.eliminar_nodo(arista_inicial.get_nodo_destino());
    }

    void Algoritmo_Multiarranque_::preprocesamiento_metodo2(vector<Nodo_> &vector_nodos)
    {
        Arista_ arista = calcular_arista_maxima();

        vector_nodos.push_back(grafo.get_nodo(arista.get_nodo_inicial() - 1));
        vector_nodos.push_back(grafo.get_nodo(arista.get_nodo_destino() - 1));

        grafo.vector_nodos.erase(grafo.vector_nodos.begin() + arista.get_nodo_inicial() - 1);
        grafo.vector_nodos.erase(grafo.vector_nodos.begin() + arista.get_nodo_destino() - 2);
    }

// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------
    void Algoritmo_Multiarranque_::imprimir_solucion()
    {
        cout << "Solucion Algoritmo Multiarranque: {";
        for (int i = 0; i < vector_solucion.size(); i++)
        {
            cout << vector_solucion[i].get_identificador_nodo() << " | ";
        }

        cout << "}" << endl;
    }