//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_NEGIFNOT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_NEGIFNOT_HPP_INCLUDED

#include <boost/simd/pack.hpp>
#include <boost/simd/function/simd/if_else.hpp>
#include <boost/simd/function/simd/unary_minus.hpp>
#include <boost/mpl/equal_to.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD(negifnot_
                             , (typename A0, typename A1, typename X)
                             , bd::cpu_
                             , bs::pack_<bd::unspecified_<A0>, X>
                             , bs::pack_<bd::signed_<A1>, X>
                             )
   {
      BOOST_FORCEINLINE A1 operator()( const A0& a0, const  A1&  a1) const BOOST_NOEXCEPT
      {
        return if_else(a0,a1, unary_minus(a1));
      }
   };

} } }

#endif

