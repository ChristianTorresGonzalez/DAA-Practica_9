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
		numero_nodos(nodos)
		{
			vector_nodos.resize(nodos);
		}

	void Grafo_::set_aristas(vector<Arista_> aristas)
	{
		vector_aristas = aristas;
	}
	
	// void Grafo_::insertar(nodo_ nodos)
	// {
	// 	vector_nodos.push_back(nodos);
	// }
	
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
