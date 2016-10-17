#ifndef ENCRYPT_HPP
#define ENCRYPT_HPP

using namespace std;

#include <fstream>
#include "PrimeSet.hpp"
#include "Math2.hpp"

class Encrypt {
public:
        Encrypt(string input, string output);
        string getKeyP();
        string getKeyQ();
        string getKeyD();
private:
        void pickOdd();
        void totiente();
        void choosePair();
        bool loadMedia(string iPath);
        void encrypt();
        string m_path_input;
        string m_path_output;
        fstream m_in;
        fstream m_out;
        PrimeSet m_primes;
        unsigned long long int MAX_IDX = 10e9;
        unsigned long long int m_p;
        unsigned long long int m_q;
        unsigned long long int m_multply;
        unsigned long long int m_ring;
        unsigned long long int m_e;
        unsigned long long int m_d;
};

#endif // !ENCRYPT_HPP