/**
  * @copyright Universidad de La Laguna
  * @copyright Escuela Superior de Ingeniería y Tecnología
  * @copyright Grado en Ingeniería Informática
  * @copyright Asignatura: Diseño y Analisis de Algoritmos (DAA)
  * @copyright Curso: 3º Itinerario 1
  * @copyright Práctica 8. Algoritmos 
  * @author: Christian Torres Gonzalez alu0101137902@ull.edu.es
  * @description: Fichero de la clase Grafo, encargadad de almacenar
  * la informacion al grafo con el que estamos trabajando
  * @since 23/04/2020 
  * @file Fichero de implementacion de la clase Grafo
  * @version 1.0.0
  * @see https://github.com/ChristianTorresGonzalez/DAA_P8.git
*/

#pragma once

#include <iostream>
#include <vector>
#include <fstream>

#include "nodo.h"
#include "arista.h"

using namespace std;

class Grafo_
{
	public:
		int numero_nodos;
		vector<Nodo_> vector_nodos;
		vector<Arista_> vector_aristas;
		
	public:
		Grafo_(void);
		Grafo_(int , vector<Arista_> );

		void construir_nodos(void);
		
		void set_aristas(vector<Arista_> );
		void insertar_nodo(Nodo_ );
    
		int get_numero_nodos(void);
		Nodo_ get_nodo(int );
		
		void imprimir_grafo(void);
		void imprimir_costes(void);

		void eliminar_nodo(int );
};
