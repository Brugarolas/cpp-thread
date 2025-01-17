//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// Copyright (C) 2011 Vicente J. Botet Escriba
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

// <future>

// class shared_future<R>

// shared_future& shared_future=(shared_future&& rhs);

#define BOOST_THREAD_VERSION 3

#include <boost/thread/future.hpp>
#include <boost/core/lightweight_test.hpp>

boost::mutex m0;
boost::mutex m1;

int main()
{
  {
      typedef int T;
      boost::promise<T> p;
      boost::shared_future<T> f0 = BOOST_THREAD_MAKE_RV_REF(p.get_future());
      boost::shared_future<T> f;
      f = boost::move(f0);
      BOOST_TEST(!f0.valid());
      BOOST_TEST(f.valid());
  }
  {
      typedef int T;
      boost::shared_future<T> f0;
      boost::shared_future<T> f;
      f = boost::move(f0);
      BOOST_TEST(!f0.valid());
      BOOST_TEST(!f.valid());
  }
  {
      typedef int& T;
      boost::promise<T> p;
      boost::shared_future<T> f0 = BOOST_THREAD_MAKE_RV_REF(p.get_future());
      boost::shared_future<T> f;
      f = boost::move(f0);
      BOOST_TEST(!f0.valid());
      BOOST_TEST(f.valid());
  }
  {
      typedef int& T;
      boost::shared_future<T> f0;
      boost::shared_future<T> f;
      f = boost::move(f0);
      BOOST_TEST(!f0.valid());
      BOOST_TEST(!f.valid());
  }
  {
      typedef void T;
      boost::promise<T> p;
      boost::shared_future<T> f0 = BOOST_THREAD_MAKE_RV_REF(p.get_future());
      boost::shared_future<T> f;
      f = boost::move(f0);
      BOOST_TEST(!f0.valid());
      BOOST_TEST(f.valid());
  }
  {
      typedef void T;
      boost::shared_future<T> f0;
      boost::shared_future<T> f;
      f = boost::move(f0);
      BOOST_TEST(!f0.valid());
      BOOST_TEST(!f.valid());
  }


  return boost::report_errors();

}

