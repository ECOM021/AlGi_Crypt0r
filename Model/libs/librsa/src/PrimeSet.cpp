#include "../inc/PrimeSet.hpp"

PrimeSet::PrimeSet() {
  do {
    fstream input;
    input.open("/home/gio/Workspace/algi_crypt0r/Assets/primes.txt", fstream::in);
    if(!input.is_open()) {
      cout << "Can't open prime file" << endl;
      continue;
    }
    ulong_64 v = 0;
    char c;
    m_primes = new vector<ulong_64>();
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
    primes->erase(0);
    for( auto p : *primes )
      m_primes->push_back(p);

    sort( m_primes->begin() , m_primes->end()  );
    delete primes;
  } while(0); 
}
ulong_64 PrimeSet::getSize() const {
  return m_primes->size();
}
ulong_64 PrimeSet::getNthPrime( ulong_64 idx ) const {
  return m_primes->at(idx);
}