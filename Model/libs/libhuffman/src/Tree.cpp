#include "../inc/Tree.hpp"
using namespace std;

struct NodeCmp
{
    bool operator()( Node* lhs,  Node* rhs) const {
            return lhs->getOccur() > rhs->getOccur();
    }
};

Tree::Tree ( vector<ulong_64> occur )
{
  priority_queue<Node*, vector<Node *> ,NodeCmp >pq;
  for (int i = 0; i < ASCII_SIZE; i++) {
    if( occur[i] ){
      pq.push( new Node( i , occur[i], NULL , NULL  ) );
    }
  }
  while( pq.size() > 1 ) {
    Node * lC = pq.top(); pq.pop();
    Node * rC = pq.top(); pq.pop();
    pq.push( new Node( '*' , lC->getOccur() + rC->getOccur() , lC, rC ) );
  }
  m_root = pq.top(); pq.pop();
}

Node * Tree::buildTree( int & idx, vector<uchar> reprenset , int height ) {
	if( reprenset[idx] == '*' ) {
		return new Node( 0 , 0 , buildTree(++idx, reprenset, height+1),
                              buildTree(++idx,reprenset, height+1) );
	} else {
    m_height = max(m_height, height+1);
		if( reprenset[idx] == '!' )  ++idx;
		return new Node( reprenset[idx] , 0 , NULL , NULL );
	}
}

Tree::Tree ( std::vector<uchar> represent ) {
	int idx = m_height = 0;
  m_root = buildTree(idx , represent , 0);
}

int Tree::getHeigth() {
  return m_height;
}

Node * Tree::getRoot() {
        return m_root;
}

void Tree::print(Node * no) {
  if( no->isLeaf() ) {
    if( no->getSymb() == '!' || no->getSymb() == '*' ) cout << "!";
    cout << no->getSymb();
  } else {
    cout << "*";
    print(no->getLeft());
    print(no->getRight());
  }
}
