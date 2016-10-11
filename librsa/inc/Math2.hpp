#pragma once

typedef unsigned long long int ulong_64;

class Math2 {
public:
        Math2();
        static ulong_64 exp(ulong_64 base, ulong_64 _exp, ulong_64 mod);
        static ulong_64 inv(ulong_64 value, ulong_64 mod);
        static ulong_64 gcd(ulong_64 v1,ulong_64 v2);
        static ulong_64 sqrt(ulong_64 v1);
};
