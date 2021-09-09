// Loggey example.
// written by: Spedzay

#include "../include/Loggey.hpp"

using namespace std;
using namespace loggey;

logType MESSAGE = { colors::orange,
	"LOG", logTypeFlags::addPrefixEncasing };


int main() {
    MESSAGE.prefix = "Init";
    loggey_settings::textColor = colors::magenta;

    log(MESSAGE, "Loggey, the single header C++17 logging library");

    MESSAGE.color = colors::light_blue;
    loggey_settings::textColor = colors::white;
    
    MESSAGE.flags = logTypeFlags::addPlus;
    MESSAGE.prefix = "LOG";

    log(MESSAGE, "Loggey is written by Spedzay");
    log(MESSAGE, "Any contributions are welcome!");
    log(MESSAGE, "Loggey is indev as of right now.");

    std::cin.get();
    return 0;
}
