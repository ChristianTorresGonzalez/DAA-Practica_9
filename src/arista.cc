/**
  * @copyright Universidad de La Laguna
  * @copyright Escuela Superior de Ingeniería y Tecnología
  * @copyright Grado en Ingeniería Informática
  * @copyright Asignatura: Diseño y Analisis de Algoritmos (DAA)
  * @copyright Curso: 3º Itinerario 1
  * @copyright Práctica 8. Algoritmos 
  * @author: Christian Torres Gonzalez alu0101137902@ull.edu.es
  * @description: Fichero de la clase Arista_, encargada de almacenar
  * la informacion relevante a cada arista
  * @since 23/04/2020 
  * @file Fichero de implementacion de la clase Arista_
  * @version 1.0.0
  * @see https://github.com/ChristianTorresGonzalez/DAA_P8.git
*/

#include <iostream>
#include <vector>
#include <string>

#include "../include/arista.h"

// ------------------------------------------------------------------------------------
// ----------------------------------Constructores-------------------------------------
// ------------------------------------------------------------------------------------
	Arista_::Arista_(void)
		{}

	Arista_::Arista_(int inicio,int final,float coste):
		nodo_inicial(inicio),
		nodo_final(final),
		coste(coste)
		{}

// ------------------------------------------------------------------------------------
// ----------------------------------Metodos getter------------------------------------
// ------------------------------------------------------------------------------------
	int Arista_::get_nodo_inicial(void)
	{
		return nodo_inicial;
	}
	
	int Arista_::get_nodo_destino(void)
	{
		return nodo_final;
	}

	float Arista_::get_coste_arista(void)
	{
		return coste;
	}

// ------------------------------------------------------------------------------------
// ----------------------------------Metodos setter------------------------------------
// ------------------------------------------------------------------------------------
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

	void Arista_::imprimir_arista(void)
	{
		cout << nodo_inicial << " - " << nodo_final << " =>" << coste;
	}

// ---------------------------------------------------------------------------------------
// ------------------------------Operador para comparar aristas---------------------------
// ---------------------------------------------------------------------------------------
	bool Arista_::operator ==(Arista_ otra_arista)
	{
		if (this -> nodo_inicial == otra_arista.nodo_inicial)
			return true;
		
		return false;
	}

	
