class Graph {
private:
    int **matrix;
    int count_of_nodes;
    int selected_node;
    int maxCount_of_nodes;
public:
    Graph(int);

    ~Graph();

    void printGraph();

    void Graph::checkGraph(int v);
