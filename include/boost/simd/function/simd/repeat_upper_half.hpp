//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SIMD_REPEAT_UPPER_HALF_INCLUDED
#define BOOST_SIMD_FUNCTION_SIMD_REPEAT_UPPER_HALF_INCLUDED

#include <boost/simd/function/scalar/repeat_upper_half.hpp>

#if defined(BOOST_HW_SIMD_X86)

#  if BOOST_HW_SIMD_X86 >= BOOST_HW_SIMD_X86_SSE_VERSION
#    include <boost/simd/arch/x86/sse1/simd/function/repeat_upper_half.hpp>
#  endif
#  if BOOST_HW_SIMD_X86 >= BOOST_HW_SIMD_X86_AVX_VERSION
#    include <boost/simd/arch/x86/avx/simd/function/repeat_upper_half.hpp>
#  endif

#endif

#if defined(BOOST_HW_SIMD_PPC)

#  if BOOST_HW_SIMD_PPC >= BOOST_HW_SIMD_PPC_VMX_VERSION
#    include <boost/simd/arch/power/vmx/simd/function/repeat_upper_half.hpp>
#  endif

#endif

#if defined(BOOST_HW_SIMD_ARM)

#  if BOOST_HW_SIMD_ARM >= BOOST_HW_SIMD_ARM_NEON_VERSION
#    include <boost/simd/arch/arm/neon/simd/function/repeat_upper_half.hpp>
#  endif

#endif

#endif
