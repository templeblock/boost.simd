// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------

/// bench for functor abs in extern mode for double type with std_.
#include <simd_bench.hpp>
#include <boost/simd/function/abs.hpp>

namespace nsb = ns::bench;
namespace bs =  boost::simd;

DEFINE_EXTERN_BENCH(extern_abs, bs::std_(bs::abs));

DEFINE_BENCH_MAIN()
{
  nsb::for_each<extern_abs, double>(-10, 10);
}
