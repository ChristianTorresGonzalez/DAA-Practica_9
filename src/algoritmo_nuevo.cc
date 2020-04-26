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
        cronometro.start();
        Arista_ arista = calcular_arista_maxima();

        vector_inicial.push_back(grafo.get_nodo(arista.get_nodo_inicial() - 1));
        vector_inicial.push_back(grafo.get_nodo(arista.get_nodo_destino() - 1));
        grafo.vector_nodos.erase(grafo.vector_nodos.begin() + arista.get_nodo_inicial() - 1);
        grafo.vector_nodos.erase(grafo.vector_nodos.begin() + arista.get_nodo_destino() - 2);

        dispersion_media = calcular_dispersion_media(vector_inicial);

        while(comparar_vectores(vector_inicial, vector_solucion) == false)
        {
            vector_solucion = vector_inicial;
            float nueva_dispersion = calcular_dispersion_maxima(dispersion_media);

            if (nueva_dispersion >= dispersion_media)
            {
                dispersion_media = nueva_dispersion;
                grafo.eliminar_nodo(vector_inicial[vector_inicial.size() - 1].get_identificador_nodo());
            }
        }

        cronometro.end();
    }

    float Algoritmo_Nuevo_::calcular_dispersion_maxima(float dispersion_actual)
    {
        float dispersion = dispersion_actual;
        bool encontrado = false;

        int i = 0;
        while (i < grafo.vector_nodos.size() && encontrado == false)            
        {
            vector_inicial.push_back(grafo.get_nodo(i));
            float nueva_dispersion = calcular_dispersion_media(vector_inicial);

            if (nueva_dispersion >= dispersion)
            {
                dispersion = nueva_dispersion;
                encontrado = true;
            }
            else
            {
                vector_inicial.erase(vector_inicial.begin() + vector_inicial.size());   
            }

            i++;
        }

        return dispersion;
    }

    void Algoritmo_Nuevo_::imprimir_solucion()
    {
        cout << "Solucion Algoritmo Nuevo: {";
        for (int i = 0; i < vector_solucion.size(); i++)
        {
            cout << vector_solucion[i].get_identificador_nodo() << " | ";
        }

        cout << "}" << endl;
        cout << "Tiempo de CPU: " << cronometro.tiempo_transcurrido() << endl;
        cout << "Dispersion media: " << dispersion_media << endl;
    }