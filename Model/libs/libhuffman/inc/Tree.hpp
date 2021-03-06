#ifndef TREE_HPP
#define TREE_HPP

using namespace std;

#include"Globals.hpp"
#include "Node.hpp"

class Tree {
private:

  Node * m_root;
  vector<uchar> m_reprenset;
  int m_height;
  Node * buildTree( int & idx, vector<uchar> reprenset , int height );
public:
  Tree ( vector<ulong_64> occur );
  Tree ( vector<uchar> reprenset );
  Node * getRoot();
  int getHeigth();
  void print(Node * no);
};

#endif // !TREE_HPP