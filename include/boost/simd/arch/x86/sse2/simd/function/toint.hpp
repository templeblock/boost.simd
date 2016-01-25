//==================================================================================================
/*!
    @file

    @Copyright 2016 Numscale SAS
    @copyright 2016 J.T.Lapreste

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_TOINT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_TOINT_HPP_INCLUDED

#include <boost/dispatch/meta/as_integer.hpp>
//#include <boost/simd/function/simd/split_low.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd =  boost::dispatch;
  namespace bs =  boost::simd;
  // TODO split_low
//   BOOST_DISPATCH_OVERLOAD ( toint_
//                           , (typename A0)
//                           , bs::sse2_
//                           , bs::pack_<bd::double_<A0>, bs::sse_>
//                           , bs::fast_tag
//                          )
//   {
//     BOOST_FORCEINLINE  bd::as_integer_t<A0>  operator() ( const A0 & a0, const fast_tag &) const BOOST_NOEXCEPT
//     {
//       auto out = _mm_cvttpd_epi32(a0);
//       return bs::split_low(out);
//     }
//   };

  BOOST_DISPATCH_OVERLOAD ( toint_
                          , (typename A0)
                          , bs::sse2_
                          , bs::pack_<bd::single_<A0>, bs::sse_>
                         )
  {
    BOOST_FORCEINLINE bd::as_integer_t<A0> operator() ( const A0 & a0) const BOOST_NOEXCEPT
    {
      return _mm_cvttps_epi32(a0);
    }
  };
} } }

#endif
