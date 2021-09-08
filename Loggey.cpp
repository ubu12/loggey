// Loggey example.
// written by: Spedzay

#include "Loggey.hpp"

#include <iostream>

using namespace std;
using namespace loggey;

logType ALERT = { colors::red,
	"Alert", logTypeFlags::addPlus };

logType WARNING = { colors::orange,
	"Warning", logTypeFlags::addPlus };

logType MESSAGE = { colors::light_blue,
	"LOG", logTypeFlags::addPlus };


int main() {
	WARNING.prefix = "Init";
	WARNING.flags = logTypeFlags::addPrefixEncasing;
	loggey_settings::textColor = colors::magenta;

	log(WARNING, "Loggey, the single header C++17 logging library");

	loggey_settings::textColor = colors::white;
	WARNING.flags = logTypeFlags::addPlus;
	WARNING.prefix = "Warning";

	log(MESSAGE, "Loggey is written by Spedzay");
	log(MESSAGE, "Any contributions are welcome!");
	log(MESSAGE, "Its under MIT License, tho its really bad.");

    std::cin.get();
    return 0;
}
