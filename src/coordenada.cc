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

#include "../include/coordenada.h"

using namespace std;

	Coordenada_::Coordenada_(void)
		{
			coordenadas.resize(0);
		}

	Coordenada_::Coordenada_(int size)
		{
			coordenadas.resize(size);
			for (int i = 0; i < size; i++)
			{
				coordenadas[i] = 0;
				// insertar_coordenada(i, 0);
			}
		}
		
	Coordenada_::Coordenada_(vector<float> coordenada):
		coordenadas(coordenada)
		{}	

// ----------------------------------------------------------------------------------------------
// ------------------------------Metodos insert para almacenar datos-----------------------------
// ----------------------------------------------------------------------------------------------
	void Coordenada_::insertar_coordenada(int posicion, float x)
	{
		coordenadas[posicion] = x;
	}

// ---------------------------------------------------------------------------------------------
// --------------------------------- Metodos getter de la clase --------------------------------
// ---------------------------------------------------------------------------------------------	
	int Coordenada_::get_cantidad_coordenadas(void)
	{
		return coordenadas.size();
	}

	float Coordenada_::get_coordenada(int posicion)
	{
		return coordenadas[posicion];
	}