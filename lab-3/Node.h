#ifndef NODE_H
#define NODE_H
#pragma once

class Node {
private:
    int id;
    int depth;
    Node *right;
    Node *left;

    friend class Tree;

public:
    Node(int);

    ~Node();
};

#endif
