//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_PPC_VMX_PACK_TRAITS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_PPC_VMX_PACK_TRAITS_HPP_INCLUDED

#include <boost/config.hpp>
#include <boost/simd/detail/pack_traits.hpp>
#include <boost/simd/detail/pack_support.hpp>

namespace boost { namespace simd
{
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::int8_t  , 16, __vector signed   char, ::boost::simd::vmx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::uint8_t , 16, __vector unsigned char, ::boost::simd::vmx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(char         , 16, __vector unsigned char, ::boost::simd::vmx_)

  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::int16_t ,  8, __vector signed   short, ::boost::simd::vmx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::uint16_t,  8, __vector unsigned short, ::boost::simd::vmx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::int8_t  ,  8, __vector signed   char , ::boost::simd::vmx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::uint8_t ,  8, __vector unsigned char , ::boost::simd::vmx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(char         ,  8, __vector unsigned char , ::boost::simd::vmx_)

  BOOST_SIMD_ENABLE_PACK_SUPPORT(float        ,  4, __vector        float  , ::boost::simd::vmx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::int32_t ,  4, __vector signed   int  , ::boost::simd::vmx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::uint32_t,  4, __vector unsigned int  , ::boost::simd::vmx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::int16_t ,  4, __vector signed   short, ::boost::simd::vmx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::uint16_t,  4, __vector unsigned short, ::boost::simd::vmx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::int8_t  ,  4, __vector signed   char , ::boost::simd::vmx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::uint8_t ,  4, __vector unsigned char , ::boost::simd::vmx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(char         ,  4, __vector unsigned char , ::boost::simd::vmx_)

  BOOST_SIMD_ENABLE_PACK_SUPPORT(float        ,  2, __vector        float  , ::boost::simd::vmx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::int32_t ,  2, __vector signed   int  , ::boost::simd::vmx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::uint32_t,  2, __vector unsigned int  , ::boost::simd::vmx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::int16_t ,  2, __vector signed   short, ::boost::simd::vmx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::uint16_t,  2, __vector unsigned short, ::boost::simd::vmx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::int8_t  ,  2, __vector signed   char , ::boost::simd::vmx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::uint8_t ,  2, __vector unsigned char , ::boost::simd::vmx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(char         ,  2, __vector unsigned char , ::boost::simd::vmx_)

  BOOST_SIMD_ENABLE_PACK_SUPPORT(float        ,  1, __vector        float  , ::boost::simd::vmx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::int32_t ,  1, __vector signed   int  , ::boost::simd::vmx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::uint32_t,  1, __vector unsigned int  , ::boost::simd::vmx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::int16_t ,  1, __vector signed   short, ::boost::simd::vmx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::uint16_t,  1, __vector unsigned short, ::boost::simd::vmx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::int8_t  ,  1, __vector signed   char , ::boost::simd::vmx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::uint8_t ,  1, __vector unsigned char , ::boost::simd::vmx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(char         ,  1, __vector unsigned char , ::boost::simd::vmx_)

  // Match also the bool funky types from VMX
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::int8_t  , 16, __vector __bool char, ::boost::simd::vmx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::uint8_t , 16, __vector __bool char, ::boost::simd::vmx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(char         , 16, __vector __bool char, ::boost::simd::vmx_)

  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::int16_t ,  8, __vector __bool short, ::boost::simd::vmx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::uint16_t,  8, __vector __bool short, ::boost::simd::vmx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::int8_t  ,  8, __vector __bool char , ::boost::simd::vmx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::uint8_t ,  8, __vector __bool char , ::boost::simd::vmx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(char         ,  8, __vector __bool char , ::boost::simd::vmx_)

  BOOST_SIMD_ENABLE_PACK_SUPPORT(float        ,  4, __vector __bool int  , ::boost::simd::vmx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::int32_t ,  4, __vector __bool int  , ::boost::simd::vmx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::uint32_t,  4, __vector __bool int  , ::boost::simd::vmx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::int16_t ,  4, __vector __bool short, ::boost::simd::vmx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::uint16_t,  4, __vector __bool short, ::boost::simd::vmx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::int8_t  ,  4, __vector __bool char , ::boost::simd::vmx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::uint8_t ,  4, __vector __bool char , ::boost::simd::vmx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(char         ,  4, __vector __bool char , ::boost::simd::vmx_)

  BOOST_SIMD_ENABLE_PACK_SUPPORT(float        ,  2, __vector __bool int  , ::boost::simd::vmx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::int32_t ,  2, __vector __bool int  , ::boost::simd::vmx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::uint32_t,  2, __vector __bool int  , ::boost::simd::vmx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::int16_t ,  2, __vector __bool short, ::boost::simd::vmx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::uint16_t,  2, __vector __bool short, ::boost::simd::vmx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::int8_t  ,  2, __vector __bool char , ::boost::simd::vmx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::uint8_t ,  2, __vector __bool char , ::boost::simd::vmx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(char         ,  2, __vector __bool char , ::boost::simd::vmx_)

  BOOST_SIMD_ENABLE_PACK_SUPPORT(float        ,  1, __vector __bool int  , ::boost::simd::vmx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::int32_t ,  1, __vector __bool int  , ::boost::simd::vmx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::uint32_t,  1, __vector __bool int  , ::boost::simd::vmx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::int16_t ,  1, __vector __bool short, ::boost::simd::vmx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::uint16_t,  1, __vector __bool short, ::boost::simd::vmx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::int8_t  ,  1, __vector __bool char , ::boost::simd::vmx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(std::uint8_t ,  1, __vector __bool char , ::boost::simd::vmx_)
  BOOST_SIMD_ENABLE_PACK_SUPPORT(char         ,  1, __vector __bool char , ::boost::simd::vmx_)
} }

#endif
