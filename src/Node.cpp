#include "../inc/Node.hpp"
#include <stdio.h>

Node::Node() {
        symb = occur = 0;
        left = right = NULL;
}

Node::Node( uchar symb , int occur , Node *left , Node *right ) {
        this->symb = symb;
        this->occur = occur;
        this->left = left;
        this->right = right;
}

uchar Node::getSymb() {
        return this->symb;
}
int Node::getOccur() {
        return this->occur;
}
Node * Node::getLeft() {
        return this->left;
}
Node * Node::getRight() {
        return this->right;
}

bool Node::isLeaf() {
        return (this->left == NULL) && (this->right == NULL);
}

bool Node::operator > (Node &other) {
        return this->occur < other.occur;
}
