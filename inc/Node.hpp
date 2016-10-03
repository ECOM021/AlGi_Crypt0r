#pragma once
using namespace std;

#include "Globals.hpp"

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
