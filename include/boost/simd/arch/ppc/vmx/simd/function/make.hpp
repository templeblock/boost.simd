//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_PPC_VMX_SIMD_FUNCTION_MAKE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_PPC_VMX_SIMD_FUNCTION_MAKE_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/meta/is_power_of_2.hpp>
#include <boost/simd/detail/brigand.hpp>
#include <boost/simd/detail/nope.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;

  BOOST_DISPATCH_OVERLOAD ( make_
                          , (typename Target, typename... Values)
                          , bs::vmx_
                          , bd::target_<bs::pack_<bd::arithmetic_<Target>,bs::vmx_>>
                          , bd::scalar_<bd::unspecified_<Values>>...
                          )
  {
    using target_t  = typename Target::type;
    using v_t       = typename target_t::value_type;

    static_assert (     (sizeof...(Values) <= target_t::static_size)
                    &&  (is_power_of_2_<sizeof...(Values)>::value  )
                  , "boost::simd::make - Invalid number of parameters"
                  );

    BOOST_FORCEINLINE target_t operator()(Target const&, Values const&... vs) const BOOST_NOEXCEPT
    {
      return do_( brigand::range<int,sizeof...(Values), (16/sizeof(v_t))>{}, vs...);
    }

    template<typename... Z> BOOST_FORCEINLINE
    static target_t do_(brigand::list<Z...> const&, Values const&... vs) BOOST_NOEXCEPT
    {
      using s_t = typename target_t::storage_type;

      s_t that = { static_cast<v_t>(vs)..., detail::nope<v_t,Z>()... };
      return that;
    }
  };
} } }

#endif
