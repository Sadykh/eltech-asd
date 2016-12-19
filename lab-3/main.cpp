#include <iostream>
#include "Tree.h"
#include "time.h"

using namespace std;

int main() {
    srand(time(NULL));
    Tree tree = Tree(4);
    tree.marking(tree.getRoot());
    tree.showTree();
    tree.BFS();
    system("pause");
    return 0;
}
