/*
INSTRUCTIONS
In this assignment, it is required that you fill out areas under comments labeled as "TODO" appropriately based on the accompanying directions. 
You are also required to follow any directions accompanying comments such as "NOTE".
You can add/modify code anywhere, with the exception of the provided "main" (which we will use for testing).
You can use the constants RED and BLACK, instead of the ints 0 and 1, when appropriate.
*/

#include <iostream>
#include <math.h> // for asserting height
#include <queue>

using namespace std;

#define RED 0
#define BLACK 1

template <class T>
class RBT;

// swapColor swaps the color from red to black and vice versa
int swapColor(int c) {
    return (c==0)?1:0;
}

template <class T>
class RBTNode {
    RBTNode<T> *parent, *left, *right;
    T data;
    int color;

public:
    RBTNode(T data)
        : data(data),
          color(RED),
          parent(nullptr),
          left(nullptr),
          right(nullptr) {}
    friend class RBT<T>;
    void prettyPrint(int indent) const;

    template <class T1>
    friend void swapColor(RBTNode<T1> *);
    template <class T1>
    friend int getColor(RBTNode<T1> *);

    int height() const;
};

template <class T>
int RBTNode<T>::height() const {
    int left_h = 0;
    if (left != nullptr) {
        left_h = left->height();
    }
    int right_h = 0;
    if (right != nullptr) {
        right_h = right->height();
    }
    return 1 + max(left_h, right_h);
}

template <class T>
void RBTNode<T>::prettyPrint(int indent) const {
    if (right != nullptr) {
        right->prettyPrint(indent + 1);
    }
    int margin = indent * 2;
    for (int i = 0; i < margin; ++i) {
        cout << '\t';
    }
    cout << "DATA: " << data << endl;
    for (int i = 0; i < margin; ++i) {
        cout << '\t';
    }
    cout << "COLOR: " << (color == RED ? "RED" : "BLACK") << endl;
    if (left != nullptr) {
        left->prettyPrint(indent + 1);
    }
}

template <class T>
void swapColor(RBTNode<T> *node) {
    if (node != nullptr) {
        node->color = swapColor(node->color);
    }
}

// getColor handles null nodes
template <class T>
int getColor(RBTNode<T> *node) {
    if (node != nullptr) {
        return node->color;
    }
    return BLACK;
}

template <class T>
class RBT {
    RBTNode<T> *root;
    void singleCCR(RBTNode<T> *&point);
    void doubleCR(RBTNode<T> *&point);
    void singleCR(RBTNode<T> *&point);
    void doubleCCR(RBTNode<T> *&point);
    void doRotation(RBTNode<T>* point);

public:
    RBT() : root(nullptr) {}

    void insert(const T &);
    void insert(const T &, RBTNode<T> *&point, RBTNode<T> *parent);
    void prettyPrint() const { root->prettyPrint(0); }

    int height() const { return root->height(); }
};

template <class T>
void RBT<T>::doubleCCR(RBTNode<T> *&point) {
    singleCR(point->right);
    singleCCR(point);
}

template <class T>
void RBT<T>::doubleCR(RBTNode<T> *&point) {
    singleCCR(point->left);
    singleCR(point);
}

template <class T>
void RBT<T>::singleCR(RBTNode<T> *&point) {
    RBTNode<T> *grandparent = point;
    RBTNode<T> *parent = point->left;
    // TODO: ADD ROTATION CODE HERE
    parent->parent = grandparent->parent;
    grandparent->parent = parent;
    grandparent->left = parent->right;
    parent->right = grandparent;
    if (grandparent->left != nullptr)
        grandparent->left->parent = grandparent;
    if (parent->parent == nullptr)
        root = parent;
    else if (parent->parent->left == grandparent)
        parent->parent->left = parent;
    else
        parent->parent->right = parent;
    grandparent->height();
    parent->height();
}

template <class T>
void RBT<T>::singleCCR(RBTNode<T> *&point) {
    RBTNode<T> *grandparent = point;
    RBTNode<T> *parent = point->right;
    // TODO: ADD ROTATION CODE HERE
    parent->parent = grandparent->parent;
    grandparent->parent = parent;
    grandparent->right = parent->left;
    parent->left = grandparent;
    if (grandparent->right != nullptr)
        grandparent->right->parent = grandparent;
    if (parent->parent == nullptr)
        root = parent;
    else if (parent->parent->right == grandparent)
        parent->parent->right = parent;
    else
        parent->parent->left = parent;
    grandparent->height();
    parent->height();
}

template <class T>
void RBT<T>::insert(const T &toInsert, RBTNode<T> *&point, RBTNode<T> *parent) {
    if (point == nullptr) {               // leaf location is found so insert node
        point = new RBTNode<T>(toInsert); // modifies the pointer itself since *point
                                          // is passed by reference
        point->parent = parent;

        RBTNode<T> *curr_node = point; // curr_node will be set appropriately when walking up the tree
        // TODO: ADD RBT RULES HERE
        // if parent is red, we process it
        while (curr_node->parent->color == 0) {
            if (curr_node->parent == curr_node->parent->parent->left) {
                RBTNode<T> *uncle = curr_node->parent->parent->right;
                // case1: uncle is red
                if (uncle->color == 0) {
                    curr_node->parent->color = 1;
                    uncle->color = 1;
                    curr_node->parent->parent->color = 0;
                    curr_node = curr_node->parent->parent;
                }
                    // case2 & 3: uncle i is black
                else {
                    if (curr_node == curr_node->parent->right){     // case2
                        curr_node = curr_node->parent;
                        doRotation(curr_node);
                    }
                    // case3
                    curr_node->parent->color = 1;
                    curr_node->parent->parent->color = 0;
                    doRotation(curr_node->parent->parent);
                }
            }

            else {
                RBTNode<T> *uncle = curr_node->parent->parent->left;
                // case1: uncle is red
                if (uncle->color == 0) {
                    curr_node->parent->color = 1;
                    uncle->color = 1;
                    curr_node->parent->parent->color = 0;
                    curr_node = curr_node->parent->parent;
                }
                // case2 & 3: uncle is black
                else {
                    if (curr_node == curr_node->parent->left) { // case2
                        curr_node = curr_node->parent;
                        doRotation(curr_node);
                    }
                    // case3
                    curr_node->parent->color = 1;
                    curr_node->parent->parent->color = 0;
                    doRotation(curr_node->parent->parent);
                }
            }
        }
        root->color = 1;
    } else if (toInsert < point->data) { // recurse down the tree to left to find correct leaf location
        insert(toInsert, point->left, point);
    } else { // recurse down the tree to right to find correct leaf location
        insert(toInsert, point->right, point);
    }
}

template <class T>
void RBT<T>::doRotation(RBTNode<T>* point){
    int leftChild = -1;
    int rightChild = -1;
    if (point->left != nullptr)
        leftChild = point->left->height();
    if (point->right != nullptr)
        rightChild = point->right->height();

    if (leftChild > rightChild){//CR, but is it single or double?
        int leftGC = -1;
        int rightGC = -1;
        if (point->left->left != nullptr)
            leftGC = point->left->left->height();
        if (point->left->right != nullptr)
            rightGC = point->left->right->height();
        if (leftGC > rightGC) // single rotation
            singleCR(point);
        else
            doubleCR(point);
    }
    else{//definitely a CCR, but which one?
        int leftGC = -1;
        int rightGC = -1;
        if (point->right->left != nullptr)
            leftGC = point->right->left->height();
        if (point->right->right != nullptr)
            rightGC = point->right->right->height();
        if (leftGC > rightGC) // double rotation
            doubleCCR(point);
        else
            singleCCR(point);
    }
}


template <class T>
void RBT<T>::insert(const T &toInsert) {
    insert(toInsert, root, nullptr);
}

// NOTE: DO NOT MODIFY THE MAIN FUNCTION BELOW
int main() {
    RBT<int> b;
    int count = 10;
    for (int i = 0; i < count; i++) {
        b.insert(i);
    }

    b.prettyPrint();
    /* EXPECTED OUTPUT:
                                                                    Data: 9
                                                                    COLOR: RED
                                                    Data: 8
                                                    COLOR: BLACK
                                    Data: 7
                                    COLOR: RED
                                                    Data: 6
                                                    COLOR: BLACK
                    Data: 5
                    COLOR: BLACK
                                    Data: 4
                                    COLOR: BLACK
    Data: 3
    COLOR: BLACK
                                    Data: 2
                                    COLOR: BLACK
                    Data: 1
                    COLOR: BLACK
                                    Data: 0
                                    COLOR: BLACK
    */

    // TEST
    // the below tests the validity of the height of the RBT
    // if the assertion fails, then your tree does not properly self-balance
    int height = b.height();
    assert(height <= 2 * log2(count));
}