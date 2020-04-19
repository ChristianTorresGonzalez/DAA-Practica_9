#include <iostream>
#include <vector>
#include <string>

using namespace std;

class tupla_busqueda_
{
public:
    int nodo_inicial;
    float coste_actual;
    vector<int> camino;
    
    float coste_camino;

  public:
    tupla_busqueda_(void);
	tupla_busqueda_(int ,int ,float);
	tupla_busqueda_(int ,float ,vector<int> ,float);
    
    int get_nodo_inicial(void);
    float get_coste_actual(void);
    vector<int> get_camino(void);
    float get_coste_camino();
    int get_camino_size(void);
    int get_nodo_camino(int );
    
    void set_camino(int );
    void set_coste_camino(float );
};
