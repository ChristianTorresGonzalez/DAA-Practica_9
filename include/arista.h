#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Arista_
{
    public:
        int nodo_inicial;
        int nodo_final;
        float coste;

    public:
        Arista_(void);
        Arista_(int , int , float );

        int get_nodo_inicial(void);
        int get_nodo_destino(void);
        float get_coste_arista(void);

        void set_nodo_inicial(int );
        void set_nodo_final(int );
        void set_coste(float );
        
        bool operator ==(Arista_ );

        void imprimir_arista(void);
};
