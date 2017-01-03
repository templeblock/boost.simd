// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

/// bench for functor nthroot in scalar mode for float type with raw_.
#include <simd_bench.hpp>
#include <boost/simd/function/nthroot.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;
namespace bd =  boost::dispatch;

struct nthr
{
  template<class T> T operator()(const T & a, const T & N) const
  {
    return bs::raw_(bs::nthroot)(a, bd::as_integer_t<T>(N));
  }
};
DEFINE_SCALAR_BENCH(scalar_nthroot, nthr());

DEFINE_BENCH_MAIN()
{
  nsb::for_each<scalar_nthroot, float>(0, 10, 0, 10);
}
