//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/frexp.hpp>
#include <boost/simd/function/tofloat.hpp>
#include <boost/simd/detail/constant/minexponent.hpp>
#include <boost/simd/constant/halfeps.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/pack.hpp>
#include <utility>

#include <simd_test.hpp>

namespace bs = boost::simd;
namespace bd = boost::dispatch;

template <typename T, std::size_t N, typename Env>
void test(Env& $)
{
  using p_T  = bs::pack< T, N>;

  T a1[N], m[N];
  T e[N];

  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(1+i) : -T(1+i);
    std::tie(m[i], e[i])   = bs::frexp(a1[i]);
  }

  p_T  in(&a1[0], &a1[0]+N);
  p_T  mm( &m[0],  &m[0]+N);
  p_T  ee( &e[0],  &e[0]+N);

  auto that = bs::frexp(in);

  STF_EQUAL(that.first, mm);
  STF_EQUAL(that.second, ee);
}

STF_CASE_TPL("Check basic behavior of frexp on pack" , STF_IEEE_TYPES)
{
  static const std::size_t N = bs::pack<T>::static_size;
  test<T, N>($);
  test<T, N/2>($);
  test<T, N*2>($);
}

STF_CASE_TPL("Check behavior of pedantic_(frexp) on Zero", STF_IEEE_TYPES)
{
  auto r = bs::frexp(bs::pack<T>(0));

  STF_EQUAL (r.first , bs::pack<T>(0));
  STF_EQUAL (r.second, bs::pack<T>(0));
}

STF_CASE_TPL("Check behavior of pedantic_(frexp) on Valmax", STF_IEEE_TYPES)
{
  auto r = bs::frexp(bs::Valmax<bs::pack<T>>());

  STF_ULP_EQUAL (r.first , 1-bs::Halfeps<bs::pack<T>>(), 1);
  STF_EQUAL (r.second, bs::tofloat(bs::Limitexponent<bs::pack<T>>()));
}
