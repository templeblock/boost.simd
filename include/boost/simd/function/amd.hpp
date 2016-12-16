//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_AMD_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_AMD_HPP_INCLUDED
#include <boost/simd/detail/decorator.hpp>

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-decorator

    provides an easy way to use the original  amdlibc++ function that is mimicked by one of our functors.

    @par Semantic

    For a function object @c func,

    @code
    auto amd_func = amd_(func);
    @endcode

    is equivalent to:

    @code
    T r = amd::func(< func parameters >);
    @endcode

    @par Notes:

    - for simd vector parameter a map of the standard function is done automagically
      for each vector element but of course there is no vectorization gain.

    - amd_ is only a convenience feature for people which
      sometimes have to stick to the standard or
      test the standard behaviour against **Boost.SIMD**.

  **/
  const detail::decorator<amd_tag> amd_ = {};
} }
#endif

namespace boost { namespace simd
{
  struct amd_tag : decorator_<amd_tag>
  {
    using parent = decorator_<amd_tag>;
  };

  const detail::decorator<amd_tag> amd_ = {};
} }

#endif
