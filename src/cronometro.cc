#include <iostream>
#include <vector>
#include <string>
#include <chrono>

#include "../include/cronometro.h" 

using namespace std;

        Cronometro_::Cronometro_()
            {}

        void Cronometro_::start()
        {
            inicio = chrono::system_clock::now();
        }


        void Cronometro_::end()
        {
            fin = std::chrono::system_clock::now();
        }

        float Cronometro_::tiempo_transcurrido()
        {
            chrono::duration<float, milli> duration = (fin - inicio) / 1000;
            return duration.count();
        }
