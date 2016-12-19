#ifndef TREE_H
#define TREE_H
#pragma once

#include "Node.h"

class Tree {
private:
    int maxDepth;
    Node *root;
    int id;
public:
    Tree(int maximum_depth);

    Tree();

    ~Tree();

    void marking(Node *node);

    void BFS();

    void showTree();

    void showNode(Node *node, int x, int y);

    Node *addFromKeyboard(int depth);

    Node *generate(int depth, int maximum_depth);

    Node *getRoot();

    void gotoxy(int x, int y);
};

#endif
