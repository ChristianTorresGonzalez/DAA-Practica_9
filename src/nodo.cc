#include <iostream>
#include <vector>

#include "../include/nodo.h"

using namespace std;

	Nodo_::Nodo_(void):
		nodo(0),
		generado(0),
		inspeccionado(0)
		{
			aristas.resize(0);
		}
		
	Nodo_::Nodo_(int nodo):
		nodo(nodo),
		generado(0),
		inspeccionado(0)
		{
			aristas.resize(0);
		}	
	
	void Nodo_::insert(int a)
	{
		nodo = a;
	}
	void Nodo_::insertar_arista(Pair_t_ sucesor)
	{
		aristas.push_back(sucesor);
	}
	
	int Nodo_::get_identificador_nodo(void)
	{
		return nodo;
	}
	
	int Nodo_::get_cantidad_aristas(void)
	{
		return aristas.size();
	}
	
	int Nodo_::get_destino_arista(int a)
	{
		return aristas[a].get_hijo();
	}
	
	float Nodo_::get_coste_arista(int a)
	{
		return aristas[a].get_coste_pair();
	}
	
	Pair_t_ Nodo_::get_sucesores(int a)
	{
		return aristas[a];
	}
	
	bool Nodo_::get_inspeccionado(void)
	{
		return inspeccionado;
	}
	
	void Nodo_::set_inspeccionado(bool a)
	{
		inspeccionado = a;
	}
	
	bool Nodo_::is_inspeccionado(void)
	{
		if (inspeccionado == 0)
			return false;
		else
			return true;
	}
	
	bool Nodo_::operator ==(Nodo_ b)
	{
		if (this -> nodo == b.nodo)
			return true;
		
		return false;
	}
