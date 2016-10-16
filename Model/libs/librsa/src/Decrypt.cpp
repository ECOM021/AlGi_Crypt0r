#include "../inc/Decrypt.hpp"


Decrypt::Decrypt(std::string input, std::string output, 
                      ulong_64 key1 , ulong_64 key2, ulong_64 d)
{
  m_path_input = input;

  //Pick FilePath
  std::size_t dash = input.find_last_of("/\\");
  if(output == "")
        m_path_output = input.substr(0,dash);
  m_path_output += "/" + input.substr(dash+1);
  
  //Pick FileName
  std::size_t dot  = m_path_output.find_last_of(".");
  m_path_output = m_path_output.substr(0, dot);
  m_path_output += ".huff";

	m_e = key1;
	m_d = key2;
	m_ring = m_e * m_d;

  m_input.open(m_path_input);
	
}

void Decrypt::decrypt() {
  std::ifstream input("../../../../Assets/primes.txt");
  ulong_64 v = 0;
  char c;

  std::ofstream file(m_path_output);
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