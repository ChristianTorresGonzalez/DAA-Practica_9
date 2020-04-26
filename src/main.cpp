#include <iostream>
#include <vector>
#include <string>

#include "../include/gestora.h"
#include "../include/grafo.h"
#include "../include/algoritmos.h"
#include "../include/algoritmo_voraz.h"
#include "../include/algoritmo_nuevo.h"
#include "../include/algoritmo_grasp.h"

using namespace std;

int main(int argc,char *argv[])
{
  srand(time(NULL));

  string entrada = argv[1];
  string salida = argv[2];

  Grafo_ grafo;

  Gestor_Archivos_ gestor_archivos(entrada, salida, grafo);
  Algoritmo_Voraz_ algoritmo(grafo);
  Algoritmo_Nuevo_ algoritmo_nuevo(grafo);
  // grafo.imprimir_grafo();
  // grafo.imprimir_costes();

  algoritmo.resolver_algoritmo();
  algoritmo.imprimir_solucion();

  algoritmo_nuevo.resolver_algoritmo();
  algoritmo_nuevo.imprimir_solucion();

  for (int i = 0; i < 5; i++)
  {
    Algoritmo_GRASP_ algoritmo_grasp(grafo, 5, 1, 1000);
    algoritmo_grasp.resolver_algoritmo();
    algoritmo_grasp.imprimir_solucion();
  }
}
