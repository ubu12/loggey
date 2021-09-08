// Loggey example.
// written by: Spedzay

#include "Loggey.hpp"

using namespace std;
using namespace loggey;

logType MESSAGE = { colors::light_blue,
	"LOG", logTypeFlags::addEncasing };


int main() {
    MESSAGE.prefix = "Init";
    MESSAGE.flags = logTypeFlags::addPrefixEncasing;
    loggey_settings::textColor = colors::magenta;

    log(MESSAGE, "Loggey, the single header C++17 logging library");

    loggey_settings::textColor = colors::white;
    MESSAGE.flags = logTypeFlags::addPlus;
    MESSAGE.prefix = "LOG";

    log(MESSAGE, "Loggey is written by Spedzay");
    log(MESSAGE, "Any contributions are welcome!");
    log(MESSAGE, "Loggey is indev as of right now.");

    std::cin.get();
    return 0;
}
