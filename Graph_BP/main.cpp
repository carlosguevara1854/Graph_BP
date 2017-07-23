/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: carlos
 * GitHub repository: https://github.com/carlosguevara1854/Graph_BP
 * Created on 18 de julio de 2017, 12:33 PM
 */

#include "Graph.h"

/*
 * 
 */

int main(int argc, char** argv) {
    Graph grafo;
    grafo.BreakingPoint(); //Se determinan los nodos de ruptura.
    grafo.write_BP(); //Se escribe en el archivo de salida.
    return 0;
}

