/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: carlos
 *
 * Created on 18 de julio de 2017, 12:33 PM
 */

#include "Graph.h"

/*
 * 
 */

int main(int argc, char** argv) {
    Graph grafo; //Creación del objeto de tipo (Graph).
    grafo.BreakingPoint(); //Se determinan los nodos de ruptura del grafo.
    grafo.write_BP(); //Se escribe en el archivo de salida "ruptura.txt".
    grafo.~Graph(); //Free memory.
    return 0;
}

