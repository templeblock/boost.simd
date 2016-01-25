//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_SELADD_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_SELADD_HPP_INCLUDED

#include <boost/simd/pack.hpp>
#include <boost/simd/cardinal_of.hpp>
#include <boost/simd/function/simd/if_else_zero.hpp>
#include <boost/simd/function/simd/plus.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
  BOOST_DISPATCH_OVERLOAD(seladd_
                         , (typename A0, typename A1, typename X)
                         , bd::cpu_
                         , bs::pack_<bd::fundamental_<A0>, X>
                         , bs::pack_<bd::arithmetic_<A1>, X>
                         , bs::pack_<bd::arithmetic_<A1>, X>
                         )
   {
     BOOST_FORCEINLINE A1 operator()( A0 const& a0
                                    , A1 const& a1, A1 const& a2) const BOOST_NOEXCEPT
     {
       return a1+if_else_zero(a0, a2);
     }
   };

} } }

#endif

