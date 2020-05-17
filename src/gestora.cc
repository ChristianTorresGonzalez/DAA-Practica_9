/**
  * @copyright Universidad de La Laguna
  * @copyright Escuela Superior de Ingeniería y Tecnología
  * @copyright Grado en Ingeniería Informática
  * @copyright Asignatura: Diseño y Analisis de Algoritmos (DAA)
  * @copyright Curso: 3º Itinerario 1
  * @copyright Práctica 8. Algoritmos 
  * @author: Christian Torres Gonzalez alu0101137902@ull.edu.es
  * @description: Fichero de la clase gestora, encargada de leer los
  * datos del archivo, tratarlos, almacenarlos y pasarselos al grafo
  * que se utilizara para la resolucion de los algoritmos
  * @since 23/04/2020 
  * @file Fichero de implementacion de la clase Gestora
  * @version 1.0.0
  * @see https://github.com/ChristianTorresGonzalez/DAA_P8.git
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "../include/gestora.h"

	Gestor_Archivos_::Gestor_Archivos_(string entrada, Grafo_ &grafo)
		{
			archivo1.open(entrada);

			if (archivo1.fail())
				cout << "Fallo en la aperura del archivo de entrada" << endl;
			else
				cout << "Apertura de archivo del grafo de entrada con exito" << endl;

			cargar_datos(grafo);
		}

//--------------------------------------------------------------------------------------------	
//----------------------------------Funcion almacenar los datos-------------------------------	
//--------------------------------------------------------------------------------------------	
	/**
	 * @brief Funcion encargadad de cargar los datos del archivo de entrada a una variable
	 * y ya desde ahi, cargarlos en el grafo, que se ha pasado como referencia
	 * @param grafo Grafo que se va a utilizar en el problema
	 */
	void Gestor_Archivos_::cargar_datos(Grafo_ &grafo)
	{
		int numero_nodos;
		int  cantidad_coordenadas;
		float x;
		vector<vector<float>> coordenadas;

		archivo1 >> numero_nodos;
		archivo1 >> cantidad_coordenadas;

		for (int i = 0; i < numero_nodos; i++) 
		{
			vector<float> coord;
			for (int j = 0; j < cantidad_coordenadas; j++)
			{
				archivo1 >> x;
				coord.push_back(x);
			}

			coordenadas.push_back(coord);
		}

		grafo = Grafo_(numero_nodos, coordenadas);
		// mostrar_coordenadas(coordenadas);
	}
	
//--------------------------------------------------------------------------------------------	
//----------------------------------Funcion para ordenar aristas------------------------------	
//--------------------------------------------------------------------------------------------	
	/**
	 * @brief Funcion encargadad de mostrar todas las aristas cargadas desde el archivo
	 */
	void Gestor_Archivos_::mostrar_coordenadas(vector<vector<float>> coordenadas)
	{
		for (int nodo = 0; nodo < coordenadas.size(); nodo++)
		{
			cout << "Coordenadas: ";
			
			for (int coordenada = 0; coordenada < coordenadas[nodo].size(); coordenada++)
			{
				cout << coordenadas[nodo][coordenada] << ", ";
			}

			cout << endl << "---------------------------------------------------------------------" << endl;
		}
	}