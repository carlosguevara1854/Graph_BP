/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Graph.cpp
 * Author: carlos
 * 
 * Created on 18 de julio de 2017, 12:33 PM
 */

#include "Graph.h"

/*
 * Contructor de la clase.
 * 
 * @param V Numero de vertices.
 */
Graph::Graph(int V) {
    this->V = V;
    this->adj = new std::list<int>[V];
}

Graph::Graph(const Graph& orig) {
}

Graph::~Graph() {
}

/*
 * Método que agrega una conexión entre nodos.
 * 
 * @param v Nodo al que se le agrega la conexión (w).
 * @param w Conexion que se le agrega al nodo (v).
 */
void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

/*
 * Método que realiza el recorrido BFS sobre el grafo, a partir de un nodo.
 * 
 * @param s Nodo desde el cual se empieza el recorrido.
 * @param visited Array que indica los nodos visitados.  (true recorrido, false 
 * todo lo contrario)
 */
void Graph::BFS(int s, bool *visited) {
    std::list<int> queue; //Cola para realizar el recorrido.
    visited[s] = true;
    queue.push_back(s);
    std::list<int>::iterator i;
    //Se realiza el ciclo while mientras la cola no este vacía.
    while (!queue.empty()) {
        s = queue.front();
        queue.pop_front();
        for (i = adj[s].begin(); i != adj[s].end(); ++i) {
            //Si no ha sido recorrido, se agrega como recorrido, y se encola.
            if (!visited[*i]) {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

/*
 * Metodo que determina los puntos de ruptura de un grafo conexo.
 * 
 * @see isB_Point(bool* visited)
 * @see BFS(int s, bool *visited)
 */
void Graph::BreakingPoint() {
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++) {
        if ((i + 1) < V) {
            //Se coloca todos los nodos como no visitado. (false)
            for (int j = 0; j < V; j++) {
                visited[j] = false;
            }
            //Se coloca el nodo actual como visitado.
            visited[i] = true;
            //Se aplica el recorrido BFS desde el siquiente nodo.
            BFS(i + 1, visited);
            //Se verifca si todo los nodos fueron recorridos.
            if (isB_Point(visited)) {
                //Si el nodo determina un nodo de ruptura se guarda.
                BP->push_back(i);
            }
        }
    }
}

/**
 * Método que verifica si fueron recorrido todos los nodos.
 * 
 * @param visited Array de nodos visitados.
 * @return True: encontro un nodo no recorrido, False: todos fueron recorridos.
 */
bool Graph::isB_Point(bool* visited) {
    bool enc = false;
    for (int j = 0; j < V; j++) {
        if (visited[j] == false) {
            return true;
        }
    }
    return enc;
}

