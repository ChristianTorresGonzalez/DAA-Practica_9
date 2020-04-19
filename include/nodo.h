#pragma once

#include <iostream>
#include <vector>

#include "pair.h"

using namespace std;

class nodo_
{
	private:
		short int nodo;
		bool generado;
		bool inspeccionado;
		
		vector<pair_t> sucesores;
		
	public:
		nodo_(void);
		nodo_(int );
		
		void insert(int );
		
		void insertar_nodo_hijo(pair_t );
		int get_nodo(void);
		int get_size_sucesores(void);
		int get_nodo_hijo(int );
		bool get_inspeccionado(void);
		float get_coste_hijo(int );
		pair_t get_sucesores(int );
		
		void set_inspeccionado(bool);
		bool is_inspeccionado(void);
		
		bool operator ==(nodo_ );
};
