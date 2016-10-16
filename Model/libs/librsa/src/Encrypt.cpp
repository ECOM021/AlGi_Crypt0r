#include "../inc/Encrypt.hpp"

Encrypt::Encrypt(string input, string output = "") {
  m_path_input = input;

  //Pick FilePath
  std::size_t dash = input.find_last_of("/\\");
  if(output == "")
        m_path_output = input.substr(0,dash);
  m_path_output += "/" + input.substr(dash+1);
  
  //Pick FileName
  std::size_t dot  = m_path_output.find_last_of(".");
  m_path_output = m_path_output.substr(0, dot);
  m_path_output += ".agc";

  std::cout << "1" << std::endl;
  m_primes = PrimeSet();
  std::cout << "2" << std::endl;
  srand (time(NULL));
  std::cout << "Set size: " << m_primes.getSize() << std::endl;
   std::cout << "3" << std::endl;
   choosePair();
   std::cout << "first ten:" << std::endl;
   for(int i = 0; i < 10; ++i)
        cout << m_primes.getNthPrime(i) << endl;
//   std::cout << "4" << std::endl;
//   totiente();
//   std::cout << "5" << std::endl;
//   loadMedia(input);
//   std::cout << "6" << std::endl;
//   encrypt();
//   std::cout << "Keys: " << m_p << "\t" << m_q << "\n";
//   std::cout << "Exps: " << m_e << "\t" << m_d << "\n"; 
}

void Encrypt::pickOdd() {
	m_e = 3;
	while( Math2::gcd(m_e,m_multply) != 1 )
		m_e += 2;
	m_d = Math2::inv( m_e , m_multply );
}
void Encrypt::totiente() {
	m_multply = (m_p-1) * (m_q-1);
}
void Encrypt::choosePair() {
	ulong_64 size = m_primes.getSize();
	cout << size << " ----- choosePair" << endl; 
	do {
 		m_p = m_primes.getNthPrime( rand()%size );
  		m_q = m_primes.getNthPrime( rand()%size );
  		m_ring = m_p * m_q;
  		cout << "Primes " << m_p << "\t\t" << m_q << endl;
  		return; 
                cout << m_ring << endl;
  	} while( m_ring <= 256 );
}
bool Encrypt::loadMedia(string iPath) {
	m_in.open(iPath, fstream::in | std::fstream::binary);
        if(m_in.is_open())
                return true;
        return false;
}
void Encrypt::encrypt() {
        char * in = new char[READMAX];
        ofstream file(m_path_output);
        while(m_in.readsome(in, READMAX))
                for (int i = 0; i < m_in.gcount() ; i++)
                	file << Math2::exp((uchar)in[i],m_e,m_ring) << '#';
        file.close();
        delete []in;
}