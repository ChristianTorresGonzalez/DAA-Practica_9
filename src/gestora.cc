#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "../include/gestora.h"

	Gestor_Archivos_::Gestor_Archivos_(string entrada, string salida, Grafo_ &grafo)
		{
			archivo1.open(entrada);
			archivo2.open(salida);

			if (archivo1.fail())
				cout << "Fallo en la aperura del archivo de entrada" << endl;
			else
				cout << "Apertura de archivo del grafo de entrada con exito" << endl;

			cargar_datos(grafo);
		}

	void Gestor_Archivos_::cargar_datos(Grafo_ &grafo)
	{
		int numero_nodos;
		float distancia;
		int nodo_origen = 1;
		int nodo_destino = 2;

		archivo1 >> numero_nodos;

		while(archivo1 >> distancia)
		{
			if (nodo_destino > numero_nodos)
			{
				nodo_origen++;
				nodo_destino = nodo_origen + 1;
			}

			Arista_ arista_ida(nodo_origen,nodo_destino,distancia);
			Arista_ arista_vuelta(nodo_destino,nodo_origen,distancia);
			vector_aristas.push_back(arista_ida);
			vector_aristas.push_back(arista_vuelta);

			nodo_destino++;
		}

		ordenar_aristas(numero_nodos);
		grafo = Grafo_(numero_nodos, vector_aristas);

	}
	
//------------------------------------------------------------------------------------------------------------------------------------------	
//------------------------------------------------------------------------------------------------------------------------------------------	
	void Gestor_Archivos_::ordenar_aristas(int nodos)
	{
		vector<Arista_> vector_aristas_auxiliar;

		for (int i = 1; i <= nodos; i++)
		{
			for (int j = 0; j < vector_aristas.size();)
			{
				if (vector_aristas[j].get_nodo_inicial() == i)
				{
					vector_aristas_auxiliar.push_back(vector_aristas[j]);
					vector_aristas.erase(vector_aristas.begin() + j);
					j = 0;
				}
				else
				{
					j++;
				}			
			}
		}

		vector_aristas = vector_aristas_auxiliar;
	}
	
	void Gestor_Archivos_::mostrar_aristas(void)
	{
		for (int i = 0; i < vector_aristas.size(); i++)
			cout << vector_aristas[i].get_nodo_inicial() << " - " << vector_aristas[i].get_nodo_final() << " => " << vector_aristas[i].get_coste() << endl;
	}