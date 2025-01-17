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

// <boost/thread/recursive_mutex.hpp>

// class recursive_timed_mutex;

// recursive_timed_mutex(const recursive_timed_mutex&) = delete;

#include <boost/thread/recursive_mutex.hpp>
#include <boost/core/lightweight_test.hpp>

int main()
{
  boost::recursive_timed_mutex m0;
  boost::recursive_timed_mutex m1(m0);
}

#include "../../../remove_error_code_unused_warning.hpp"

