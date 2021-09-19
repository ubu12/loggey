/*
	 _
	| |   ___  __ _ __ _ _  _
	| |__/ _ \/ _` / _` | || |
	|____\___/\__, \__, |\_, |
	          |___/|___/ |__/

	A cross platform C++17 single-header
	console logging library.

	How do I use Loggey?
 	there is an example application and docs are on the github:
	https://github.com/Spedzay/loggey/

	How do I change default colors?
	If your text editor supports searching, search for inside this file:
	LoggeySettings

	Contact me:
	- mail: admin@ambrosia.club
	- matrix: @spedzay:straya.xyz

	-- Begin MIT License. --

	Copyright (c) 2021 Spedzay

	Permission is hereby granted, free of charge, to any person obtaining
	a copy of this software and associated documentation files (the
	"Software"), to deal in the Software without restriction, including
	without limitation the rights to use, copy, modify, merge, publish,
	distribute, sublicense, and/or sell copies of the Software, and to
	permit persons to whom the Software is furnished to do so, subject to
	the following conditions:

	The above copyright notice and this permission notice shall be
	included in all copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
	EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
	MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
	NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
	LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
	OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
	WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

	-- End MIT License. --

	I do not reccomend using Loggey in its current state, its barley usable.
*/

// - loggey.h header guard
#ifndef LOGGEY_H
#define LOGGEY_H

// - Standard Library Includes
#include <iostream>
#include <string>
#include <ctime>    

// Check if we're on Windows or a Unix based system
#if defined(_WIN32) || defined(_WIN64)
#   define LOGGEY_WIN
#elif defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
#   define LOGGEY_UNIX
#endif

// Operating System Specific #Defines and Includes
// Windows
#ifdef LOGGEY_WIN
// Windows specific includes and defines
#include <Windows.h>
#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#endif

// Unix
#ifdef LOGGEY_UNIX
#endif

namespace loggey {
	// All the colors loggey uses are in this namespace
	// Since the way console colors are handled differently on Unix and Windows we have seperate defines
	namespace colors {
#ifdef LOGGEY_WIN
		// Windows Color Codes
		constexpr uint8_t black = 0;
		constexpr uint8_t dark_blue = 1;
		constexpr uint8_t dark_green = 2;
		constexpr uint8_t light_blue = 3;
		constexpr uint8_t dark_red = 4;
		constexpr uint8_t magenta = 5;
		constexpr uint8_t orange = 6;
		constexpr uint8_t light_gray = 7;
		constexpr uint8_t gray = 8;
		constexpr uint8_t blue = 9;
		constexpr uint8_t green = 10;
		constexpr uint8_t cyan = 11;
		constexpr uint8_t red = 12;
		constexpr uint8_t pink = 13;
		constexpr uint8_t yellow = 14;
		constexpr uint8_t white = 15;
#endif // LOGGEY_WIN
#ifdef LOGGEY_UNIX
		// UNIX Color Codes
		constexpr uint8_t black = 30;
		constexpr uint8_t dark_blue = 34;
		constexpr uint8_t dark_green = 32;
		constexpr uint8_t light_blue = 36;
		constexpr uint8_t dark_red = 31;
		constexpr uint8_t magenta = 35;
		constexpr uint8_t orange = 33;
		constexpr uint8_t light_gray = 37;
		constexpr uint8_t gray = 90;
		constexpr uint8_t blue = 94;
		constexpr uint8_t green = 92;
		constexpr uint8_t cyan = 96;
		constexpr uint8_t red = 91;
		constexpr uint8_t pink = 95;
		constexpr uint8_t yellow = 93;
		constexpr uint8_t white = 97;
#endif // LOGGEY_UNIX
	}

	/*  
		 _                               
		| |   ___  __ _ __ _ _  _        
		| |__/ _ \/ _` / _` | || |       
		|____\___/\__, \__, |\_, |       
		 ___      |___/|___/ |__/        
		/ __| ___| |_| |_(_)_ _  __ _ ___
		\__ \/ -_)  _|  _| | ' \/ _` (_-<
		|___/\___|\__|\__|_|_||_\__, /__/
		                        |___/    
		LoggeySettings

		Change colors for Loggey Functions and Text!

		How do I use this??
		All the editable variables are in the loggey_settings namespace down below
	*/
	namespace loggey_settings {
		// Flags
		static uint8_t flagPlusColor = loggey::colors::pink;
		static uint8_t flagBracketsColor = loggey::colors::light_gray;
		static uint8_t flagTimeColor = loggey::colors::gray;
		static bool timeUTC = false;

		// Generic
		static uint8_t textColor = loggey::colors::white;
		static uint8_t prefixColor = loggey::colors::red;
	}

	// Flags for logType's, What each flag does is documented on the github
	// When creating a logType with multiple flags do it like this:
	// addPlus | addPrefixEncasing | addTime
	// With a | to seperate each logType
	struct logTypeFlags {
		enum Value {
			addPlus = 0x01,
			addPrefixEncasing = 0x02,
			addTime = 0x04
			//SOMETHING_ELSE = 0x10,
			//SOMETHING_COMPLETELY_DIFFERENT = 0x20
		};
	};

	// Set the console color. color codes are in loggey::loggey_settings
	inline void setConsoleColor(uint8_t color)
	{
#ifdef LOGGEY_WIN
		static const HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(handle, colors::black << 4 | color);
#endif // LOGGEY_WIN
#ifdef LOGGEY_UNIX
        const std::string to_print = "\033["+std::to_string(color)+"m";
        std::cout << to_print;
#endif // LOGGEY_UNIX
	}

	
	// logType is a type for defining different logs, heres an example: you want a logType for erros and a logType for warnings,
	// So we define a logType called ERROR and set it to be red and its prefix as "ERROR" and with what flags we want!
	// Now when we call log() and pass in our ERROR logType it will make a red log
	class logType {
	public:
		uint8_t color = loggey_settings::prefixColor;  // Prefix Color
		std::string prefix; // Prefix text aka "PrefixExample: LogText"
		int flags; // Flags aka addPlus will make it "[+] PrefixExample: LogText"

		// ik this is bad but my ass cant figure out how to do it. (constructor overloading :vomit:)  i think this is the best way to do it, c++ 2021 fix when - stalin
		// TODO: ^
		logType(uint8_t prefixColor, std::string prefixText, int logFlag) {
			color = prefixColor;
			prefix = prefixText;
			flags = logFlag;
		}
		logType(uint8_t prefixColor, std::string prefixText) {
			color = prefixColor;
			prefix = prefixText;
		}
		logType(std::string prefixText) {
			prefix = prefixText;
		}
		logType(std::string prefixText, int logFlag) {
			flags = logFlag;
			prefix = prefixText;
		}
	};

	// log output to the console/terminal, this takes in a logType and a string to log
	inline void log(const logType& logtype, const std::string& Text) {
		// If addTime is a flag from logtype we will add the time to the log
		if (logtype.flags & logTypeFlags::addTime) {
			// Current date/time based on current system
			time_t now_seconds = time(0);
    		struct tm *now = gmtime(&now_seconds);
			// Convert now to tm struct for local timezone
			tm* localtm = localtime_r(&now_seconds, now);
			
			setConsoleColor(loggey_settings::flagTimeColor);
			if (loggey_settings::timeUTC) {
				tm* gmtm = gmtime_r(&now_seconds, now);
				if (gmtm != NULL) {
					std::cout << gmtm->tm_hour << ":" << gmtm->tm_min << ":" << gmtm->tm_sec << " ";
				}
				else {
					// if we cant do UTC we 'goto cantUTC'
					goto cantUTC;
				}
			}
			else {
				cantUTC:
				std::cout << localtm->tm_hour << ":" << localtm->tm_min << ":" << localtm->tm_sec << " ";
			}
		}

		// If addPlus is a flag from logtype we will add a [+] to the log.
		if (logtype.flags & logTypeFlags::addPlus) {
			setConsoleColor(loggey_settings::flagBracketsColor);  std::cout << "[";
			setConsoleColor(loggey_settings::flagPlusColor); std::cout << "+";
			setConsoleColor(loggey_settings::flagBracketsColor);  std::cout << "] ";
		}
		// If addPrefix is a flag from logtype we will add [this] around the prefix of the log.
		if (logtype.flags & logTypeFlags::addPrefixEncasing) {
			setConsoleColor(loggey_settings::flagBracketsColor); std::cout << "[";
			setConsoleColor(logtype.color); std::cout << logtype.prefix;
			setConsoleColor(loggey_settings::flagBracketsColor); std::cout << "] ";
		}
		
		// if theres no flags in logtype we will just write the colored prefix like normal.
		else {
			setConsoleColor(logtype.color); std::cout << logtype.prefix << " ";
		}
		setConsoleColor(loggey_settings::textColor); std::cout << Text << std::endl;;
	}

}

// === End loggey namespace === //

// This will let you use lg as the namespace ONLY if its not already defined.
#ifdef lg
#else
namespace lg = loggey;
#endif

// === End loggey.h header guard === //
#endif
