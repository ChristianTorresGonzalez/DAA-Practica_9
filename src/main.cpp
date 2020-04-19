#include <iostream>
#include <vector>
#include <string>

#include "../include/gestora.h"
#include "../include/grafo.h"

using namespace std;

int main(int argc,char *argv[])
{
  string entrada = argv[1];
  string salida = argv[2];

  Grafo_ grafo;

  Gestor_Archivos_ gestor_archivos(entrada, salida, grafo);
  // gestor_archivos.mostrar_aristas();

  cout << grafo.get_numero_nodos();
  grafo.imprimir_grafo();
}
