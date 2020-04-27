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
#include "../include/algoritmo_nuevo.h"
#include "../include/algoritmo_grasp.h"
#include "../include/algoritmo_multiarranque.h"

using namespace std;

int main(int argc,char *argv[])
{
  srand(time(NULL));

  string entrada = argv[1];
  string salida = argv[2];

  Grafo_ grafo;

  Gestor_Archivos_ gestor_archivos(entrada, salida, grafo);
  
  // grafo.imprimir_grafo();
  // grafo.imprimir_costes();

  cout << endl;

  for (int i = 0; i < 5; i++)
  {
    Algoritmo_Voraz_ algoritmo(grafo);
    algoritmo.resolver_algoritmo();
    algoritmo.imprimir_solucion("VORAZ");
  }

  cout << endl << "-------------------------------------------" << endl;

  for (int i = 0; i < 5; i++)
  {
    Algoritmo_Nuevo_ algoritmo_nuevo(grafo);
    algoritmo_nuevo.resolver_algoritmo();
    algoritmo_nuevo.imprimir_solucion("NUEVO");
  }

  cout << endl << "-------------------------------------------" << endl;

  for (int i = 0; i < 5; i++)
  {
    Algoritmo_GRASP_ algoritmo_grasp(grafo, 3, 1, 1000);
    algoritmo_grasp.resolver_algoritmo(0);
    algoritmo_grasp.imprimir_solucion("GRASP");
  }

  cout << endl << "-------------------------------------------";

  for (int i = 0; i < 5; i++)
  {
    Algoritmo_Multiarranque_ algoritmo_multiarranque(grafo);
    algoritmo_multiarranque.resolver_algoritmo_metodo1();
    // algoritmo_multiarranque.resolver_algoritmo_metodo2();
    algoritmo_multiarranque.imprimir_solucion("MULTIARRANQUE");
  }
}
