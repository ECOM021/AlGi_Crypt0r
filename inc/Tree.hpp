#pragma once
using namespace std;

#include"Globals.hpp"
#include "Node.hpp"

class Tree {
private:

  Node * m_root;

public:
  Tree ( vector<ulong_64> occur );
  Node * getRoot() const;
};
