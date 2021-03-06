//==================================================================================================
/*!
    @file

    @Copyright 2016 Numscale SAS

    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE1_SIMD_FUNCTION_DIVIDES_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE1_SIMD_FUNCTION_DIVIDES_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#if defined(BOOST_SIMD_COMPILER_GCC) && BOOST_SIMD_GCC_VERSION < 40603
#  include <boost/simd/function/logical_and.hpp>
#  include <boost/simd/function/is_eqz.hpp>
#  include <boost/simd/function/if_nan_else.hpp>
#endif

namespace boost { namespace simd { namespace ext
{
  namespace bd =  boost::dispatch;
  namespace bs =  boost::simd;
  BOOST_DISPATCH_OVERLOAD ( divides_
                          , (typename A0)
                          , bs::sse1_
                          , bs::pack_<bd::single_<A0>, bs::sse_>
                          , bs::pack_<bd::single_<A0>, bs::sse_>
                         )
  {
    BOOST_FORCEINLINE A0 operator() ( const A0 & a0
                                    , const A0 & a1 ) const BOOST_NOEXCEPT
    {
      A0 const that = _mm_div_ps(a0,a1);
#if defined(BOOST_SIMD_COMPILER_GCC) && BOOST_SIMD_GCC_VERSION < 40603
      // workaround for GCC bug #50396 fixed in 4.6.3  But apparently not in 4.7.0
      return if_nan_else(logical_and(is_eqz(a0), is_eqz(a1)), that);
#else
      return that;
#endif
    }
  };
} } }

#endif

