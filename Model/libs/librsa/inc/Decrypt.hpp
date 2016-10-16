#ifndef DECRYPT_HPP
#define DECRYPT_HPP

#include "Math2.hpp"
class Decrypt {
public:
	Encrypt(string input, string output, unsigned long long key1 , unsigned long long key2);
private:
	void decrypt();
	unsigned long long int m_ring;
	unsigned long long int m_e;
	unsigned long long int m_d;
	
};

#endif // !DECRYPT_HPP

