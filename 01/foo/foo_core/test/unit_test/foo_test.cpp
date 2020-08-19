#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE foo_test

#include <boost/test/unit_test.hpp>
namespace utf = boost::unit_test;

#include <foo/bar.h>

BOOST_AUTO_TEST_SUITE( bar_suite )

BOOST_AUTO_TEST_CASE( bar_case )
{
  BOOST_CHECK_EQUAL(bar(2,2), 4);
}

BOOST_AUTO_TEST_SUITE_END()
