// Copyright (C) 2013 Vicente J. Botet Escriba
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

// <boost/thread/synchronized_value.hpp>

// class synchronized_value<T,M>

// synchronized_value();

#define BOOST_THREAD_VERSION 4

#include <boost/thread/synchronized_value.hpp>

#include <boost/core/lightweight_test.hpp>

int main()
{

  {
      boost::synchronized_value<int, boost::mutex > f;
  }
  {
      boost::synchronized_value<int, boost::timed_mutex> f;
  }

  return boost::report_errors();
}

