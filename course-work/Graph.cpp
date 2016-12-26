#include "Graph.h"

Graph::Graph() {
    srand((unsigned int) time(NULL));
    s = rand() % 10;
    string data((unsigned int) (s * s), '0');
    for (int i = 0; i < s * s; i++)
        if (rand() % s == 1) data[i] = '1';
    matrix = new bool *[s];
    for (int i = 0; i < s; i++)
        matrix[i] = new bool[s]();
    for (int i = 0; i < s; i++)
        for (int j = 0; j < s; j++) {
            matrix[i][j] = data[i * s + j] - '0';
        }
}

Graph::Graph(int s) {
    this->s = s;
    matrix = new bool *[s];
    for (int i = 0; i < s; i++)
        matrix[i] = new bool[s]();
}

Graph::Graph(int s, string data) : Graph(s) {
    for (int i = 0; i < s; i++)
        for (int j = 0; j < s; j++) {
            matrix[i][j] = data[i * s + j] - '0';
        }
}

void Graph::Show() {
    cout << "Количество вершин в графе: " << s << endl;
    for (int i = 0; i < s; i++) {
        cout << i + 1 << "\t";
        for (int j = 0; j < s; j++)
            cout << "[" << matrix[i][j] << "]";
        cout << endl;
    }
}

void Graph::dfs(int v) {
    if (colors[v] == 2)
        return;
    if (cyclic)
        return;
    if (colors[v] == 1) {
        cyclic = true;
        return;
    }
    colors[v] = 1;
    for (int i = 0; i < s; i++) {
        if (matrix[v][i] == 1) {
            from[i] = v;
            if (colors[i] == 1) {
                cycleS = i;
                cycleE = v;
            }
            dfs(i);
        }
    }
    colors[v] = 2;
    return;
}

bool Graph::isAcyclic() {
    cyclic = false;
    colors = new int[s];
    from = new int[s]();
    dfs(0);
    return !cyclic;
}

Graph::~Graph() {
    for (int i = 0; i < s; i++)
        delete[] matrix[i];
    delete[] matrix;
    delete[] from;
    delete[] colors;
}

void Graph::showCycle() {
    vector<int> cycle;
    cycle.push_back(cycleS);
    for (int v = cycleE; v != cycleS; v = from[v])
        cycle.push_back(v);
    cout << cycleS + 1;
    for (int i = cycle.size() - 1; i >= 0; i--)
        cout << " -> " << cycle[i] + 1;

    cout << " \n";
}
