#pragma once
typedef unsigned char uchar;
class Node
{
  uchar symb;
  int occur;
  Node *left;
  Node *right;

public:

  Node();
  Node( uchar symb , int occur , Node *left , Node *right );
  uchar getSymb();
  int getOccur();
  Node * getLeft();
  Node * getRight();
  bool isLeaf();
  bool operator < (Node &other);
};
