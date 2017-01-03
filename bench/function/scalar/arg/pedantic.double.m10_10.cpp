// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

/// bench for functor arg in scalar mode for double type with pedantic_.
#include <simd_bench.hpp>
#include <boost/simd/function/arg.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;

DEFINE_SCALAR_BENCH(scalar_arg, bs::pedantic_(bs::arg));

DEFINE_BENCH_MAIN()
{
  nsb::for_each<scalar_arg, double>(-10, 10);
}
