#include "Tree.h"
#include <iostream>
#include "windows.h"
#include <math.h>
#include "Queue.h"

using namespace std;


/**
 * Ввод с клавиатуры
 */
Tree::Tree() {
    int depth = 0;
    bool decision;

    maxDepth = 0;
    id = 1;

    cout << "Создать корень?(1\\0)\n";
    cin >> decision;

    if (decision) {
        root = addFromKeyboard(depth);
    }
}

/**
 * Автоматический конструктор
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
 * Автоматическая генерация узла
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
 * Ввоз узлов с клавиатуры
 * @param depth
 * @return
 */
Node *Tree::addFromKeyboard(int depth) {
    bool decision;
    if (depth > maxDepth)
        maxDepth = depth;

    Node *node = new Node(depth);
    cout << "Узел успешно создан.\n";
    if (depth < 6) {
        cout << "Создать левого сына с глубиной " << depth + 1 << "?(1\\0)\n";
        cin >> decision;
        if (decision) {
            node->left = addFromKeyboard(depth + 1);
        }
        cout << "Создать правого сына с глубиной " << depth + 1 << "?(1\\0)\n";
        cin >> decision;
        if (decision) {
            node->right = addFromKeyboard(depth + 1);
        }
    } else
        cout << "Невозможно создать узел с глубиной " << depth
             << ", т.к. это приведет к проблемам вывода \nдерева на экран.\n";
    return node;
}


/**
 * Разметка дерева (прямая разметка)
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
 * Обход дерева в ширину и подсчет листьев
 * @return int
 */
void Tree::BFS() {
    const int MaxQ = 20; //максимальный размер очереди
    int count = 0;
    QUEUE<Node *> Q(MaxQ);  //создание очереди указателей на узлы
    Q.put(root); // QUEUE <- root поместить в очередь корень дерева
    while (!Q.empty()) //пока очередь не пуста
    {
        Node *v = Q.get();// взять из очереди,
        cout << v->id << ' ';
//        закомментировано, для нагдядности подсчета можно раскомментировать
//        cout << " узел: ";
//        if (v->left == nullptr) cout << "нет левого сына \n";
//        if (v->right == nullptr) cout << "нет правого сына \n";
//        cout << "\n";
        if (v->left == nullptr && v->right == nullptr) count++;
        if (v->left) Q.put(v->left); // QUEUE <- (левый сын)
        if (v->right) Q.put(v->right); // QUEUE <- (правый сын)
    }
    cout << "\nЛистьев: " << count << "\n";
}

/**
 * Вывод дерева на экран
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
 * Вывод узла на экран
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
 * Перемещение курсора
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
 * Деструктор
 */
Tree::~Tree() {
    delete root;
}

/**
 * Получение корня
 * @return root
 */
Node *Tree::getRoot() {
    return root;
}