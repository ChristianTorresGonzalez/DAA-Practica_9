/**
  * @copyright Universidad de La Laguna
  * @copyright Escuela Superior de Ingeniería y Tecnología
  * @copyright Grado en Ingeniería Informática
  * @copyright Asignatura: Diseño y Analisis de Algoritmos (DAA)
  * @copyright Curso: 3º Itinerario 1
  * @copyright Práctica 8. Algoritmos 
  * @author: Christian Torres Gonzalez alu0101137902@ull.edu.es
  * @description: Fichero de la clase Algoritmo_VNS, encargada de 
  * implementar el codigo que resuelve el problema
  * @since 23/04/2020 
  * @file Fichero de implementacion de la clase Algoritmo_VNS
  * @version 1.0.0
  * @see https://github.com/ChristianTorresGonzalez/DAA_P8.git
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "../include/algoritmo_vns.h"    
    
    Algoritmo_VNS_::Algoritmo_VNS_(Grafo_ grafo):
        Algoritmos_(grafo)
        {}

    void Algoritmo_VNS_::resolver_algoritmo(int iteraciones, int intercambios, int opcion)
    {
        cronometro.start();
        vector_solucion.resize(0);

        preprocesamiento();

        Algoritmo_GRASP_ algoritmo(grafo, 3, 1, 1000);
        vector_solucion = algoritmo.resolver_algoritmo(vector_inicial, 1);
        dispersion_media = algoritmo.dispersion_media;
        grafo = algoritmo.grafo;
        estructura_entorno(iteraciones, intercambios, opcion);

        cronometro.end();
    }

    void Algoritmo_VNS_::preprocesamiento(void)
    {
        Arista_ arista = calcular_arista_maxima();

        vector_inicial.push_back(grafo.get_nodo(arista.get_nodo_inicial() - 1));
        vector_inicial.push_back(grafo.get_nodo(arista.get_nodo_destino() - 1));

        grafo.vector_nodos.erase(grafo.vector_nodos.begin() + arista.get_nodo_inicial() - 1);
        grafo.vector_nodos.erase(grafo.vector_nodos.begin() + arista.get_nodo_destino() - 2);
    }

    void Algoritmo_VNS_::estructura_entorno(int iteraciones, int intercambios, int opcion)
    {
        if (opcion == 1)
        {
            for (int i = 0; i < iteraciones; i++)
            {
                bool encontrado = false;
                int busquedas = 0;
                vector<Nodo_> auxiliar = vector_solucion;

                while (busquedas < intercambios && encontrado == false)
                {
                    Nodo_ nodo_candidato = grafo.get_nodo(rand() % grafo.vector_nodos.size());
                    int posicion = rand() % auxiliar.size();

                    Nodo_ nodo_extraido = auxiliar[posicion];
                    auxiliar.erase(auxiliar.begin() + posicion);
                    auxiliar.push_back(nodo_candidato);

                    float disperion_nueva = calcular_dispersion_media(auxiliar);

                    if (disperion_nueva >= dispersion_media)
                    {
                        vector_solucion = auxiliar;
                        encontrado = true;
                        dispersion_media = disperion_nueva;
                        grafo.eliminar_nodo(nodo_candidato.get_identificador_nodo());
                        grafo.vector_nodos.push_back(nodo_extraido);
                    }
                    
                    busquedas++;                    
                }
            }

        }
    }