#pragma once

#include <iostream>

using namespace std;

class Pair_t_
{
	private:
		int nodo_hijo;
		float coste;

	public:
		Pair_t_(void):
			nodo_hijo(0),
			coste(0.0)
			{}

		Pair_t_(int a,float b):
			nodo_hijo(a),
			coste(b)
			{}
			
		void insertar_hijo(int a,float b)
		{
			nodo_hijo = a;
			coste = b;
		}
		
		int get_hijo(void)
		{
			return nodo_hijo;
		}
		
		float get_coste_pair(void)
		{
			return coste;
		}
};
