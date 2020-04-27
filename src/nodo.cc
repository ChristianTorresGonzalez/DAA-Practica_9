/**
  * @copyright Universidad de La Laguna
  * @copyright Escuela Superior de Ingeniería y Tecnología
  * @copyright Grado en Ingeniería Informática
  * @copyright Asignatura: Diseño y Analisis de Algoritmos (DAA)
  * @copyright Curso: 3º Itinerario 1
  * @copyright Práctica 8. Algoritmos 
  * @author: Christian Torres Gonzalez alu0101137902@ull.edu.es
  * @description: Fichero de la clase Nodo, encargadad de almacenar
  * la informacion referente a cada nodo
  * @since 23/04/2020 
  * @file Fichero de implementacion de la clase Nodo
  * @version 1.0.0
  * @see https://github.com/ChristianTorresGonzalez/DAA_P8.git
*/

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
// ------------------------------ Metodo para encontrar aristas---------------------------
// ---------------------------------------------------------------------------------------
	Arista_ Nodo_::find_arista(int objetivo)
	{
		for (int i = 0; i < aristas.size(); i++)
		{
			if (aristas[i].get_nodo_destino() == objetivo)
			{
				return aristas[i];
			}
		}
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
