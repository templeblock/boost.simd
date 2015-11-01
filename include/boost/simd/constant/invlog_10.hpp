//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_INVLOG_10_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_INVLOG_10_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-constant

    Generate the constant invlog_10.

    @return The Invlog_10 constant for the proper type
  **/
  template<typename T> T Invlog_10();

  namespace functional
  {
    /*!
      @ingroup group-constant
      Generate the  constant invlog_10.

      @return The Invlog_10 constant for the proper type
    **/
    const boost::dispatch::functor<tag::invlog_10_> invlog_10 = {};
  }
} }
#endif

#include <boost/simd/constant/definition/invlog_10.hpp>
#include <boost/simd/arch/common/scalar/constant/constant_value.hpp>

#endif
