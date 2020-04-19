#include <iostream>
#include <vector>

#include "../include/nodo.h"

using namespace std;

	nodo_::nodo_(void):
		nodo(0),
		generado(0),
		inspeccionado(0)
		{
			sucesores.resize(0);
		}
		
	nodo_::nodo_(int nodo):
		nodo(nodo),
		generado(0),
		inspeccionado(0)
		{
			sucesores.resize(0);
		}	
	
	void nodo_::insert(int a)
	{
		nodo = a;
	}
	void nodo_::insertar_nodo_hijo(pair_t sucesor)
	{
		sucesores.push_back(sucesor);
	}
	
	int nodo_::get_nodo(void)
	{
		return nodo;
	}
	
	int nodo_::get_size_sucesores(void)
	{
		return sucesores.size();
	}
	
	int nodo_::get_nodo_hijo(int a)
	{
		return sucesores[a].get_hijo();
	}
	
	float nodo_::get_coste_hijo(int a)
	{
		return sucesores[a].get_coste_pair();
	}
	
	pair_t nodo_::get_sucesores(int a)
	{
		return sucesores[a];
	}
	
	bool nodo_::get_inspeccionado(void)
	{
		return inspeccionado;
	}
	
	void nodo_::set_inspeccionado(bool a)
	{
		inspeccionado = a;
	}
	
	bool nodo_::is_inspeccionado(void)
	{
		if (inspeccionado == 0)
			return false;
		else
			return true;
	}
	
	bool nodo_::operator ==(nodo_ b)
	{
		if (this -> nodo == b.nodo)
			return true;
		
		return false;
	}
