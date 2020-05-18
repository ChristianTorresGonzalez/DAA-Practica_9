/**
  * @copyright Universidad de La Laguna
  * @copyright Escuela Superior de Ingeniería y Tecnología
  * @copyright Grado en Ingeniería Informática
  * @copyright Asignatura: Diseño y Analisis de Algoritmos (DAA)
  * @copyright Curso: 3º Itinerario 1
  * @copyright Práctica 8. Algoritmos 
  * @author: Christian Torres Gonzalez alu0101137902@ull.edu.es
  * @description: Fichero de implementacion del programa principal
  * @since 23/04/2020 
  * @file Fichero de implementacion de la clase Algoritmo_Multiarranque
  * @version 1.0.0
  * @see https://github.com/ChristianTorresGonzalez/DAA_P8.git
*/

#include <iostream>
#include <vector>
#include <string>

#include "../include/gestora.h"
#include "../include/grafo.h"
#include "../include/algoritmos.h"
#include "../include/algoritmo_voraz.h"
#include "../include/algoritmo_voraz_nuevo.h"
#include "../include/algoritmo_busqueda_local.h"
#include "../include/algoritmo_grasp.h"
#include "../include/algoritmo_busqueda_tabu.h"


using namespace std;

int main(int argc,char *argv[])
{
    srand(time(NULL));

    string entrada = argv[1];

    Grafo_ grafo;
    Gestor_Archivos_ gestor_archivos(entrada, grafo);
    
    grafo.imprimir_grafo();

    for (int soluciones = 2; soluciones <= 5; soluciones++)
    {
        Algoritmo_Voraz_ algoritmo(grafo);
        algoritmo.resolver_algoritmo(soluciones);
        algoritmo.imprimir_solucion("VORAZ");
    }

    cout << endl << "-------------------------------------------" << endl;

    Algoritmo_Voraz_Nuevo_ algoritmo_nuevo(grafo);
    for (int soluciones = 2; soluciones <= 5; soluciones++)
    {
        algoritmo_nuevo.resolver_algoritmo(soluciones);
        algoritmo_nuevo.imprimir_soluciones();
    }

    cout << endl << "-------------------------------------------" << endl;

    Algoritmo_BusquedaLocal_ algoritmo_busqueda_local(grafo);
    for (int soluciones = 2; soluciones <= 5; soluciones++)
    {
        algoritmo_busqueda_local.resolver_algoritmo(soluciones);
        algoritmo_busqueda_local.imprimir_soluciones();
    }

    cout << endl << "-------------------------------------------" << endl;

    // soluciones = 2;
    for (int soluciones = 2; soluciones <= 5; soluciones++)
    {
        for (int j = 10; j <= 20; j = 2*j)
        {
            for (int k = 2; k <= 3; k++)
            {
                Algoritmo_GRASP_ algoritmo_grasp(grafo, k, j); 
                algoritmo_grasp.resolver_algoritmo(soluciones);
                algoritmo_grasp.imprimir_soluciones();    
            }
        }
    }

    cout << endl << "-------------------------------------------" << endl;

    for (int soluciones = 2; soluciones <= 5; soluciones++)
    {
        for (int j = 10; j <= 20; j = 2*j)
        {
            for (int k = 2; k <= 3; k++)
            {
                Algoritmo_Busqueda_Tabu_ algoritmo_tabu(grafo, j, k); 
                algoritmo_tabu.resolver_algoritmo(soluciones);
                algoritmo_tabu.imprimir_soluciones();
            }
        }
    }
}
