// Loggey example.
// written by: Spedzay

#include "../include/Loggey.hpp"

using namespace std;
using namespace loggey;

logType MESSAGE = { colors::orange,
	"Init", logTypeFlags::addPrefixEncasing };
    
logType TIME = { colors::light_blue,
	"LOG", logTypeFlags::addTime };


int main() {
    loggey_settings::textColor = colors::magenta;

    log(MESSAGE, "Loggey, the single header C++17 logging library");

    loggey_settings::textColor = colors::white;
    
    log(TIME, "Loggey is written by Spedzay");
    log(TIME, "Any contributions are welcome!");
    log(TIME, "Loggey is indev as of right now.");

    std::cin.get();
    return 0;
}
