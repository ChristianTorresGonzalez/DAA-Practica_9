#include <iostream>
#include <vector>

#include "../include/nodo.h"

using namespace std;

	Nodo_::Nodo_(void):
		nodo(0),
		inspeccionado(0)
		{
			aristas.resize(0);
		}
		
	Nodo_::Nodo_(int nodo):
		nodo(nodo),
		inspeccionado(0)
		{
			aristas.resize(0);
		}	

// ----------------------------------------------------------------------------------------------
// ------------------------------Metodos insert para almacenar datos-----------------------------
// ----------------------------------------------------------------------------------------------
	void Nodo_::insertar_identificador(int identificador)
	{
		nodo = identificador;
	}

	void Nodo_::insertar_arista(Arista_ arista)
	{
		aristas.push_back(arista);
	}

	void Nodo_::insertar_inspeccionado(bool a)
	{
		inspeccionado = a;
	}

// ---------------------------------------------------------------------------------------------
// --------------------------------- Metodos getter de la clase --------------------------------
// ---------------------------------------------------------------------------------------------	
	int Nodo_::get_identificador_nodo(void)
	{
		return nodo;
	}
	
	int Nodo_::get_cantidad_aristas(void)
	{
		return aristas.size();
	}
	
	int Nodo_::get_destino_arista(int indice)
	{
		return aristas[indice].get_nodo_destino();
	}
	
	float Nodo_::get_coste_arista(int a)
	{
		return aristas[a].get_coste_arista();
	}
	
	Arista_ Nodo_::get_arista(int a)
	{
		return aristas[a];
	}
	
// --------------------------------------------------------------------------------------------------	
// --------------------------------- Metodos para comprobar inspeccionado ---------------------------
// --------------------------------------------------------------------------------------------------
	bool Nodo_::is_inspeccionado(void)
	{
		if (inspeccionado == 0)
			return false;
		else
			return true;
	}
	
// ---------------------------------------------------------------------------------------
// ------------------------------Operador para comparar nodos-----------------------------
// ---------------------------------------------------------------------------------------
	bool Nodo_::operator ==(Nodo_ b)
	{
		if (this -> nodo == b.nodo)
			return true;
		
		return false;
	}
