/**
  * @copyright Universidad de La Laguna
  * @copyright Escuela Superior de Ingeniería y Tecnología
  * @copyright Grado en Ingeniería Informática
  * @copyright Asignatura: Diseño y Analisis de Algoritmos (DAA)
  * @copyright Curso: 3º Itinerario 1
  * @copyright Práctica 8. Algoritmos 
  * @author: Christian Torres Gonzalez alu0101137902@ull.edu.es
  * @description: Fichero de la clase Algoritmo, encargada almacenar
  * la informacion comun a los diferentes algorimtos implementados
  * @since 23/04/2020 
  * @file Fichero de implementacion de la clase Algoritmo
  * @version 1.0.0
  * @see https://github.com/ChristianTorresGonzalez/DAA_P8.git
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "../include/algoritmos.h"

    Algoritmos_::Algoritmos_(Grafo_ grafo):
        dispersion_media(0),
        tiempo_cpu(0),
        grafo(grafo)
        {}
      
    void Algoritmos_::resolver_algoritmo()
    {

    }
    
    Arista_ Algoritmos_::calcular_arista_maxima()
    {
        float coste = 0;
        Arista_ arista_maxima;

        for (int i = 0; i < grafo.get_numero_nodos(); i++)
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

    bool Algoritmos_::comparar_vectores(vector<Nodo_> vector_inicial, vector<Nodo_> vector_solucion)
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

    bool Algoritmos_::buscar_en_vector(Nodo_ nodo, vector<Nodo_> vector_nodos)
    {
        if (vector_nodos.size() == 0)
        {
            return false;
        }
        else
        {
            for (int i = 0; i < vector_nodos.size(); i++)
            {
                if (vector_nodos[i].get_identificador_nodo() == nodo.get_identificador_nodo())
                {
                    return true;
                }
            }

            return false;
        }
    }

    float Algoritmos_::calcular_dispersion_media(vector<Nodo_> vector_nodos)
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

    void Algoritmos_::imprimir_solucion(string cadena)
    {   
        cout << "Solucion Algoritmo " << cadena << ": {";
        for (int i = 0; i < vector_solucion.size(); i++)
        {
            cout << vector_solucion[i].get_identificador_nodo() << " | ";
        }

        cout << "}" << endl;
        cout << "Tiempo de CPU: " << cronometro.tiempo_transcurrido() << endl;
        cout << "Dispersion media: " << dispersion_media << endl;
    }