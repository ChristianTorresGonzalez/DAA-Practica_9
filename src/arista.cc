#include <iostream>
#include <vector>
#include <string>

#include "../include/arista.h"

// --------------------------------------------------------------------
// --------------------------------------------------------------------
	Arista_::Arista_(void)
		{}

	Arista_::Arista_(int inicio,int final,float coste):
		nodo_inicial(inicio),
		nodo_final(final),
		coste(coste)
		{}

// --------------------------------------------------------------------
// --------------------------------------------------------------------	
	int Arista_::get_nodo_inicial(void)
	{
		return nodo_inicial;
	}
	
	int Arista_::get_nodo_final(void)
	{
		return nodo_final;
	}

	float Arista_::get_coste(void)
	{
		return coste;
	}

// --------------------------------------------------------------------
// --------------------------------------------------------------------
	void Arista_::set_nodo_inicial(int nuevo_origen)
	{
		nodo_inicial = nuevo_origen;
	}
	
	void Arista_::set_nodo_final(int nuevo_destino)
	{
		nodo_final = nuevo_destino;
	}

	void Arista_::set_coste(float nuevo_coste)
	{
		coste = nuevo_coste;
	}
// --------------------------------------------------------------------
// --------------------------------------------------------------------
	bool Arista_::operator ==(Arista_ otra_arista)
	{
		if (this -> nodo_inicial == otra_arista.nodo_inicial)
			return true;
		
		return false;
	}
