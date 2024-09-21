#ifndef LOGGEY_H
#define LOGGEY_H

#include <fast_io.h>
#include <string_view>

#if defined(_WIN32) || defined(_WIN64)
#   define LOGGEY_WIN
#   define WIN32_LEAN_AND_MEAN
#   define VC_EXTRALEAN
#   include <Windows.h>
#elif defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
#   define LOGGEY_UNIX
#endif

namespace loggey {
    namespace colors {
#ifdef LOGGEY_WIN
        enum : uint8_t {
            black = 0, dark_blue = 1, dark_green = 2, light_blue = 3,
            dark_red = 4, magenta = 5, orange = 6, light_gray = 7, gray = 8, blue = 9,
            green = 10, cyan = 11, red = 12, pink = 13, yellow = 14, white = 15
        };
#else
        enum : uint8_t {
            black = 30, dark_blue = 34, dark_green = 32, light_blue = 36,
            dark_red = 31, magenta = 35, orange = 33, light_gray = 37, gray = 90, blue = 94,
            green = 92, cyan = 96, red = 91, pink = 95, yellow = 93, white = 97
        };
#endif
    }

    struct Settings {
        uint8_t flagPlusColor = colors::pink;
        uint8_t flagBracketsColor = colors::light_gray;
        uint8_t flagTimeColor = colors::gray;
        bool timeUTC = true;
        uint8_t textColor = colors::white;
        uint8_t prefixColor = colors::red;
    };

    inline Settings settings;

    enum class LogTypeFlags : uint8_t {
        addPlus = 0x01,
        addPrefixEncasing = 0x02,
        addTime = 0x04
    };

    inline void setConsoleColor(uint8_t color) {
#ifdef LOGGEY_WIN
        static const HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(handle, colors::black << 4 | color);
#else
        fast_io::io::print("\033[", color, "m");
#endif
    }

    class LogType {
    public:
        uint8_t color = settings.prefixColor;
        std::string_view prefix;
        uint8_t flags = 0;

        constexpr LogType(uint8_t prefixColor, std::string_view prefixText, uint8_t logFlag) 
            : color(prefixColor), prefix(prefixText), flags(logFlag) {}
        constexpr LogType(uint8_t prefixColor, std::string_view prefixText) 
            : color(prefixColor), prefix(prefixText) {}
        constexpr LogType(std::string_view prefixText) : prefix(prefixText) {}
        constexpr LogType(std::string_view prefixText, uint8_t logFlag) 
            : prefix(prefixText), flags(logFlag) {}
    };

    template<typename... Args>
    inline void log(const LogType& logtype, Args&&... args) {
        if (logtype.flags & static_cast<uint8_t>(LogTypeFlags::addTime)) {
            fast_io::posix_tzset();
            auto now = fast_io::posix_clock_gettime(fast_io::posix_clock_id::realtime);
            setConsoleColor(settings.flagTimeColor);
            fast_io::io::print(settings.timeUTC ? fast_io::utc(now) : fast_io::local(now), " ");
            fast_io::io::print(fast_io::timezone_name(), " ");
        }

        if (logtype.flags & static_cast<uint8_t>(LogTypeFlags::addPlus)) {
            setConsoleColor(settings.flagBracketsColor);
            fast_io::io::print("[");
            setConsoleColor(settings.flagPlusColor);
            fast_io::io::print("+");
            setConsoleColor(settings.flagBracketsColor);
            fast_io::io::print("] ");
        }

        if (logtype.flags & static_cast<uint8_t>(LogTypeFlags::addPrefixEncasing)) {
            setConsoleColor(settings.flagBracketsColor);
            fast_io::io::print("[");
            setConsoleColor(logtype.color);
            fast_io::io::print(logtype.prefix);
            setConsoleColor(settings.flagBracketsColor);
            fast_io::io::print("] ");
        } else {
            setConsoleColor(logtype.color);
            fast_io::io::print(logtype.prefix, " ");
        }

        setConsoleColor(settings.textColor);
        fast_io::io::println(std::forward<Args>(args)...);
    }
}

#ifndef lg
namespace lg = loggey;
#endif

#endif // LOGGEY_H