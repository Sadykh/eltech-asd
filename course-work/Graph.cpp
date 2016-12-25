#include "Graph.h"
#include <iostream>
#include "windows.h"
#include <vector>

Graph::Graph(int maxCount) {
    maxCount_of_nodes = maxCount;
    count_of_nodes = rand() % (maxCount - 5) + 6;
    matrix = new int *[count_of_nodes];
    for (int i = 0; i < count_of_nodes; i++)
        matrix[i] = new int[count_of_nodes];
    for (int i = 0; i < count_of_nodes; i++)
        for (int j = 0; j < count_of_nodes; j++)
            matrix[i][j] = rand() % 2;
}


Graph::~Graph() {
    for (int i = 0; i < count_of_nodes; i++)
        delete[] matrix[i];
    delete[] matrix;
    matrix = nullptr;
}

void Graph::printGraph() {
    std::cout << "\t";
    for (int i = 0; i < count_of_nodes; i++)
        std::cout << i << "|";
    std::cout << "\n\n";
    for (int i = 0; i < count_of_nodes; i++) {
        std::cout << i << "\t";
        for (int j = 0; j < count_of_nodes; j++)
            if (j < 10)
                std::cout << matrix[i][j] << "|";
            else
                std::cout << matrix[i][j] << " |";

        std::cout << "\n";
    }
}

void Graph::checkGraph(int v) {
    int n;
    vector <vector<int>> g;
    vector<char> cl;
    vector<int> p;
    int cycle_st, cycle_end;

    cl[v] = 1;
    for (size_t i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if (cl[to] == 0) {
            p[to] = v;
            if (Graph::checkGraph(to)) return true;
        } else if (cl[to] == 1) {
            cycle_end = v;
            cycle_st = to;
            return true;
        }
    }
    cl[v] = 2;
    return false;
}