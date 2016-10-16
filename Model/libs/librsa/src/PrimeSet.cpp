#include "../inc/PrimeSet.hpp"

PrimeSet::PrimeSet() {
  fstream input;
  input.open("../AlGi_Crypt0r/assets/primes.txt", fstream::in);
  ulong_64 v = 0;
  char c;
  set<unsigned long long int> primes;
  while (input.get(c)) {
    if( c < '0' || c > '9' ) {
      primes.insert(v);
      v = 0;
      continue;
    }
    else v = v*10 + (c-'0');
  }
  primes.insert(v);
  primes.erase(0);
  for( auto p : primes )
      m_primes.push_back(p);
  sort( m_primes.begin() , m_primes.end()  );
}
unsigned long long int PrimeSet::getSize() const {
  return m_primes.size();
}
unsigned long long int PrimeSet::getNthPrime( ulong_64 idx ) const {
  return m_primes[idx];
}