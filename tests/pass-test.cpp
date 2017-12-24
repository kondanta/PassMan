#define BOOST_TEST_MODULE addertest
#include <boost/test/included/unit_test.hpp>
#include "pass.hpp"

using namespace std;

struct TestFixture{
    PassGen obj;
    TestFixture()
    : obj()
    {BOOST_TEST_MESSAGE("setup fixture");};
};


BOOST_FIXTURE_TEST_SUITE(TestGet, TestFixture);

 BOOST_AUTO_TEST_CASE(test1)
{   
    BOOST_TEST_MESSAGE("Checking the password methods");
    PassGen obj;
    string pass = "t";
    obj.setPassword(pass);
    BOOST_CHECK_EQUAL (obj.getPassword(), "t");
}

BOOST_AUTO_TEST_SUITE_END();
