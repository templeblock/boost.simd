//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_EXPONENT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_EXPONENT_HPP_INCLUDED

#include <boost/simd/pack.hpp>
#include <boost/simd/constant/maxexponent.hpp>
#include <boost/simd/constant/nbmantissabits.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/function/simd/exponentbits.hpp>
#include <boost/simd/function/simd/selsub.hpp>
#include <boost/simd/function/simd/shr.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/dispatch/meta/scalar_of.hpp>

#ifndef BOOST_SIMD_NO_INVALIDS
#include <boost/simd/function/simd/if_zero_else.hpp>
#include <boost/simd/function/simd/is_invalid.hpp>
#endif
#if defined(__INTEL_COMPILER) && defined(BOOST_SIMD_HAS_AVX_SUPPORT) && !defined(BOOST_SIMD_HAS_AVX2_SUPPORT)
#include <boost/simd/function/simd/if_else.hpp>
#include <boost/simd/function/simd/minus.hpp>
#endif


namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD(exponent_
                          , (typename A0, typename X)
                          , bd::cpu_
                          , bs::pack_<bd::integer_<A0>, X>
                          )
   {
      using result = bd::as_integer_t<A0, signed>;
     BOOST_FORCEINLINE result operator()(A0 const&) const
      {
        return Zero<result>();
      }
   };

   BOOST_DISPATCH_OVERLOAD(exponent_
                          , (typename A0, typename X)
                          , bd::cpu_
                          , bs::pack_<bd::floating_<A0>, X>
                          )
   {
      using result = bd::as_integer_t<A0, signed>;
      BOOST_FORCEINLINE result operator()( const A0& a0) const BOOST_NOEXCEPT
      {
        using s_type = bd::scalar_of_t<A0>;
        const int nmb= int(Nbmantissabits<s_type>());
        result x = shr(exponentbits(a0), nmb);
        // workaround for ICC 14.0.3, tested on AVX
        #if defined(__INTEL_COMPILER) && defined(BOOST_SIMD_HAS_AVX_SUPPORT) && !defined(BOOST_SIMD_HAS_AVX2_SUPPORT)
        x = x - if_else(a0, Maxexponent<A0>(), Zero<result>());
        #else
        x = selsub(a0, x, Maxexponent<A0>());
        #endif
        #ifndef BOOST_SIMD_NO_INVALIDS
        return if_zero_else( is_invalid(a0), x );
        #else
        return x;
        #endif
      }
   };

} } }

#endif

