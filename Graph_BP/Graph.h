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

class Graph {
public:
    Graph(int V);
    Graph(const Graph& orig);
    virtual ~Graph();
    //
    void addEdge(int v, int w);
    void BreakingPoint();
    void BFS(int s, bool *visited);
private:
    bool isB_Point(bool *visited);
    int V; //Número de vertices.
    std::list<int> *adj; //Lista de adyacencia.
    std::list<int> *BP; //Lista de nodos determinados como nodo de ruptura.
};

#endif /* GRAPH_H */

