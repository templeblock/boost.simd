//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_NONE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_NONE_HPP_INCLUDED

#include <boost/simd/pack.hpp>
#include <boost/simd/function/simd/any.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD(none_
                          , (typename A0, typename X)
                          , bd::cpu_
                          , bs::pack_<bd::fundamental_<A0>, X>
                          )
   {
     BOOST_FORCEINLINE  bool operator()( const A0& a0) const BOOST_NOEXCEPT
     {
       return !bs::any(a0);
     }
   };

} } }

#endif

