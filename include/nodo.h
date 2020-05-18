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

#pragma once

#include <iostream>
#include <vector>

#include "./coordenada.h"

using namespace std;

class Nodo_
{
	private:
		short int nodo;
        int tiempo_tabu;
		Coordenada_ coordenadas;
		
	public:
		Nodo_(void);
		Nodo_(int , Coordenada_ );
		
		void insertar_identificador(int );
		void insertar_coordenada(int , float );
		void insertar_tiempo_tabu(int );

		int get_identificador_nodo(void);
		int get_cantidad_coordenadas(void);
		int get_tiempo_tabu(void);
		float get_coordenada(int );
};
