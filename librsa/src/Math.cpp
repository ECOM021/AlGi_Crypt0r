#include "./Math.hpp"

Math::Math() {
}

static ulong_64 exp(ulong_64 base, ulong_64 _exp, ulong_64 mod) {
  ulong_64 ans = 1;
  while( _exp ) {
    if( _exp&1 ) ans = (ans*base)%mod;
    _exp >>= 1;
    base = (base<<1)%mod;
  }
  return ans;
}
static ulong_64 inv(ulong_64 value, ulong_64 mod) {0
  return exp(value, mod-2, mod);
}
static ulong_64 gcd(ulong_64 v1,ulong_64 v2){
    return a ? gcd(v1%v2, int v1) : v2;
}
