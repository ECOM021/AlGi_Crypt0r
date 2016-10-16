#include "../inc/Decrypt.hpp"


Decrypt::Decrypt(string input, string output, unsigned long long key1 , unsigned long long key2)
{
	m_e = key1;
	m_d = key2;
	m_ring = m_e * m_d;
	/* Leitura
		leitura do .agc
	*/
	
}

void Decrypt::decrypt()
{
  fstream input;
  // 
  //input.open("../AlGi_Crypt0r/assets/primes.txt", fstream::in);
  ulong_64 v = 0;
  char c;
  // saida do arquivo anterior
  ofstream file(m_path_output);
  while (input.get(c)) {
    if( c < '0' || c > '9' ) {
      file << (uchar)( Math2::inv(m_d,m_ring) );  
      v = 0;
      continue;
    }
    v = v*10 + (c-'0');
  }
  file.close();
}