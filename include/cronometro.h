/**
  * @copyright Universidad de La Laguna
  * @copyright Escuela Superior de Ingeniería y Tecnología
  * @copyright Grado en Ingeniería Informática
  * @copyright Asignatura: Diseño y Analisis de Algoritmos (DAA)
  * @copyright Curso: 3º Itinerario 1
  * @copyright Práctica 8. Algoritmos 
  * @author: Christian Torres Gonzalez alu0101137902@ull.edu.es
  * @description: Fichero de la clase Cronometro, encargada de contabilizar
  * el tiempo que ha tardado el programa en realizar la ejecucion
  * @since 23/04/2020 
  * @file Fichero de implementacion de la clase Cronometro
  * @version 1.0.0
  * @see https://github.com/ChristianTorresGonzalez/DAA_P8.git
*/

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
