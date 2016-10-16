#include "../inc/PrimeSet.hpp"

PrimeSet::PrimeSet() {
  fstream input;
  input.open("../../../../Assets/primes.txt", fstream::in);
  ulong_64 v = 0;
  char c;
  m_primes = new vector<ulong_64>(10000000);
  set<ulong_64> *primes = new set<ulong_64>();
  while (input.get(c)) {
    if( c < '0' || c > '9' ) {
      primes->insert(v);
      v = 0;
      continue;
    }
    else v = v*10 + (c-'0');
  }
  primes->insert(v);
  cout << "Tamanho do set" << primes->size() << endl;
  primes->erase(0);
  int idx = 0;
  cout << "Tamanho do set " << primes->size() << endl;
  cout << "Os primos ";
  for( auto p : *primes )
  {
    if( idx++ <= 20 ) cout << p << " ";
    m_primes->push_back(p);
  }
  sort( m_primes->begin() , m_primes->end()  );
  std::cout << "Vector size: " << m_primes->size() << std::endl;
  delete primes;
}
ulong_64 PrimeSet::getSize() const {
  return m_primes->size();
}
ulong_64 PrimeSet::getNthPrime( ulong_64 idx ) const {
  return m_primes->at(idx);
}