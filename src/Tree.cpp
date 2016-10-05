#include "../inc/Tree.hpp"
using namespace std;
Tree::Tree ( vector<ulong_64> occur )
{
  priority_queue<Node*, vector<Node*> , less<Node*> >pq;
  for (int i = 0; i < ASCII_SIZE; i++) {
    if( occur[i] ){
      pq.push( new Node( i , occur[i], NULL , NULL  ) );
    }
  }
  cout << pq.size() << endl;
  int j = 1;
  while( pq.size() > 1 ) {
          cout << j++ <<endl;
    Node * lC = pq.top(); pq.pop();
    Node * rC = pq.top(); pq.pop();
    pq.push( new Node( '*' , lC->getOccur() + rC->getOccur() , lC, rC ) );
  }
  m_root = pq.top(); pq.pop();
}

Node * buildTree( int & idx, vector<uchar> reprenset ) {
	if( reprenset[idx] == '*' ) {
		return new Node( 0 , 0 , buildTree(++idx, reprenset), buildTree(++idx,reprenset));
	} else {
		if( reprenset[idx] == '!' )  ++idx;
		return new Node( reprenset[idx] , 0 , NULL , NULL );
	}
}

Tree::Tree ( std::vector<uchar> represent ) {
	int idx = 0;
        m_root = buildTree(idx,represent);
}

Node * Tree::getRoot() {
        return m_root;
}
