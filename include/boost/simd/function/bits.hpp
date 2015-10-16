//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_BITS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_BITS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-bitwise

    Computes bits value of its parameter.

  **/
  template<typename T> auto bits(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-bitwise

      Function object tied to simd::bits

      @see simd::bits
    **/
    const boost::dispatch::functor<tag::bits_> bits = {};
  }
} }
#endif

#include <boost/simd/function/definition/bits.hpp>
#include <boost/simd/arch/common/generic/function/bits.hpp>
//#include <boost/simd/arch/common/function/simd/bits.hpp>

#endif