#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>

class StackTest : public CppUnit::TestFixture {
CPPUNIT_TEST_SUITE(StackTest);
CPPUNIT_TEST(testAddition);
CPPUNIT_TEST_SUITE_END();

public:
    void setUp()
    {
    }

    void tearDown()
    {
    }

    void testAddition()
    {
        CPPUNIT_ASSERT(true);
    }
};

int main( int argc, char **argv)
{
    CppUnit::TextUi::TestRunner runner;

    runner.addTest(StackTest::suite());
    runner.run();

    return 0;
}
