// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

/// bench for functor round in std mode for float type with std_.
#include <simd_bench.hpp>
#include <boost/simd/function/round.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;

DEFINE_SCALAR_BENCH(std_round, bs::std_(bs::round));

DEFINE_BENCH_MAIN()
{
  nsb::for_each<std_round, float>(-10, 10);
}
