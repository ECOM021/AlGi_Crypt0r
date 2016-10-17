#include "../inc/Math2.hpp"

Math2::Math2() {
}

ulong_64 Math2::exp(ulong_64 base, ulong_64 _exp, ulong_64 mod) {
   ulong_64 pot = base % mod;
   ulong_64 resultado = 1;

  for ( ; _exp > 0; _exp /= 2) {
    if (_exp&1)  /* O bit menos significativo e 1 */
      resultado = (resultado * pot) % mod;
    pot = (pot * pot) % mod;
  }
  return resultado;
}

ulong_64 Math2::inv(ulong_64 value, ulong_64 mod) {
  return exp(value, mod-1, mod);
}

ulong_64 Math2::gcd( ulong_64 a, ulong_64 b ) {
	if( !b ) return a;
	return gcd( b, a%b );
}

ulong_64 Math2::sqrt(ulong_64 v) {
    if (v == 0 || v == 1)
       return v;
    ulong_64 start = 1, end = v, ans;
    while (start <= end)
    {
        ulong_64 mid = (start + end)>>1;
        if (mid*mid == v)
            return mid;
        if (mid*mid < v)
        {
            start = mid + 1;
            ans = mid;
        }
        else
            end = mid - 1;
    }
    return ans;
}
