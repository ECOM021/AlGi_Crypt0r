#ifndef PRIMESET_HPP
#define PRIMESET_HPP

#include "../../libhuffman/inc/Globals.hpp"
#include "Math2.hpp"
#include <algorithm>

typedef ulong_64 ulong_64;

class PrimeSet {
public:
        PrimeSet();
        ulong_64 getNthPrime( ulong_64 idx ) const;
        ulong_64 getSize() const;
private:
        vector<ulong_64> * m_primes;
};

#endif // !PRIMESET_HPP