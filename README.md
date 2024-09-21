# Loggey (In Development)

[![CodeFactor](https://www.codefactor.io/repository/github/spedzay/loggey/badge)](https://www.codefactor.io/repository/github/spedzay/loggey)

Loggey is a cross-platform, C++17, single-header console logging library designed for simplicity and flexibility.

## Features

- Single header file for easy integration
- Cross-platform support
- Customizable log types and colors
- Dynamic color and prefix changes

## Installation

Simply include `Loggey.hpp` in your project to start using Loggey.

## Quick Start

Here's a basic example of how to use Loggey:

```cpp
#include "Loggey.hpp"

int main() {
    // Define a log type
    loggey::logType ALERT = {
        loggey::colors::red,
        "Alert",
        loggey::logTypeFlags::addPlus
    };

    // Log a message
    loggey::log(ALERT, "Loggey, the single header C++17 logging library");

    return 0;
}
```

This will output: `[+] Alert: Loggey, the single header C++17 logging library`

## Usage Guide

### Defining Log Types

Create a `logType` to customize your log messages:

```cpp
loggey::logType INFO = {
    loggey::colors::blue,
    "Info",
    loggey::logTypeFlags::addTime
};
```

### Logging Messages

Use the `log` function to output messages:

```cpp
loggey::log(INFO, "This is an informational message");
```

### Customizing Colors

Change text colors globally or for specific messages:

```cpp
// Change global text color
loggey::loggey_settings::textColor = loggey::colors::magenta;

// Log with global color
loggey::log(INFO, "This message will be magenta");

// Change color for a single message
loggey::loggey_settings::textColor = loggey::colors::white;
loggey::log(INFO, "This message will be white");
```

### Modifying Log Types

You can change log type properties on the fly:

```cpp
INFO.prefix = "Debug";
loggey::log(INFO, "This message now has a 'Debug' prefix");
```

## Building the Example

You can build the example using CMake or directly with a C++ compiler:

```bash
# Using CMake
cmake .
make

# Using g++ directly
g++ -std=c++17 loggey.cpp -o loggey_demo
```

## Customization

Edit the `loggey_settings` namespace in `Loggey.hpp` to change default colors and behaviors.

## Planned Features

- Single-use color changes
- Additional customization options
- Extended platform support

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## License

[Insert your chosen license here]

## Author

Loggey is developed by Spedzay/Stali.

---

For more information, bug reports, or feature requests, please visit our [GitHub repository](https://github.com/spedzay/loggey).