#include "../inc/Tree.hpp"
using namespace std;
Tree::Tree ( vector<ulong_64> occur )
{
  priority_queue<Node*> pq;
  for (int i = 0; i < ASCII_SIZE; i++) {
    if( occur[i] ){
      pq.push( new Node( i , occur[i], NULL , NULL  ) );
    }
  }
  while( pq.size() > 1 ) {
    Node * lC = pq.top(); pq.pop();
    Node * rC = pq.top(); pq.pop();
    pq.push( new Node( '*' , lC->getOccur() + lC->getOccur() , lC, rC ) );
  }
  m_root = pq.top(); pq.pop();
}

Tree::Tree ( vector<uchar> represent ) {
	int idx = 0;
	m_root = buildTree(idx, reprenset);
}

Node * Tree::getRoot() const {
        return m_root;
}

Node * buildTree( int & idx , vector<uchar> & represent ) {
	if( represent[idx] == '*' ) {
		return new Node( 0 , 0 , buildTree(idx++, represent), buildTree(idx++, represent) ); 
	} else {
		if( represent[idx] == '!' )  ++idx;
		return new Node( represent[idx] , 0 , NULL , NULL );
	}
}
