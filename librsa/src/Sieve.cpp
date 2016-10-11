#include "../inc/Sieve.hpp"


Sieve::Sieve()
{
  /*cout << "Gerando" << endl;
  m_table.set();
  m_table[0] = m_table[1] = false;
  ulong_64 limit = 100;//Math2::sqrt(10e10+10);
  for (ulong_64 i = 2; i <= limit; ++i)
  {
    if( m_table[i] )
    {
      m_primes.push_back(i);
      for (ulong_64 j = 2; j*i < 10e10+10 ; ++j)
        m_table[j*i] = false;
    }
  }
  for (ulong_64 i = limit ; i <= 10e10+10; ++i)
    if( m_table[i] )
      m_primes.push_back(i);*/
}
bool Sieve::isPrime(unsigned long long int idx)
{
  return m_table[idx];
}
unsigned long long int Sieve::getPos(unsigned long long int idx) const
{
  return m_primes[idx];
}
unsigned long long int Sieve::getSize() const
{
  return m_primes.size();
}
