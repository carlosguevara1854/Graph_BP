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
Graph::Graph() {
    read_names();
    this->V = nom_pla.size();
    this->adj = new std::list<int>[V];
    this->BP = new std::list<int>[V];
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
 * Método que determina los puntos de ruptura de un grafo conexo.
 * 
 * @see isB_Point(bool* visited)
 * @see BFS(int s, bool *visited)
 */
void Graph::BreakingPoint() {
    bool* visited = new bool[V];
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
    delete(visited);
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

void Graph::read_names() {
    std::ifstream mapa_nombres("mapa_nombres.txt");
    std::string c = ", ";
    std::vector<std::string> aux;
    std::string content;
    if (!mapa_nombres.fail()) {
        int i = 0, j = 0;
        while (std::getline(mapa_nombres, content)) {
            this->nom_pla = split(content, c[0]);
        }
    }
    mapa_nombres.close();
}

void Graph::read_connections() {
    std::ifstream mapa_conexiones("mapa_conexiones.txt");
    std::string c = ", ";
    std::vector<std::string> aux_fila_matrix;
    std::vector<int> fila_matrix;
    int matrix[V][V];
    std::string content;
    if (!mapa_conexiones.fail()) {
        int j = 0;
        while (std::getline(mapa_conexiones, content)) {
            aux_fila_matrix = split(content, c[1]);
            for (int i = 0; i < aux_fila_matrix.size(); i++) {
                fila_matrix[i] = std::stoi(aux_fila_matrix[i]);
                matrix[j][i] = fila_matrix[i];
            }
            j++;
        }
    }
    mapa_conexiones.close();
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (matrix[i][j] == 1) {
                addEdge(i, j);
            }
        }
    }
}

std::vector<std::string> Graph::split(std::string str, char pattern) {
    int posInit = 0;
    int posFound = 0;
    std::string splitted;
    std::vector<std::string> resultados;

    while (posFound >= 0) {
        posFound = str.find(pattern, posInit);
        splitted = str.substr(posInit, posFound - posInit);
        posInit = posFound + 1;
        resultados.push_back(splitted);
    }
    return resultados;
}

