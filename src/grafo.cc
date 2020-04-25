#include <iostream>
#include <vector>

#include "../include/grafo.h"

using namespace std;

	Grafo_::Grafo_(void):
		numero_nodos(0)
		{
			vector_nodos.resize(0);
		}

	Grafo_::Grafo_(int nodos, vector<Arista_> aristas):
		numero_nodos(nodos),
		vector_aristas(aristas)
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
	 * Por ejemplo: [(Arista_1|Nodo_origen = 1|Nodo_destino = 2|Distancia = 235)|...]
	 * esta funcion, clasifica esa arista que contiene nuestro vector de aristas, pasado
	 * al constructor de la clase y crear el nodo correspondiente a esa arista y almacenarla
	*/
	void Grafo_::construir_nodos(void)
	{
		int inicio = 0;
		for (int i = 1; i <= numero_nodos; i++)
		{
			Nodo_ nodo(i);

			for (int j = inicio; j < (inicio + numero_nodos - 1); j++)
			{
				Arista_ arista(vector_aristas[j].get_nodo_inicial(), vector_aristas[j].get_nodo_destino(), vector_aristas[j].get_coste_arista());
				nodo.insertar_arista(arista);
			}
			
			insertar_nodo(nodo);
			inicio += numero_nodos - 1;
		}
	}

// ----------------------------------------------------------------------------------------------
// ----------------------------------------Metodos setter----------------------------------------
// ----------------------------------------------------------------------------------------------
	void Grafo_::set_aristas(vector<Arista_> aristas)
	{
		vector_aristas = aristas;
	}
	
	void Grafo_::insertar_nodo(Nodo_ nodo)
	{
		vector_nodos.push_back(nodo);
	}

// ----------------------------------------------------------------------------------------------
// ----------------------------------------Metodos getter----------------------------------------
// ----------------------------------------------------------------------------------------------	
	int Grafo_::get_numero_nodos(void)
	{
		return numero_nodos;
	}

	Nodo_ Grafo_::get_nodo(int posicion)
	{
		return vector_nodos[posicion];
	}

// ----------------------------------------------------------------------------------------
// ------------------------------ Metodo de impresion del grafo ---------------------------
// ----------------------------------------------------------------------------------------
	void Grafo_::imprimir_grafo(void)
	{
		for (int nodo = 0; nodo < vector_nodos.size(); nodo++)
		{
			cout << "Nodo: " << vector_nodos[nodo].get_identificador_nodo() << endl;
			for (int arista = 0; arista < vector_nodos[nodo].get_cantidad_aristas(); arista++)
			{
				cout << "	Arista " << arista + 1 << ": Nodo_destino: " << vector_nodos[nodo].get_destino_arista(arista) <<
				        " => " << vector_nodos[nodo].get_coste_arista(arista) << endl;
			}

			cout << "---------------------------------------------------------------------" << endl;
		}
	}

	void Grafo_::imprimir_costes(void)
	{
		for (int nodo = 0; nodo < vector_nodos.size(); nodo++)
		{
			for (int arista = 0; arista < vector_nodos[nodo].get_cantidad_aristas(); arista++)
			{
				cout << vector_nodos[nodo].get_coste_arista(arista) << " ";
			}

			cout << endl;
		}
	}

// ----------------------------------------------------------------------------------------
// ------------------------------ Metodo de eliminacion de nodos --------------------------
// ----------------------------------------------------------------------------------------
	void Grafo_::eliminar_nodo(int nodo)
	{
		for (int i = 0; i < vector_nodos.size(); i++)
		{
			if (vector_nodos[i].get_identificador_nodo() == nodo)
			{
				vector_nodos.erase(vector_nodos.begin() + i);
			}
		}
	}


