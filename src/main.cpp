#include <iostream>
#include <vector>
#include <string>

#include "../include/gestora.h"
#include "../include/grafo.h"
#include "../include/algoritmos.h"
#include "../include/algoritmo_voraz.h"

using namespace std;

int main(int argc,char *argv[])
{
  string entrada = argv[1];
  string salida = argv[2];

  Grafo_ grafo;

  Gestor_Archivos_ gestor_archivos(entrada, salida, grafo);
  Algoritmo_Voraz_ algoritmo(grafo);
  //gestor_archivos.mostrar_aristas();

  //cout << grafo.get_numero_nodos();
  // grafo.imprimir_grafo();
  // grafo.imprimir_costes();

  algoritmo.resolver_algoritmo();
  algoritmo.imprimir_solucion();
}
