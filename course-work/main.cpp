#include <iostream>
#include <windows.h>
#include "Graph.h"

using namespace std;

int main() {
//    Graph* graph = new Graph(3,"001001000");
//    Graph* graph = new Graph(3,"001100010");
//    Graph* graph = new Graph(8,"0010011000000000000000010000100000001000000100000001000010100100");
    Graph *graph = new Graph();
    graph->Show();
    if (graph->isAcyclic())
        cout << "Граф не содержит циклов \n" << endl;
    else {
        cout << "Граф содержит цикл" << endl;
        graph->showCycle();
    }
    delete graph;
    system("pause");
    return 0;
}