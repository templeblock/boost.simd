// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

/// bench for functor bitwise_notor in simd mode for double type with no decorator (regular call).
#include <simd_bench.hpp>
#include <boost/simd/function/bitwise_notor.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;

DEFINE_SIMD_BENCH(simd_bitwise_notor, bs::bitwise_notor);

DEFINE_BENCH_MAIN()
{
  nsb::for_each<simd_bitwise_notor, double>(-10, 10,-10, 10);
}
