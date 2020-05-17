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
        diversidad(0),
        tiempo_cpu(0),
        grafo(grafo)
        {}
      
    void Algoritmos_::resolver_algoritmo()
    {

    }
    
    Nodo_ Algoritmos_::calcular_centro(vector<Nodo_> elementos)
    {
        int cantidad_coordenadas = elementos[0].get_cantidad_coordenadas();
        int cantidad_nodos = elementos.size();
        Coordenada_ coordenadas(cantidad_coordenadas);

        for (int i = 0; i < elementos.size(); i++)
        {
            for (int j = 0; j < elementos[i].get_cantidad_coordenadas(); j++)
            {
                coordenadas.insertar_coordenada(j, (coordenadas.get_coordenada(j) +
                    (elementos[i].get_coordenada(j)) / cantidad_nodos));
            }
        }

        Nodo_ centro = Nodo_(cantidad_nodos + 1, coordenadas);
        return centro;
    }

    Nodo_ Algoritmos_::calcular_distancia_maxima(Nodo_ centro, vector<Nodo_> elementos)
    {
        float distancia_maxima = 0;
        Nodo_ nodo_lejano;

        for (int i = 0; i < elementos.size(); i++)
        {
            float distancia = calcular_distancia(centro, elementos[i]);

            if (distancia > distancia_maxima)
            {
                nodo_lejano = elementos[i];
                distancia_maxima = distancia;
            }
        }

        return nodo_lejano;
    }

    float Algoritmos_::calcular_distancia(Nodo_ centro, Nodo_ nodo)
    {
        float suma_coordenadas = 0;
        for (int i = 0 ; i < centro.get_cantidad_coordenadas(); i++)
        {
            float resta = centro.get_coordenada(i) - nodo.get_coordenada(i);
            suma_coordenadas += pow(resta, 2);
        }

        return sqrt(suma_coordenadas);
    }

    float Algoritmos_::calcular_diversidad(float & diversidad, vector<Nodo_> vector_nodos)
    {
        for (int i = 0; i < vector_nodos.size() - 1; i++)
        {
            for (int j = i + 1; j < vector_nodos.size(); j++)
            {
                diversidad += calcular_distancia(vector_nodos[i], vector_nodos[j]);
            }
        }

        return diversidad;
    }

    // bool Algoritmos_::comparar_vectores(vector<Nodo_> vector_inicial, vector<Nodo_> vector_solucion)
    // {
    //     if (vector_inicial.size() != vector_solucion.size())
    //     {
    //         return false;
    //     }
    //     else
    //     {
    //         for (int i = 0; i < vector_inicial.size(); i++)
    //         {
    //             if (vector_inicial[i].get_identificador_nodo() != vector_solucion[i].get_identificador_nodo())
    //             {
    //                 return false;
    //             }
    //         }
    //         return true;
    //     }
    // }

    // bool Algoritmos_::buscar_en_vector(Nodo_ nodo, vector<Nodo_> vector_nodos)
    // {
    //     if (vector_nodos.size() == 0)
    //     {
    //         return false;
    //     }
    //     else
    //     {
    //         for (int i = 0; i < vector_nodos.size(); i++)
    //         {
    //             if (vector_nodos[i].get_identificador_nodo() == nodo.get_identificador_nodo())
    //             {
    //                 return true;
    //             }
    //         }

    //         return false;
    //     }
    // }

    // float Algoritmos_::calcular_dispersion_media(vector<Nodo_> vector_nodos)
    // {
    //     float suma = 0;
    //     for (int i = 0; i < vector_nodos.size() - 1; i++)
    //     {
    //         for (int j = i + 1; j < vector_nodos.size(); j++)
    //         {
    //             Arista_ arista = vector_nodos[i].find_arista(vector_nodos[j].get_identificador_nodo());
    //             suma += arista.get_coste_arista();
    //         }
    //     }
        
    //     return (suma / vector_nodos.size());
    // }

    void Algoritmos_::imprimir_solucion(string cadena)
    {   
        cout << "Solucion Algoritmo " << cadena << ": {";
        for (int i = 0; i < vector_solucion.size(); i++)
        {
            cout << vector_solucion[i].get_identificador_nodo() << " | ";
        }

        cout << "}" << endl;
        cout << "Tiempo de CPU: " << cronometro.tiempo_transcurrido() << endl;
        cout << "Diversidad maxima: " << diversidad << endl;
    }