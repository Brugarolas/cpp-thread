// Copyright (C) 2012 Vicente J. Botet Escriba
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

// <boost/thread/mutex.hpp>

// <mutex>

// template <class Lock>
// class nested_strict_lock
// {
// public:
//     typedef typename Lock::mutex_type mutex_type;
//     ...
// };


#include <boost/thread/lock_types.hpp>
#include <boost/thread/strict_lock.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/core/lightweight_test.hpp>

int main()
{
  BOOST_STATIC_ASSERT_MSG((boost::is_same<boost::nested_strict_lock<boost::unique_lock<boost::mutex> >::mutex_type,
      boost::mutex>::value), "");

  BOOST_STATIC_ASSERT_MSG((boost::is_strict_lock<boost::nested_strict_lock<boost::unique_lock<boost::mutex> > >::value), "");

  return boost::report_errors();
}

