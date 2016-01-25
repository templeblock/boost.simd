//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SIMD_RROR_INCLUDED
#define BOOST_SIMD_FUNCTION_SIMD_RROR_INCLUDED

#include <boost/simd/function/scalar/rror.hpp>
#include <boost/simd/arch/common/simd/function/rror.hpp>

#if defined(BOOST_HW_SIMD_X86)

#  if BOOST_HW_SIMD_X86 >= BOOST_HW_SIMD_X86_XOP_VERSION
#    include <boost/simd/arch/x86/xop/simd/function/rror.hpp>
#  endif

#endif

#endif
