/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Graph.cpp
 * Author: carlos
 * GitHub repository: https://github.com/carlosguevara1854/Graph_BP
 * Created on 18 de julio de 2017, 12:33 PM
 */

#include "Graph.h"

/**
 * Contructor de la clase.
 */
Graph::Graph() {
    //Se lee la primera línea del archivo "mapa.txt"; se almacenan los nombres
    //en (nom_pla).
    read_names();
    //De acuerdo a la cantidad de nombres, es decir la cantidad de planetas, se
    //reserva memoria con la misma cantidad.
    this->V = nom_pla.size();
    this->adj = new std::list<int>[V];
    //Se leen las conexiones en tre los nodos (planetas), en el archivo
    //"mapa.txt", también se hace un llenado de la lista de adyacencia.
    read_connections();
}

/**
 * 
 * Copy constructor.
 * 
 * @param orig
 */
Graph::Graph(const Graph& orig) {
}

/**
 * Free memory
 */
Graph::~Graph() {
    delete[] adj;
}

/**
 * Método que agrega una conexión entre nodos.
 * 
 * @param v Nodo al que se le agrega la conexión (w).
 * @param w Conexion que se le agrega al nodo (v).
 */
void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

/**
 * Método que realiza el recorrido BFS sobre el grafo, a partir de un nodo.
 * 
 * @param s Nodo desde el cual se empieza el recorrido.
 * @param visited Array que indica los nodos visitados.  (true recorrido, false 
 * todo lo contrario)
 */
void Graph::BFS(int s, bool *visited) {
    std::list<int> queue; //Cola para realizar el recorrido.
    visited[s] = true;
    queue.push_back(s); // Se encola el nodo de llegada. (s)
    std::list<int>::iterator i;
    //Se realiza el ciclo while mientras la cola no este vacía.
    while (!queue.empty()) {
        s = queue.front();
        queue.pop_front();
        //Se realiza un ciclo "for", para todos los arcos del nodo, de dicho nodo
        //en la posición (s) de la lista de adyancencia.
        for (i = adj[s].begin(); i != adj[s].end(); ++i) {
            //Si no ha sido recorrido, se agrega como recorrido, y se encola.
            if (!visited[*i]) {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

/**
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
                BP.push_back(this->nom_pla[i]);
            }
        }
    }
    delete[] visited; //Free memory.
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

/**
 * Método de lectura de los nombres de los nodos. (planetas)
 * 
 * @see split(string str, char pattern)
 */
void Graph::read_names() {
    std::ifstream map_names("mapa.txt");
    std::string c = ",";
    std::string content;
    if (!map_names.fail()) {
        std::getline(map_names, content);
        this->nom_pla = split(content, c[0]);
    }
    map_names.close();
}

/**
 * Método de lectura de las conexiones entre los nodos. (planetas)
 * 
 * @see split(string str, char pattern)
 * @see addEdge(int v, int w)
 */
void Graph::read_connections() {
    std::ifstream read_connections("mapa.txt");
    std::string c = " ";
    //Variable auxiliar que representa una fila en la matriz.
    std::vector<std::string> fila_matrix;
    //Se crea una matriz con la dimensiones de acuerdo al número planetas.
    int matrix[V][V];
    std::string content;
    if (!read_connections.fail()) {
        int j = 0; // Variable auxiliar para recorrer las columnas de la matriz.
        //Nótese que la variable (sw) sirve para empezar a hacer el proceso de
        //lectura en la segunda línea del archivo "mapa.txt".
        bool sw = false;
        while (std::getline(read_connections, content)) {
            if (sw == true) {
                fila_matrix = split(content, c[0]);
                for (int i = 0; i < fila_matrix.size(); i++) {
                    matrix[j][i] = std::stoi(fila_matrix[i]); // Se llena la matriz.
                }
                j++;
            } else {
                sw = true;
            }
        }
    }
    read_connections.close();
    // LLenado de la lista de adyacencia, de acuerdo a la matriz.
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            //Se verifica si hay arco.
            if (matrix[i][j] == 1) {
                addEdge(i, j); //Se guarda el arco o conexión.
            }
        }
    }
}

/**
 * Método que divide una cadena de caracteres.
 * 
 * @param str Cadena de caracteres que sera dividida.
 * @param pattern Caracter o criterio de partición.
 * @return Vector con las cadenas resultantes.
 */
std::vector<std::string> Graph::split(std::string str, char pattern) {
    int posInit = 0, posFound = 0;
    std::string splitted;
    std::vector<std::string> result;
    while (posFound >= 0) {
        posFound = str.find(pattern, posInit);
        splitted = str.substr(posInit, posFound - posInit);
        posInit = posFound + 1;
        result.push_back(splitted);
    }
    return result;
}

/**
 * Método de escritura en el archivo de salida.
 * 
 * @see split(string str, char pattern)
 */
void Graph::write_BP() {
    std::string string_con; //Cadena donde se almacenará todos los puntos de ruptura.
    // Concatenación de las cadenas en una sola.
    for (int i = 0; i < this->BP.size(); i++) {
        if ((i + 1) < this->BP.size()) {
            string_con = string_con + this->BP[i] + ",";
        } else {
            string_con = string_con + this->BP[i];
        }
    }
    std::ofstream ruptura("ruptura.txt");
    if (!ruptura.fail()) {
        //Escritura de la cadena concatenada en el archivo "ruptura.txt".
        ruptura << string_con;
    }
    ruptura.close();
}

