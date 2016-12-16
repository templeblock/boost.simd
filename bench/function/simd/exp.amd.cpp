// -------------------------------------------------------------------------------------------------
//                              Copyright 2016 - NumScale SAS
//
//                   Distributed under the Boost Software License, Version 1.0.
//                        See accompanying file LICENSE.txt or copy at
//                            http://www.boost.org/LICENSE_1_0.txt
// -------------------------------------------------------------------------------------------------
//
// #include <simd_bench.hpp>
// #include <boost/simd/function/simd/exp.hpp>
// #include <boost/simd/pack.hpp>

// namespace nsb = ns::bench;
// namespace bs =  boost::simd;

// DEFINE_SIMD_BENCH(simd_exp, bs::amd_(bs::exp));

// DEFINE_BENCH_MAIN()
// {
//   nsb::for_each<simd_exp, NS_BENCH_IEEE_TYPES>(-10, 10);
// }

#include <boost/simd/pack.hpp>
#include <boost/simd/function/exp.hpp>

#include <iostream>
#include <iomanip>


namespace bs =  boost::simd;

int main()
{
  using pack_t =  bs::pack<float>;
  pack_t z(1.0);
  auto xx = bs::amd_(bs::exp)(z) ;
  std::cout <<"xx " << xx << std::endl;
  return 0;
}
//g++ exp.amd.cpp -O3 -DNDEBUG -o exp_amd -I//home/jt/boost_simd_dev/a_boost_simd/include -I/home/jt/DevC++/boost/boost_1_62_0 -lamdlibm -msse4.2 -std=c++11

