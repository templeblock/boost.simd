//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_EXP_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE2_SIMD_FUNCTION_EXP_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/traits.hpp>
#include <boost/simd/arch/common/detail/simd/exponential.hpp>
#include <boost/simd/function/amd.hpp>
#include <boost/simd/function/restricted.hpp>

extern "C"{
    __m128d amd_vrd2_exp    (__m128d x);
    __m128  amd_vrs4_expf   (__m128  x);

}

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  BOOST_DISPATCH_OVERLOAD( exp_
                         , (typename A0)
                         , bs::sse2_
                         , bs::amd_tag
                         , bs::pack_< bd::single_<A0>, bs::sse_>
                         )
  {
    BOOST_FORCEINLINE A0 operator() (amd_tag const &, A0 const& a0) const BOOST_NOEXCEPT
    {
      return ::amd_vrs4_expf(a0.storage());
    }
  };

  BOOST_DISPATCH_OVERLOAD( exp_
                         , (typename A0)
                         , bs::sse2_
                         , amd_tag
                         , bs::pack_< bd::double_<A0>, bs::sse_>
                         )
  {
    BOOST_FORCEINLINE A0 operator() (amd_tag const &, A0 const& a0) const BOOST_NOEXCEPT
    {
      return ::amd_vrd2_exp(a0);
    }
  };
} } }

#endif
