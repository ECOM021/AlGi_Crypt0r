#include "../inc/Encrypt.hpp"

Encrypt::Encrypt(string input, string output = "") {
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
        m_path_output += ".agc";

        do {
                cout << "1" << endl;
                m_primes = PrimeSet();
                cout << "set size: "<< m_primes.getSize() << endl;
                srand (time(NULL));
                cout << "3" << endl;
                choosePair();
                cout << "4" << endl;
                totiente();
                cout << "5" << endl;
                pickOdd();
                cout << "6" << endl;
                if(!loadMedia(input)) continue;
                cout << "7" << endl;
                encrypt();
                std::cout << "Keys: " << m_p << "\t" << m_q << endl;
                std::cout << "P * Q: " << m_p * m_q << endl;
                std::cout << "(P-1)*(Q-1): " << (m_p - 1) * (m_q -1) << endl;
                std::cout << "Exps: " << m_e << "\t" << m_d << endl;
                std::cout << "gcd(E, Phi) :";
                std::cout << Math2::gcd(m_e, (m_p - 1) * (m_q -1)) << endl;
                std::cout << "(E*D)%phi: ";
                std::cout << (m_e * m_d) % ((m_p-1)*(m_q-1)) << endl;
        } while(0);
}

void Encrypt::pickOdd() {
        cout << m_p << " " << m_q << " " << m_p * m_q << endl;
	cout << "Key E " << endl;
	m_e = 3;
        while (true)
	{
		if (m_e >= 2 && Math2::gcd(m_e, m_multply) == 1)
			break;
		m_e += 2;
                cout << m_e << endl;
	}
	cout << "Key D " << endl;
	/* for (ulong_64 i = 2; i < m_multply ; ++i)
	{
		if( (m_e * i)%m_multply == 1  ) {
			m_d = i; break;
		}
	}*/
	m_d = Math2::inv( m_e, m_multply );
}
void Encrypt::totiente() {
	m_multply = (m_p-1) * (m_q-1);
}
void Encrypt::choosePair() {
	ulong_64 size = m_primes.getSize();
	do {
 		m_p = m_primes.getNthPrime( rand()%size );
  		m_q = m_primes.getNthPrime( rand()%size );
  		m_ring = m_p * m_q;
  	} while( m_ring <= 256 );
}
bool Encrypt::loadMedia(string iPath) {
	m_in.open(iPath, fstream::in | std::fstream::binary);
        if(m_in.is_open())
                return true;
        return false;
}
void Encrypt::encrypt() {
        do {
                char * in = new char[READMAX];
                ofstream file(m_path_output);
                if(!file.is_open()) {
                        cout << "Can't writ encrypted file." << endl;
                        continue;
                }
                while(m_in.readsome(in, READMAX))
                        for (int i = 0; i < m_in.gcount() ; i++)
                                file << Math2::exp((uchar)in[i],m_e,m_ring) << '#';
                file.close();
                delete []in;
        } while (0);
}

ulong_64 Encrypt::getKeyP() {
        return m_p;
}

ulong_64 Encrypt::getKeyQ() {
        return m_q;
}

ulong_64 Encrypt::getKeyD() {
        return m_d;
}

ulong_64 Encrypt::getKeyE() {
        return m_e;
}