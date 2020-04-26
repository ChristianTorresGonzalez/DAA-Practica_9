#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <chrono>

using namespace std;

class Cronometro_
{
    public:
        chrono::time_point<chrono::system_clock> inicio;
        chrono::time_point<chrono::system_clock> fin;

    public:
        Cronometro_();

        void start();
        void end();
        float tiempo_transcurrido();
};
