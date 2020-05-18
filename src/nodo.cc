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
		tiempo_tabu(0),
		coordenadas()
		{}
		
	Nodo_::Nodo_(int nodo, Coordenada_ coordenada):
		nodo(nodo),
		tiempo_tabu(0),
		coordenadas(coordenada)
		{}	

// ----------------------------------------------------------------------------------------------
// ------------------------------Metodos insert para almacenar datos-----------------------------
// ----------------------------------------------------------------------------------------------
	void Nodo_::insertar_identificador(int identificador)
	{
		nodo = identificador;
	}

	void Nodo_::insertar_coordenada(int posicion, float x)
	{
		coordenadas.insertar_coordenada(posicion, x);
	}
	
	void Nodo_::insertar_tiempo_tabu(int tiempo)
	{
		tiempo_tabu = tiempo;
	}

// ---------------------------------------------------------------------------------------------
// --------------------------------- Metodos getter de la clase --------------------------------
// ---------------------------------------------------------------------------------------------	
	int Nodo_::get_identificador_nodo(void)
	{
		return nodo;
	}
	
	int Nodo_::get_cantidad_coordenadas(void)
	{
		return coordenadas.get_cantidad_coordenadas();
	}

	int Nodo_::get_tiempo_tabu(void)
	{
		return tiempo_tabu;
	}

	float Nodo_::get_coordenada(int posicion)
	{
		return coordenadas.get_coordenada(posicion);
	}