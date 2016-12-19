#include "Tree.h"
#include <iostream>
#include "windows.h"
#include <math.h>
#include "Queue.h"

using namespace std;


/**
 * ���� � ����������
 */
Tree::Tree() {
    int depth = 0;
    bool decision;

    maxDepth = 0;
    id = 1;

    cout << "������� ��७�?(1\\0)\n";
    cin >> decision;

    if (decision) {
        root = addFromKeyboard(depth);
    }
}

/**
 * ��⮬���᪨� ���������
 * @param maximum_depth
 */
Tree::Tree(int maximum_depth) {
    int chance;
    int depth = 0;
    maxDepth = 0;
    id = 1;

    chance = rand() % 7 + depth;
    if (chance < maximum_depth + 1)
        root = generate(depth, maximum_depth);
}

/**
 * ��⮬���᪠� ������� 㧫�
 * @param depth
 * @param maximum_depth
 * @return
 */
Node *Tree::generate(int depth, int maximum_depth) {
    int chance;
    Node *node = new Node(depth);

    if (depth > maxDepth)
        maxDepth = depth;
    chance = rand() % 7 + depth + 1;
    if (chance < maximum_depth + 1)
        node->left = generate(depth + 1, maximum_depth);
    chance = rand() % 7 + depth + 1;
    if (chance < maximum_depth + 1)
        node->right = generate(depth + 1, maximum_depth);

    return node;
}

/**
 * ���� 㧫�� � ����������
 * @param depth
 * @return
 */
Node *Tree::addFromKeyboard(int depth) {
    bool decision;
    if (depth > maxDepth)
        maxDepth = depth;

    Node *node = new Node(depth);
    cout << "���� �ᯥ譮 ᮧ���.\n";
    if (depth < 6) {
        cout << "������� ������ �뭠 � ��㡨��� " << depth + 1 << "?(1\\0)\n";
        cin >> decision;
        if (decision) {
            node->left = addFromKeyboard(depth + 1);
        }
        cout << "������� �ࠢ��� �뭠 � ��㡨��� " << depth + 1 << "?(1\\0)\n";
        cin >> decision;
        if (decision) {
            node->right = addFromKeyboard(depth + 1);
        }
    } else
        cout << "���������� ᮧ���� 㧥� � ��㡨��� " << depth
             << ", �.�. �� �ਢ���� � �஡����� �뢮�� \n��ॢ� �� �࠭.\n";
    return node;
}


/**
 * �����⪠ ��ॢ� (��ﬠ� ࠧ��⪠)
 * @param node
 */
void Tree::marking(Node *node) {
    if (node != nullptr) {
        node->id = id++;
        Tree::marking(node->left);
        Tree::marking(node->right);
    }
}

/**
 * ��室 ��ॢ� � �ਭ� � ������ ����쥢
 * @return int
 */
void Tree::BFS() {
    const int MaxQ = 20; //���ᨬ���� ࠧ��� ��।�
    int count = 0;
    QUEUE<Node *> Q(MaxQ);  //ᮧ����� ��।� 㪠��⥫�� �� 㧫�
    Q.put(root); // QUEUE <- root �������� � ��।� ��७� ��ॢ�
    while (!Q.empty()) //���� ��।� �� ����
    {
        Node *v = Q.get();// ����� �� ��।�,
        cout << v->id << ' ';
//        ���������஢���, ��� ����來��� ������ ����� �᪮�����஢���
//        cout << " 㧥�: ";
//        if (v->left == nullptr) cout << "��� ������ �뭠 \n";
//        if (v->right == nullptr) cout << "��� �ࠢ��� �뭠 \n";
//        cout << "\n";
        if (v->left == nullptr && v->right == nullptr) count++;
        if (v->left) Q.put(v->left); // QUEUE <- (���� ��)
        if (v->right) Q.put(v->right); // QUEUE <- (�ࠢ� ��)
    }
    cout << "\n����쥢: "  <<  count << "\n";
}

/**
 * �뢮� ��ॢ� �� �࠭
 */
void Tree::showTree() {

    if (root) {
        system("cls");
        for (int i = 0; i < maxDepth * 2 + 1; i++) {
            cout << "................................................................................";
        }
        showNode(root, 33, 0);
    }
    gotoxy(0, maxDepth * 2 + 2);
}

/**
 * �뢮� 㧫� �� �࠭
 * @param node
 * @param x
 * @param y
 */
void Tree::showNode(Node *node, int x, int y) {
    gotoxy(x, y);
    cout << node->id;
    if (node->left != nullptr) {
        showNode(node->left, x - pow(2, 5 - node->left->depth), y + 2);
    }
    if (node->right != nullptr) {
        showNode(node->right, x + pow(2, 5 - node->right->depth), y + 2);
    }
}

/**
 * ��६�饭�� �����
 * @param xpos
 * @param ypos
 */
void Tree::gotoxy(int xpos, int ypos) {
    COORD scrn;

    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);

    scrn.X = (short) xpos;
    scrn.Y = (short) ypos;

    SetConsoleCursorPosition(hOuput, scrn);
}

/**
 * ��������
 */
Tree::~Tree() {
    delete root;
}

/**
 * ����祭�� ����
 * @return root
 */
Node *Tree::getRoot() {
    return root;
}