#include "Test.h"

Test::Test(int x_)
: x(x_)
{
}

void Test::setX(int val)
{
	x = val;
}
int Test::getX() const
{
	return x;
}

int Test::incrementX()
{
	return ++x;
}

std::string Test::returnString()
{
	return "Renata";
}

// Binding code
EMSCRIPTEN_BINDINGS(Test) {
  class_<Test::Test>("Test")
    .constructor<int>()
    .function("incrementX", &Test::incrementX)
	.function("returnString", &Test::returnString)
    .property("x", &Test::getX, &Test::setX)
    ;
}