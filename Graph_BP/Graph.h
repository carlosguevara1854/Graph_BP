/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Graph.h
 * Author: carlos
 * GitHub repository: https://github.com/carlosguevara1854/Graph_BP
 * Created on 18 de julio de 2017, 12:33 PM
 */

#ifndef GRAPH_H
#define GRAPH_H
#include <fstream>
#include <list>
#include <vector>
#include <iostream>
#include <string>

class Graph {
public:
    Graph();
    Graph(const Graph& orig);
    virtual ~Graph();
    void BreakingPoint();
    void write_BP();
private:
    bool isB_Point(bool* visited);
    void BFS(int s, bool* visited);
    int V; //Número de vertices.
    std::list<int>* adj; //Lista de adyacencia.
    std::vector<std::string> BP; //Contenedor de nodos determinados como nodo de ruptura.
    std::vector<std::string> split(std::string str, char pattern);
    std::vector<std::string> nom_pla; //Contenedor de los nombres de los nodos. (planetas)
    void addEdge(int v, int w);
    void read_names();
    void read_connections();
};

#endif /* GRAPH_H */

