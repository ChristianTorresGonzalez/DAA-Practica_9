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
};
