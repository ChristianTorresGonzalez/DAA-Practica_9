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
