//==================================================================================================
/*!
    @file

    @Copyright 2016 Numscale SAS
    @copyright 2016 J.T.Lapreste

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE1_SIMD_FUNCTION_INBTRUE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE1_SIMD_FUNCTION_INBTRUE_HPP_INCLUDED
#include <boost/simd/pack.hpp>
#include <boost/simd/function/simd/genmask.hpp>
#include <boost/simd/function/scalar/popcnt.hpp>
namespace boost { namespace simd { namespace ext
{
  namespace bd =  boost::dispatch;
  namespace bs =  boost::simd;
  BOOST_DISPATCH_OVERLOAD ( inbtrue_
                          , (typename A0)
                          , bs::sse_
                          , bs::pack_<bd::single_<A0>, bs::sse_>
                         )
  {
    BOOST_FORCEINLINE std::size_t operator() ( const A0 & a0 ) const BOOST_NOEXCEPT
    {
      auto r = _mm_movemask_ps(genmask(a0));
      return popcnt(r);
//      return (r&1)+((r>>1)&1)+((r>>2)&1)+(r>>3);

   }
  };
} } }

#endif

