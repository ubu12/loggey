// Loggey example.
// Originally written by: Spedzay
// Updated for fast_io and C++23 by stali
// Refactored for optimized Loggey

#include "../include/Loggey.hpp"

int main()
{
    using namespace loggey;

    // Define log types
    constexpr LogType MESSAGE{colors::orange, "Init", static_cast<uint8_t>(LogTypeFlags::addPrefixEncasing)};
    constexpr LogType LOG{colors::light_blue, "LOG", static_cast<uint8_t>(LogTypeFlags::addTime)};

    // Configure settings
    settings.textColor = colors::magenta;
    
    log(MESSAGE, "-- Loggey, the single header C++23 logging library with fast_io --");

    // Change text color for subsequent logs
    settings.textColor = colors::white;
    
    // Log messages
    log(LOG, "Loggey is written by Spedzay");
    log(LOG, "Any contributions are welcome!");
    log(LOG, "Loggey has been updated to use fast_io and C++23 features");

    // Prompt user to exit
    fast_io::io::println("Press Enter to exit...");

    return 0;
}