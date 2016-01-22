#include <iostream>

// basic operator
namespace metamath {

  template<long long int A, long long int B>
  struct div {
    enum { result = A / B };
  };

  template<long long int A, long long int B>
  struct mul {
    enum { result = A * B };
  };

  template<long long int A, long long int B>
  struct add {
    enum { result = A + B };
  };

  template<long long int A, long long int B>
  struct sub {
    enum { result = A - B };
  };

  template<long long int A, long long int B>
  struct mod {
    enum { result = A % B };
  };
}

namespace metamath {

  template<long long int A, long long int B>
  struct is_greater {
    enum { result = ((A > B) ? true : false) };
  };

  template<long long int A, long long int B>
  struct is_lower {
    enum { result = (A < B) ? true : false };
  };

  template<long long int A, long long int B>
  struct is_greater_or_equal {
    enum { result = (A >= B) ? true : false };
  };

  template<long long int A, long long int B>
  struct is_lower_or_equal {
    enum { result = (A <= B) ? true : false };
  };

  template<long long int A, long long int B>
  struct is_equal {
    enum { result = (A == B) ? true : false };
  };
};



// other function

namespace metamath {

  template<long long A>
  struct abs {
    enum { result = ((metamath::is_lower<A, 0>::result) ? metamath::mul<A, -1>::result : A) };
  };

  template<int A, int B, int C>
  struct fma {
    enum { result = metamath::add<metamath::mul<A, B>::result, C>::result };
  };
};



namespace metamath {

  template<int N, unsigned int T>
  struct pow {
    enum { 
      __abs = metamath::abs<N>::result,
      result = ((metamath::is_lower<N, 0>::result) ? -1 : 1) * __abs * pow<__abs, T - 1>::result };
  };

  template<int N>
  struct pow<N, 0> {
    enum { result = 1 };
  };

  /*  template<unsigned int N, unsigned int Z, unsigned int OLDZ, bool C>
  struct __sqrt {
    enum { result = }
  };

  template<unsigned int N, unsigned int Z, unsigned int OLDZ>
  struct __sqrt<N, Z, OLDZ, true> {
    enum { result = __sqrt<N, Z - (metamath::sub<metamath::mul<Z, Z>::result >::result };
  };

  template<unsigned int N, unsigned int Z, unsigned int OLDZ>
  struct __sqrt<N, Z, OLDZ, false> {
    enum { result = Z };
  };
  */
  /*
  template<long long N, long long int Z, long long int OLD_Z, bool C>
  struct __sqrt {
    constexpr static const double result = Z;
  };

  template<long long N,long long int Z,long long int OLD_Z>
  struct __sqrt<N, Z, OLD_Z, true> {
    constexpr static const double result = Z;
  };

  template<long long N, long long int Z, long long int OLD_Z>
  struct __sqrt<N, Z, OLD_Z, false> {
    constexpr static const double result  = __sqrt<N, Z - (Z*Z-N)/2*Z, Z, metamath::is_lower<metamath::abs<OLD_Z - Z>::result, 100>::result >::result;
  };

  template<long long N>
  struct sqrt {
    constexpr static const double result = __sqrt<N * 10000, (N * 10000) / 2, 0, false>::result;
  };
  */
  /*
  template<int A, int B>
  struct hypot {
    enum { result = 1 };
  };
  */
}

// Minimum, maximum, difference functions

namespace metamath {

  template<int A, int B, bool C>
  struct __min { 
    enum { result = A };
  };

  template<int A, int B>
  struct __min<A, B, false> {
    enum { result = A };
  };

  template<int A, int B>
  struct __min<A, B, true> {
    enum { result = B };
  };

  template<int A, int B>
  struct min {
    enum { result = __min<A, B, metamath::is_greater<A, B>::result>::result };
  };

  template<int A, int B, bool C>
  struct __max {
    enum { result = A };
  };

  template<int A, int B>
  struct __max<A, B, false> {
    enum { result = A };
  };

  template<int A, int B>
  struct __max<A, B, true> {
    enum { result = B };
  };

  template<int A, int B>
  struct max {
    enum { result = __min<A, B, metamath::is_lower<A, B>::result>::result };
  };

  template<int A, int B, bool C>
  struct __fdim {
    enum { result = metamath::sub<A, B>::result };
  };

  template<int A, int B>
  struct __fdim<A, B, false> {
    enum { result = 0 };
  };

  template<int A, int B>
  struct __fdim<A, B, true> {
    enum { result = metamath::sub<A, B>::result };
  };

  template<int A, int B>
  struct fdim {
    enum { result = __fdim<A, B, metamath::is_lower<A, B>::result >::result };
  };
};
