/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Graph.h
 * Author: carlos
 *
 * Created on 18 de julio de 2017, 12:33 PM
 */

#ifndef GRAPH_H
#define GRAPH_H
#include <list>
#include <queue>
#include <fstream>
#include <iostream>
#include <vector>
#include <cstdlib>

class Graph {
public:
    Graph();
    Graph(const Graph& orig);
    virtual ~Graph();
    void addEdge(int v, int w);
    void read_names();
    void read_connections();
    void write_BP();
    void BreakingPoint();
private:
    bool isB_Point(bool *visited);
    void BFS(int s, bool *visited);
    int V; //Número de vertices.
    std::list<int> *adj; //Lista de adyacencia.
    std::list<int> *BP; //Lista de nodos determinados como nodo de ruptura.
    std::vector<std::string> split(std::string str, char pattern);
    std::vector<std::string> nom_pla;
};

#endif /* GRAPH_H */

