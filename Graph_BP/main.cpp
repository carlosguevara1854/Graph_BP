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

#include <cstdlib>
#include "Graph.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //Test
    Graph g(8);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 5);
    g.addEdge(2, 0);
    g.addEdge(2, 1);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 2);
    g.addEdge(4, 2);
    g.addEdge(4, 5);
    g.addEdge(5, 1);
    g.addEdge(5, 4);
    g.addEdge(5, 6);
    g.addEdge(6, 5);
    g.addEdge(6, 7);
    g.addEdge(7, 6);
    g.BreakingPoint();
    return 0;
}

