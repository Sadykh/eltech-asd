#include "Node.h"

Node::Node(int dep) {
    id = 0;
    depth = dep;
    right = nullptr;
    left = nullptr;
}


Node::~Node() {
    right = nullptr;
    left = nullptr;
}