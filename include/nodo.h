#pragma once

#include <iostream>
#include <vector>

#include "./arista.h"

using namespace std;

class Nodo_
{
	private:
		short int nodo;
		bool inspeccionado;
		
		vector<Arista_> aristas;
		
	public:
		Nodo_(void);
		Nodo_(int );
		
		void insertar_identificador(int );	
		void insertar_arista(Arista_ );
		void insertar_inspeccionado(bool);

		int get_identificador_nodo(void);
		int get_cantidad_aristas(void);

		Arista_ find_arista(int );
		
		Arista_ get_arista(int );
		int get_destino_arista(int );
		float get_coste_arista(int );
		
		bool is_inspeccionado(void);
		
		bool operator ==(Nodo_ );
};
