//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/constant/log_2.hpp>
#include <boost/simd/as.hpp>
#include <stf.hpp>

STF_CASE_TPL( "Check log_2 behavior for integral types"
            , (std::uint32_t)(std::uint64_t)
              (std::int32_t)(std::int64_t)
            )
{
  using boost::simd::as;
  using boost::simd::functional::log_2;
  using boost::simd::Log_2;
  T ref = T(0);
  STF_TYPE_IS(decltype(Log_2<T>()), T);
  STF_EQUAL(Log_2<T>(), ref);
  STF_EQUAL(log_2( as(T{}) ),ref);
}

STF_CASE_TPL( "Check log_2 behavior for double"
            , (double)(float)
            )
{
  using boost::simd::as;
  using boost::simd::functional::log_2;
  using boost::simd::Log_2;
  T ref = T(0.693147180559945309417232121458);

  STF_TYPE_IS(decltype(Log_2<T>()), T);
  STF_IEEE_EQUAL(Log_2<T>(), ref);
  STF_IEEE_EQUAL(log_2( as(T{}) ), ref);
}

