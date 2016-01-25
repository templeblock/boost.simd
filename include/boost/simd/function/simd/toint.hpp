//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SIMD_TOINT_INCLUDED
#define BOOST_SIMD_FUNCTION_SIMD_TOINT_INCLUDED

#include <boost/simd/function/scalar/toint.hpp>
#include <boost/simd/arch/common/simd/function/toint.hpp>

#if defined(BOOST_HW_SIMD_X86)

#  if BOOST_HW_SIMD_X86 >= BOOST_HW_SIMD_X86_SSE2_VERSION
#    include <boost/simd/arch/x86/sse2/simd/function/toint.hpp>
#  endif
#  if BOOST_HW_SIMD_X86 >= BOOST_HW_SIMD_X86_AVX_VERSION
#    include <boost/simd/arch/x86/avx/simd/function/toint.hpp>
#  endif

#endif

#if defined(BOOST_HW_SIMD_ARM)

#  if BOOST_HW_SIMD_ARM >= BOOST_HW_SIMD_ARM_NEON_VERSION
#    include <boost/simd/arch/arm/neon/simd/function/toint.hpp>
#  endif

#endif

#endif
