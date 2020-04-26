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

  for (int i = 0; i < 5; i++)
  {
    Algoritmo_Voraz_ algoritmo(grafo);
    algoritmo.resolver_algoritmo();
    algoritmo.imprimir_solucion();
  }

  // for (int i = 0; i < 5; i++)
  // {
  //   Algoritmo_Nuevo_ algoritmo_nuevo(grafo);
  //   algoritmo_nuevo.resolver_algoritmo();
  //   algoritmo_nuevo.imprimir_solucion();
  // }

  // for (int i = 0; i < 5; i++)
  // {
  //   Algoritmo_GRASP_ algoritmo_grasp(grafo, 2, 1, 1000);
  //   algoritmo_grasp.resolver_algoritmo(0);
  //   algoritmo_grasp.imprimir_solucion();
  // }

  for (int i = 0; i < 5; i++)
  {
    Algoritmo_Multiarranque_ algoritmo_multiarranque(grafo);
    // algoritmo_multiarranque.resolver_algoritmo_metodo1();
    algoritmo_multiarranque.resolver_algoritmo_metodo2();
    algoritmo_multiarranque.imprimir_solucion();
  }
}
