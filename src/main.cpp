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

using namespace std;

int main(int argc,char *argv[])
{
    srand(time(NULL));

    string entrada = argv[1];

    Grafo_ grafo;
    Gestor_Archivos_ gestor_archivos(entrada, grafo);
    
    grafo.imprimir_grafo();
    // grafo.imprimir_costes();

    int soluciones = 2;
    for (int i = 0; i < 4; i++)
    {
        Algoritmo_Voraz_ algoritmo(grafo);
        algoritmo.resolver_algoritmo(soluciones);
        algoritmo.imprimir_solucion("VORAZ");
        soluciones++;
    }

    cout << endl << "-------------------------------------------" << endl;

    soluciones = 2;
    Algoritmo_Voraz_Nuevo_ algoritmo_nuevo(grafo);
    for (int i = 0; i < 4; i++)
    {
        algoritmo_nuevo.resolver_algoritmo(soluciones);
        algoritmo_nuevo.imprimir_soluciones();
        soluciones++;
    }

    cout << endl << "-------------------------------------------" << endl;

    soluciones = 2;
    Algoritmo_BusquedaLocal_ algoritmo_busqueda_local(grafo);
    for (int i = 0; i < 4; i++)
    {
        algoritmo_busqueda_local.resolver_algoritmo(soluciones);
        algoritmo_busqueda_local.imprimir_soluciones();
        soluciones++;
    }

    cout << endl << "-------------------------------------------" << endl;

    soluciones = 2;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 10; j <= 20; j = 2*j)
        {
            for (int k = 2; k <= 3; k++)
            {
                Algoritmo_GRASP_ algoritmo_grasp(grafo, k, j); 
                algoritmo_grasp.resolver_algoritmo(soluciones);
                algoritmo_grasp.imprimir_soluciones();
                soluciones++;
            }
        }

        soluciones = 2;
    }

    // cout << endl << "-------------------------------------------" << endl;

    // int metodo = 0;
    // cout << "Introduzca metodo de ejecucion: ";
    // cin >> metodo;
    // for (int i = 0; i < 5; i++)
    // {
    //     Algoritmo_Multiarranque_ algoritmo_multiarranque(grafo);
    //     if (metodo == 1)
    //     {
    //         algoritmo_multiarranque.resolver_algoritmo_metodo1();  // Metodo 1: Solucion inicial aleatoria y busqueda Grasp
    //     }
    //     else
    //     {
    //         algoritmo_multiarranque.resolver_algoritmo_metodo2();     // Metodo 1: Solucion inicial Grasp y busqueda local aleatoria 
    //     }

    //     algoritmo_multiarranque.imprimir_solucion("MULTIARRANQUE");
    // }

    // cout << endl << "-------------------------------------------" << endl;

    // for (int i = 0; i < 5; i++)
    // {
    //     Algoritmo_VNS_ algoritmo_vns(grafo);
    //     algoritmo_vns.resolver_algoritmo(1000, 3, 0);
    //     algoritmo_vns.imprimir_solucion("VNS");
    // }
    
    // cout << endl << "-------------------------------------------" << endl;

    // for (int i = 0; i < 5; i++)
    // {
    //     Algoritmo_Modificacion_ algoritmo_modificacion(grafo);
    //     algoritmo_modificacion.resolver_algoritmo(1000, 2, 0);
    //     algoritmo_modificacion.imprimir_solucion("Modificacion");
    // }
}
