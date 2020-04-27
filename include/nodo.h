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
