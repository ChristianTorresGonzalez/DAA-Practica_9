#pragma once

#include <iostream>
#include <vector>

#include "pair.h"

using namespace std;

class Nodo_
{
	private:
		short int nodo;
		bool generado;
		bool inspeccionado;
		
		vector<Pair_t_> aristas;
		
	public:
		Nodo_(void);
		Nodo_(int );
		
		void insert(int );
		
		void insertar_arista(Pair_t_ );

		int get_identificador_nodo(void);
		int get_cantidad_aristas(void);
		bool get_inspeccionado(void);
		
		int get_destino_arista(int );
		float get_coste_arista(int );

		Pair_t_ get_sucesores(int );
		
		void set_inspeccionado(bool);
		bool is_inspeccionado(void);
		
		bool operator ==(Nodo_ );
};
