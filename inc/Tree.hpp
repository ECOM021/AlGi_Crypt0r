#pragma once
#include <stdio.h>
#include "Node.hpp"
typedef unsigned char uchar;
#include <queue>
#define BYTE 256

class Tree {
private:

  Node * root;

public:
  Tree ( int * occur );
};
