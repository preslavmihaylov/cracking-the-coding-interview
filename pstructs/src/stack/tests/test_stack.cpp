#include <cppunit/TestResultCollector.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <stack.h>
#include <iostream>

class StackTest : public CppUnit::TestFixture {
CPPUNIT_TEST_SUITE(StackTest);

CPPUNIT_TEST(test_addingOneElement);
CPPUNIT_TEST(test_addingTwoElements);
CPPUNIT_TEST(test_growingStack);
CPPUNIT_TEST(test_poppingOneElement);
CPPUNIT_TEST_EXCEPTION(test_poppingEmptyStack, std::invalid_argument);
CPPUNIT_TEST_EXCEPTION(test_peekingEmptyStack, std::invalid_argument);

CPPUNIT_TEST_SUITE_END();

pstructs::stack<int> *st;

public:
    void setUp()
    {
        st = new pstructs::stack<int>();
    }

    void tearDown()
    {
        delete st;
    }

    void test_addingOneElement()
    {
        st->push(5);
        CPPUNIT_ASSERT(st->getSize() == 1);
        CPPUNIT_ASSERT(st->peek() == 5);
    }

    void test_addingTwoElements()
    {
        st->push(5);
        CPPUNIT_ASSERT(st->getSize() == 1);
        CPPUNIT_ASSERT(st->peek() == 5);

        st->push(10);
        CPPUNIT_ASSERT(st->getSize() == 2);
        CPPUNIT_ASSERT(st->peek() == 10);
    }

    void test_growingStack()
    {
        int nums[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        int len = sizeof(nums) / sizeof(nums[0]);

        for (int i = 0; i < len; i++)
        {
            st->push(nums[i]);
            CPPUNIT_ASSERT(st->getSize() == i + 1);
            CPPUNIT_ASSERT(st->peek() == nums[i]);
        }

        for (int i = len - 1; i >= 0; i--)
        {
            int element = st->pop();
            CPPUNIT_ASSERT(st->getSize() == i);
            CPPUNIT_ASSERT(element == nums[i]);
        }
    }

    void test_poppingOneElement()
    {
        st->push(5);
        CPPUNIT_ASSERT(st->getSize() == 1);
        CPPUNIT_ASSERT(st->peek() == 5);

        int element = st->pop();
        CPPUNIT_ASSERT(st->getSize() == 0);
        CPPUNIT_ASSERT(element == 5);
    }

    void test_poppingEmptyStack()
    {
        CPPUNIT_ASSERT(st->getSize() == 0);
        st->pop(); 
    }

    void test_peekingEmptyStack()
    {
        CPPUNIT_ASSERT(st->getSize() == 0);
        st->peek();
    }
};

int main(int argc, const char* argv[])
{
    CppUnit::TextUi::TestRunner runner;

    runner.addTest(StackTest::suite());
    runner.run();

    return runner.result().testFailures();
}
