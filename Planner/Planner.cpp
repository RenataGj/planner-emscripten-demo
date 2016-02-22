// Planner.cpp : Defines the entry point for the console application.
//
#include "headers.h"
#include <emscripten.h>


// extern "C" int main(int argc)
// {
// 	std::printf("Hello world");
// 	return 0;
// }

// extern "C" int sum(int x, int y)
// {
// 	printf("Sum invoked\n");
// 	return x + y;
// }

#include <emscripten/bind.h>
using namespace emscripten;

class Example
{
public:
	Example(int number, std::string text)
		: m_number(number)
		, m_text(text)
	{};

	int getNumber() const { return m_number; }
	void setNumber(int val) { m_number = val; }

	std::string getText() const { return m_text; }
	void setText(std::string val) { m_text = val; }

	int squareNumber() 
	{
		int num = 10;
		num += m_number;
		num *= 15;

		return num; 
	}

	static std::string greeting() { return "Hello all from static method"; }

	static void justCallJavaScript()
	{
		int x = EM_ASM_INT({
			Module.print('I received: ' + $0);
			return $0 + 5;
		}, 100);
		
		printf("JavaScript called, now result is %d \n", x);
	}

private:
	int m_number;
	std::string m_text;
};

// Binding code
EMSCRIPTEN_BINDINGS(planner) {
	class_<Example>("Example")
		.constructor<int, std::string>()
		.function("squareNumber", &Example::squareNumber)
		.class_function("greeting", &Example::greeting)
		.class_function("justCallJavaScript", &Example::justCallJavaScript)
		.property("m_number", &Example::getNumber, &Example::setNumber)
		.property("m_text", &Example::getText, &Example::setText)
		;
}

