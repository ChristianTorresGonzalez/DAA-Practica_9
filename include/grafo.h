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
		vector<nodo_> vector_nodos;
		vector<Arista_> vector_aristas;
		
	public:
		Grafo_(void);
		Grafo_(int , vector<Arista_> );
		
		void set_aristas(vector<Arista_> );

		// void insertar_sucesor(int ,pair_t );
		// void insertar(nodo_ );
    
		int get_numero_nodos(void);
		// int get_val(int a);
		// float get_coste_hijo(int );
		// nodo_ get_nodo(int );
		
		// void imprimir_conjunto(void);
		// void insertar_archivo(string );
		
		// nodo_ operator [](int );
};
