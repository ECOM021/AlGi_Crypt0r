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

Node * Tree::getRoot() const {
        return m_root;
}
