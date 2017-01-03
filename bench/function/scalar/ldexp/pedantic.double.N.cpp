// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

/// bench for functor ldexp in scalar mode for double type with pedantic_.
#include <simd_bench.hpp>
#include <boost/simd/function/ldexp.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;
namespace bd =  boost::dispatch;

struct lde
{
  template<class T> T operator()(const T & a, const T & N) const
  {
    return bs::pedantic_(bs::ldexp)(a, bd::as_integer_t<T>(N));
  }
};

DEFINE_SCALAR_BENCH(scalar_ldexp, lde());

DEFINE_BENCH_MAIN()
{
  nsb::for_each<scalar_ldexp, double>(-10, 10, -10, 10);
}
