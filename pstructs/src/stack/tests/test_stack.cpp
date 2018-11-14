#include <cppunit/ui/text/TestRunner.h>

int main( int argc, char **argv)
{
    CppUnit::TextUi::TestRunner runner;
    runner.run();
    return 0;
}
