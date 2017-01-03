// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

/// bench for functor reversebits in simd mode for int16_t type with no decorator (regular call).
#include <simd_bench.hpp>
#include <boost/simd/constant/valmin.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/function/reversebits.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;

DEFINE_SIMD_BENCH(simd_reversebits, bs::reversebits);

DEFINE_BENCH_MAIN()
{
  nsb::for_each<simd_reversebits, int16_t>(bs::Valmin<int16_t>(), bs::Valmax<int16_t>());
}
