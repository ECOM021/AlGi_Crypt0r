#pragma once
using namespace std;

#include "Sieve.hpp"
#include <fstream>

class Encrypt {
public:
        Encrypt();

private:
        void pickOdd();
        void totiente();
        void choosePair();

        fstream m_in;
        fstream m_out;
        unsigned long long int m_p;
        unsigned long long int m_q;
        unsigned long long int m_multply;
        unsigned long long int m_ring;
        unsigned long long int m_e;
        unsigned long long int m_d;
};
