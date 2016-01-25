//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_FFS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_FFS_HPP_INCLUDED

#include <boost/simd/pack.hpp>
#include <boost/simd/function/simd/b_and.hpp>
#include <boost/simd/function/simd/bitwise_cast.hpp>
#include <boost/simd/function/simd/firstbitset.hpp>
#include <boost/simd/function/simd/genmask.hpp>
#include <boost/simd/function/simd/if_else.hpp>
#include <boost/simd/function/simd/inc.hpp>
#include <boost/simd/function/simd/seladd.hpp>
#include <boost/simd/function/simd/shift_left.hpp>
#include <boost/simd/function/simd/shr.hpp>
#include <boost/simd/function/simd/unary_minus.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/dispatch/meta/scalar_of.hpp>
 #include <boost/simd/constant/ratio.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD(ffs_
                          , (typename A0, typename X)
                          , bd::cpu_
                          , bs::pack_<bd::type8_<A0>, X>
                          )
   {
      using result = bd::as_integer_t<A0, unsigned>;
      BOOST_FORCEINLINE result operator()( const A0& a0) const BOOST_NOEXCEPT
      {
        using ltype = pack<uint64_t>; //typename limits<X>::largest_integer;
        result v = firstbitset(a0);
        return  b_and(genmask(v), inc(b_or(b_or((-( genmask(b_and(v, ltype(0xAAAAAAAAAAAAAAAAull)))))
                                               , shift_left(-( genmask(b_and(v, ltype(0xCCCCCCCCCCCCCCCCull)))), 1))
                                          , shift_left(-( genmask(b_and(v, ltype(0xF0F0F0F0F0F0F0F0ull)))), 2))));
      }
   };

   BOOST_DISPATCH_OVERLOAD(ffs_
                          , (typename A0, typename X)
                          , bd::cpu_
                          , bs::pack_<bd::type64_<A0>, X>
                          )
   {
      using result = bd::as_integer_t<A0, unsigned>;
      BOOST_FORCEINLINE result operator()( const A0& a0) const BOOST_NOEXCEPT
      {
        using si_t = bd::scalar_of_t<A0>;
        si_t z0 =  ffs(si_t(a0[0]));
        si_t z1 =  ffs(si_t(a0[1]));
        return {z0, z1};
//        return  simd::bitwise_cast<rtype>(map(dispatch::functor<bs::tag::ffs_>(), simd::bitwise_cast<rtype>(a0)));
      }
   };

   BOOST_DISPATCH_OVERLOAD(ffs_
                          , (typename A0, typename X)
                          , bd::cpu_
                          , bs::pack_<bd::type16_<A0>, X>
                          )
   {
      using result = bd::as_integer_t<A0, unsigned>;
      BOOST_FORCEINLINE result operator()( const A0& a0) const BOOST_NOEXCEPT
      {
        using ltype =  pack < uint64_t > ; //typename limits<X>::largest_integer;
        result v = firstbitset(a0);
        return  b_and(genmask(v), inc(b_or(b_or(b_or((-( genmask(b_and(v, ltype(0xAAAAAAAAAAAAAAAAull)))))
                                                     , shift_left(-( genmask(b_and(v, ltype(0xCCCCCCCCCCCCCCCCull)))), 1))
                                                , shift_left(-( genmask(b_and(v, ltype(0xF0F0F0F0F0F0F0F0ull)))), 2))
                                           , shift_left(-( genmask(b_and(v, ltype(0xFF00FF00FF00FF00ull)))), 3))));
      }
   };

   BOOST_DISPATCH_OVERLOAD(ffs_
                          , (typename A0, typename X)
                          , bd::cpu_
                          , bs::pack_<bd::type32_<A0>, X>
                          )
   {
      using result = bd::as_integer_t<A0, unsigned>;
      BOOST_FORCEINLINE result operator()( const A0& a0) const BOOST_NOEXCEPT
      {
        using ltype =  pack < uint64_t>; //typename limits<X>::largest_integer;
        result v = firstbitset(a0);
        return  b_and(genmask(v), inc(b_or(b_or(b_or(b_or((-( genmask(b_and(v, ltype(0xAAAAAAAAAAAAAAAAull)))))
                                                         , shift_left(-( genmask(b_and(v, ltype(0xCCCCCCCCCCCCCCCCull)))), 1))
                                                    , shift_left(-( genmask(b_and(v, ltype(0xF0F0F0F0F0F0F0F0ull)))), 2))
                                               , shift_left(-( genmask(b_and(v, ltype(0xFF00FF00FF00FF00ull)))), 3))
                                          , shift_left(-( genmask(b_and(v, ltype(0xFFFF0000FFFF0000ull)))), 4))));
      }
   };

} } }


#endif

