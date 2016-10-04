#pragma once
using namespace std;

#include"Globals.hpp"
#include "Node.hpp"

class Tree {
private:

  Node * m_root;
  vector<uchar> m_reprenset;
public:
  Tree ( vector<ulong_64> occur );
  Tree ( vector<uchar> reprenset );
  Node * getRoot();
};
