
#include <iostream>
#include "Graph.h"
#include "windows.h"
#include "time.h"

int main() {
    srand(time(NULL));
    Graph graph(10);
    graph.printGraph();
    system("pause");
    return 0;
}

