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

	void Grafo_::construir_nodos(void)
	{
		int inicio = 0;
		for (int i = 1; i <= numero_nodos; i++)
		{
			Nodo_ nodo(i);

			for (int j = inicio; j < (inicio + numero_nodos - 1); j++)
			{
				Pair_t_ arista(vector_aristas[j].get_nodo_final(), vector_aristas[j].get_coste());
				nodo.insertar_arista(arista);
			}
			
			insertar_nodo(nodo);
			inicio += numero_nodos - 1;
		}
	}

	void Grafo_::set_aristas(vector<Arista_> aristas)
	{
		vector_aristas = aristas;
	}
	
	void Grafo_::insertar_nodo(Nodo_ nodo)
	{
		vector_nodos.push_back(nodo);
	}
	
	// void Grafo_::insertar_sucesor(int i,pair_t nodos)
	// {
	// 	vector_nodos[i].insertar_nodo_hijo(nodos);
	// }
	
	int Grafo_::get_numero_nodos(void)
	{
		return numero_nodos;
	}
	
	
	
	// int Grafo_::get_val(int i)
	// {
	// 	return vector_nodos[i].get_nodo();
	// }
	
	// float Grafo_::get_coste_hijo(int a)
	// {
	// 	return get_coste_hijo(a);
	// }
	
	// nodo_ Grafo_::get_nodo(int a)
	// {
	// 	return vector_nodos[a];
	// }
	
	// nodo_ Grafo_::operator [](int i)
	// {
	// 	return vector_nodos[i];
	// }

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
