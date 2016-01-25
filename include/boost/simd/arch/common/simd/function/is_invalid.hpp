//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IS_INVALID_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IS_INVALID_HPP_INCLUDED

#include <boost/simd/pack.hpp>
#include <boost/simd/constant/true.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/function/simd/is_nan.hpp>
#include <boost/simd/function/simd/minus.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD(is_invalid_
                          , (typename A0, typename X)
                          , bd::cpu_
                          , bs::pack_<bd::arithmetic_<A0>, X>
                          )
   {
     using result =  bs::as_logical_t<A0> ;
     BOOST_FORCEINLINE result operator()(const A0&) const
      {
        return bs::False<result>();
      }
   };

   BOOST_DISPATCH_OVERLOAD(is_invalid_
                          , (typename A0, typename X)
                          , bd::cpu_
                          , bs::pack_<bd::floating_<A0>, X>
                          )
   {
      BOOST_FORCEINLINE  bs::as_logical_t<A0> operator()( const A0& a0) const BOOST_NOEXCEPT
      {
         return is_nan(a0-a0);
      }
   };

} } }


#endif

