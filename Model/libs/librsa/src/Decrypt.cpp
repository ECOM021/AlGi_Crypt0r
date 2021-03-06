#include "../inc/Decrypt.hpp"


Decrypt::Decrypt(std::string input, std::string output, 
                      ulong_64 key1 , ulong_64 key2, ulong_64 d)
{
  m_path_input = input;

  //Pick FilePath
  std::size_t dash = input.find_last_of("/\\");
  if(output == "")
        m_path_output = input.substr(0,dash);
  else 
        m_path_output = output;
  m_path_output += "/" + input.substr(dash+1);
  
  //Pick FileName
  std::size_t dot  = m_path_output.find_last_of(".");
  m_path_output = m_path_output.substr(0, dot);
  m_path_output += ".huff";

  std::cout << m_path_output << std::endl;

	m_p = key1;
	m_q = key2;
  m_d = d;
	m_ring = key1 * key2;

  m_input.open(m_path_input);
  decrypt();
	
}

void Decrypt::decrypt() {
  //std::ifstream input();
  ulong_64 v = 0;
  char c;

  std::ofstream file(m_path_output);
  if(file.is_open()) std::cout << "aberto" << std::endl;
  else std::cout << "fechado" << std::endl;
  while (m_input.get(c)) {
    if( c < '0' || c > '9' ) {
      file << (uchar)( Math2::exp(v,m_d,m_ring) );  
      v = 0;
      continue;
    }
    else v = v*10 + (c-'0');
  }
  file.close();
}

std::string Decrypt::getOutput() {
  return m_path_output;
}