//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SIMD_BITWISE_SELECT_INCLUDED
#define BOOST_SIMD_FUNCTION_SIMD_BITWISE_SELECT_INCLUDED

#include <boost/simd/function/scalar/bitwise_select.hpp>
#include <boost/simd/arch/common/generic/function/bitwise_select.hpp>

#if defined(BOOST_HW_SIMD_X86)

#  if BOOST_HW_SIMD_X86 >= BOOST_HW_SIMD_X86_XOP_VERSION
// #    include <boost/simd/arch/x86/xop/simd/function/bitwise_select.hpp>
#  endif

#endif

#if defined(BOOST_HW_SIMD_PPC)

#  if BOOST_HW_SIMD_PPC >= BOOST_HW_SIMD_PPC_VMX_VERSION
// #    include <boost/simd/arch/power/vmx/simd/function/bitwise_select.hpp>
#  endif

#endif

#if defined(BOOST_HW_SIMD_ARM)

#  if BOOST_HW_SIMD_ARM >= BOOST_HW_SIMD_ARM_NEON_VERSION
// #    include <boost/simd/arch/arm/neon/simd/function/bitwise_select.hpp>
#  endif
#  if BOOST_HW_SIMD_ARM >= BOOST_HW_SIMD_ARM_NEON64_VERSION
// #    include <boost/simd/arch/arm/neon64/simd/function/bitwise_select.hpp>
#  endif

#endif

#endif
