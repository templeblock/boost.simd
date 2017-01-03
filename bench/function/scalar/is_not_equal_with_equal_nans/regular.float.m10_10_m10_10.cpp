// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

/// bench for functor is_not_equal_with_equal_nans in scalar mode for float type with no decorator (regular call).
#include <simd_bench.hpp>
#include <boost/simd/function/is_not_equal_with_equal_nans.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;

DEFINE_SCALAR_BENCH(scalar_is_not_equal_with_equal_nans, bs::is_not_equal_with_equal_nans);

DEFINE_BENCH_MAIN()
{
  nsb::for_each<scalar_is_not_equal_with_equal_nans, float>(-10, 10, -10, 10);
}
