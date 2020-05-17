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

#include <iostream>
#include <vector>

#include "../include/grafo.h"

using namespace std;

	Grafo_::Grafo_(void):
		numero_nodos(0)
		{
			vector_nodos.resize(0);
		}

	Grafo_::Grafo_(int nodos, vector<vector<float>> coordenadas):
		numero_nodos(nodos),
		vector_coordenadas(coordenadas)
		{
			construir_nodos();
		}

// ---------------------------------------------------------------------------------------------
// ------------------------------Constructor de los nodos del Grafo-----------------------------
// ---------------------------------------------------------------------------------------------
	/**
	 * Funcion encargada de construir los nodos y sus aristas, es decir, se encarga
	 * de, una vez le pasa la clase gestora el conjunto de aristas que contiene el
	 * archivo introducido, esta funcion se encarga de clasificar cada arista en su
	 * correspondiente nodo para posterioremente almacenarla
	 * Por ejemplo: [(Coordenada_1|Nodo_origen = 1|Nodo_destino = 2|Distancia = 235)|...]
	 * esta funcion, clasifica esa arista que contiene nuestro vector de aristas, pasado
	 * al constructor de la clase y crear el nodo correspondiente a esa arista y almacenarla
	*/
	void Grafo_::construir_nodos(void)
	{
		for (int i = 0; i < numero_nodos; i++)
		{
			Nodo_ nodo(i + 1, vector_coordenadas[i]);
			
			insertar_nodo(nodo);
		}
	}

// // ----------------------------------------------------------------------------------------------
// // ----------------------------------------Metodos setter----------------------------------------
// // ----------------------------------------------------------------------------------------------
// 	void Grafo_::set_aristas(vector<Coordenada_> aristas)
// 	{
// 		vector_coordenadas = aristas;
// 	}
	
	void Grafo_::insertar_nodo(Nodo_ nodo)
	{
		vector_nodos.push_back(nodo);
	}

// // ----------------------------------------------------------------------------------------------
// // ----------------------------------------Metodos getter----------------------------------------
// // ----------------------------------------------------------------------------------------------	
	int Grafo_::get_numero_nodos(void)
	{
		return numero_nodos;
	}

	Nodo_ Grafo_::get_nodo(int posicion)
	{
		return vector_nodos[posicion];
	}

	vector<Nodo_> Grafo_::get_vector_nodos(void)
	{
		return vector_nodos;
	}

// // ----------------------------------------------------------------------------------------
// // ------------------------------ Metodo de impresion del grafo ---------------------------
// // ----------------------------------------------------------------------------------------
	void Grafo_::imprimir_grafo(void)
	{
		for (int nodo = 0; nodo < vector_nodos.size(); nodo++)
		{
			cout << "Nodo: " << vector_nodos[nodo].get_identificador_nodo() << endl;
			cout << "Coordenadas: ";
			
			for (int coordenada = 0; coordenada < vector_nodos[nodo].get_cantidad_coordenadas(); coordenada++)
			{
				cout << vector_nodos[nodo].get_coordenada(coordenada) << ", ";
			}

			cout << endl << "---------------------------------------------------------------------" << endl;
		}
	}

// 	void Grafo_::imprimir_costes(void)
// 	{
// 		for (int nodo = 0; nodo < vector_nodos.size(); nodo++)
// 		{
// 			for (int arista = 0; arista < vector_nodos[nodo].get_cantidad_aristas(); arista++)
// 			{
// 				cout << vector_nodos[nodo].get_coste_arista(arista) << " ";
// 			}

// 			cout << endl;
// 		}
// 	}

// // ----------------------------------------------------------------------------------------
// // ------------------------------ Metodo de eliminacion de nodos --------------------------
// // ----------------------------------------------------------------------------------------
// 	void Grafo_::eliminar_nodo(int nodo)
// 	{
// 		for (int i = 0; i < vector_nodos.size(); i++)
// 		{
// 			if (vector_nodos[i].get_identificador_nodo() == nodo)
// 			{
// 				vector_nodos.erase(vector_nodos.begin() + i);
// 			}
// 		}
// 	}


