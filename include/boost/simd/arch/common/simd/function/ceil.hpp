//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_CEIL_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_CEIL_HPP_INCLUDED

#include <boost/simd/pack.hpp>
#include <boost/simd/function/simd/is_less.hpp>
#include <boost/simd/function/simd/round2even.hpp>
#include <boost/simd/function/simd/seladd.hpp>
#include <boost/simd/constant/one.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD(ceil_
                          , (typename A0, typename X)
                          , bd::cpu_
                          , bs::pack_<bd::floating_<A0>, X>
                          )
   {
      BOOST_FORCEINLINE A0 operator()( const A0& a0) const BOOST_NOEXCEPT
      {
        const A0 d0 = round2even(a0);
        return seladd(is_less(d0,a0),d0,One<A0>());
      }
   };

} } }


#endif

