#ifndef PRIMESET_HPP
#define PRIMESET_HPP

#include "../../libhuffman/inc/Globals.hpp"
#include "Math2.hpp"
class PrimeSet {
public:
        PrimeSet();
        bool isPrime(unsigned long long int idx);
        unsigned long long int getPos(unsigned long long int idx) const;
        unsigned long long int getSize() const;
private:
        set<unsigned long long int> m_primes;
};

#endif // !PRIMESET_HPP