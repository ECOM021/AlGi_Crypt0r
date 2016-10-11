#include "../inc/Math2.hpp"

Math2::Math2() {
}

ulong_64 Math2::exp(ulong_64 base, ulong_64 _exp, ulong_64 mod) {
  if( _exp == 1 )
    return base%mod;
  else {
    ulong_64 v = exp(base,_exp>>1,mod);
    v = (v*v)%mod;
    if( _exp&1 )
      return (base*v)%mod;
    return v;
  }
}
ulong_64 Math2::inv(ulong_64 value, ulong_64 mod) {
  return exp(value, mod-2, mod);
}
ulong_64 Math2::gcd( ulong_64 a, ulong_64 b ) {
	if( !b ) return a;
	return gcd( b, a%b );
}
ulong_64 Math2::sqrt(ulong_64 v) {
  ulong_64 lower = 0;
  ulong_64 mid;
  ulong_64 upper = v;
  while( lower < upper ) {
    mid = (lower+upper)>>1;
    if( mid*mid == v )
      return mid;
    else {
      if( mid*mid > v ) upper = mid-1;
      else lower = mid+1;
    }
  }
  return mid;
}
