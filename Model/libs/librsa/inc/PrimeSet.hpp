#ifndef PRIMESET_HPP
#define PRIMESET_HPP

#include "../../libhuffman/inc/Globals.hpp"
#include "Math2.hpp"
#include <algorithm>
class PrimeSet {
public:
        PrimeSet();
        unsigned long long int getNthPrime( ulong_64 idx ) const;
        unsigned long long int getSize() const;
private:
        vector<unsigned long long int> * m_primes;
};

#endif // !PRIMESET_HPP