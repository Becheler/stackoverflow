// Copyright 2016 Arnaud Becheler    <Arnaud.Becheler@egce.cnrs-gif.fr>

/***********************************************************************                                                                         *
* This program is free software; you can redistribute it and/or modify *
* it under the terms of the GNU General Public License as published by *
* the Free Software Foundation; either version 2 of the License, or    *
* (at your option) any later version.                                  *
*                                                                      *
***************************************************************************/
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE coalescence_test

#include <boost/test/unit_test.hpp>
namespace utf = boost::unit_test;

#include <foo/bar.h>

BOOST_AUTO_TEST_SUITE( bar )

BOOST_AUTO_TEST_CASE( bar_case )
{
  BOOST_CHECK_EQUAL(bar(2), 4);
}

BOOST_AUTO_TEST_SUITE_END()
