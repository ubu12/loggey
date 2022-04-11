// Loggey example.
// written by: Spedzay

#include "../include/Loggey.hpp"

using namespace std;
using namespace loggey;


LogType MESSAGE = { colors::orange,
	"Init", LogTypeFlags::add_prefix_encasing };
    
LogType LOG = { colors::light_blue,
	"LOG", LogTypeFlags::add_time };

int main() {
    loggey_settings::text_color = colors::magenta;
    
    log(MESSAGE, "-- Loggey, the single header C++17 logging library --");
													
    loggey_settings::text_color = colors::white;
    
    log(LOG, "Loggey is written by Spedzay");
    log(LOG, "Any contributions are welcome!");
    log(LOG, "Loggey is indev as of right now");

    cin.get();
    return 0;
}
