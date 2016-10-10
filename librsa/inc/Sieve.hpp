#pragma once
using namespace std;

#include <vector>
#include <bitset>

class Sieve {
public:
        Sieve();
        bool isPrime(unsigned long long int);
        unsigned long long int getPos() const;
        unsigned long long int getSize() const;
private:
        bitset<(unsigned long long int)(10e10+10)> m_table;
        vector<unsigned long long int> m_primes;
};
