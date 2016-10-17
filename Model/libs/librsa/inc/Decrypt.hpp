#ifndef DECRYPT_HPP
#define DECRYPT_HPP

#include <fstream>
#include <string>
#include <iostream>
#include "Math2.hpp"

typedef unsigned char uchar;
typedef unsigned long long int ulong_64;

class Decrypt {
public:
	Decrypt(std::string input, std::string output, 
	             ulong_64 key1 , ulong_64 key2, ulong_64 d);
	std::string getOutput();
private:
	void decrypt();
	ulong_64 m_ring;
	ulong_64 m_e;
	ulong_64 m_d;
	ulong_64 m_p;
	ulong_64 m_q;
	std::ifstream m_input;
	std::ofstream m_output;
	std::string m_path_input;
	std::string m_path_output;
};

#endif // !DECRYPT_HPP

