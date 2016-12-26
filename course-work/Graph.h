#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>

#ifndef CW_GRAPH_H
#define CW_GRAPH_H

using namespace std;

class Graph {
private:
    bool **matrix;
    int s;
    bool cyclic;
    int *colors;
    int *from;
    int cycleS;
    int cycleE;
public:
    Graph();

    Graph(int s);

    Graph(int s, string data);

    void Show();

    void showCycle();

    void dfs(int v);

    bool isAcyclic();

    ~Graph();
};


#endif //CW_GRAPH_H
