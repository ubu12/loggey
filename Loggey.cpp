// Loggey example.
// written by: Spedzay

#include "Loggey.hpp"
#include <Windows.h>
#include <iostream>
using namespace std;

int main() {
	loggey::logType test = { loggey::colors::red,
		"ALERT", loggey::logTypeFlags::addPlus };
	//
	loggey::log(test, "stalin will suck your dick for");
	test.prefix = "Money";
	test.color = loggey::colors::magenta;
	loggey::loggey_settings::flagBracketsColor = loggey::colors::gray;
	loggey::log(test, "20$");

	std::cin.get();
	return 1;
}