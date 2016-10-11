#pragma once
using namespace std;
#include "../../libhuffman/inc/Globals.hpp"
#include "Math2.hpp"
class Sieve {
public:
        Sieve();
        bool isPrime(unsigned long long int idx);
        unsigned long long int getPos(unsigned long long int idx) const;
        unsigned long long int getSize() const;
private:
        vector<unsigned long long int> m_primes;
};
