#include "../inc/PrimeSet.hpp"

PrimeSet::PrimeSet() {
  fstream input;
  input.open("../AlGi_Crypt0r/assets/primes.txt", fstream::in);
  ulong_64 v = 0;
  char c;
  while (input.get(c)) {
    if( c < '0' || c > '9' ) {
      m_primes.insert(v);
      v = 0;
      continue;
    }
    v = v*10 + (c-'0');
  }
  m_primes.insert(v);
  m_primes.erase(0);
}
bool PrimeSet::isPrime(unsigned long long int value) {
  return m_primes.count(value);
}
unsigned long long int PrimeSet::getSize() const {
  return m_primes.size();
}
