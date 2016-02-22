#include <emscripten/bind.h>

using namespace emscripten;

class Test
{
public:
	Test(int x_);

	void setX(int val);
	int getX() const;

	int incrementX();
	std::string returnString();
private:
	int x;
};
