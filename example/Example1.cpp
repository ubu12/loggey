// Loggey example.
// written by: Spedzay

#include "../include/Loggey.hpp"

using namespace std;
using namespace loggey;


LogType MESSAGE = { colors::orange,
	"Init", LogTypeFlags::addPrefixEncasing };
    
LogType LOG = { colors::light_blue,
	"LOG", LogTypeFlags::addTime };

int main() {
    loggey_settings::textColor = colors::magenta;
    
    log(MESSAGE, "-- Loggey, the single header C++17 logging library --");
													
    loggey_settings::textColor = colors::white;
    
    log(LOG, "Loggey is written by Spedzay");
    log(LOG, "Any contributions are welcome!");
    log(LOG, "Loggey is indev as of right now");

    cin.get();
    return 0;
}
