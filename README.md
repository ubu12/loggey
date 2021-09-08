# loggey (INDEV)[![CodeFactor](https://www.codefactor.io/repository/github/spedzay/loggey/badge)](https://www.codefactor.io/repository/github/spedzay/loggey)
A cross platform C++17 single-header console logging library

## How to use?
you can compile using cmake to build the example,
but you could easily just use g++ or another compiler from the command line
and build loggey.hpp and loggey.cpp

Loggey.hpp is the code for all of loggey
and loggey.cpp is a demo application.

## How to use Loggey
To log something basic you will need to create a loggey::logType
here's some syntax for that:
`
logType ALERT = { colors::red,
	"Alert", logTypeFlags::addPlus };
`
This will define a logType called ALERT thats prefix is "Alert" and is red.
We also add [+] in front of it using the flag logTypeFlags::addPlus

Now lets log some text!
In our main() function or wherever you want:
`
log(ALERT, "Loggey, the single header C++17 logging library");
`
This will Log `[+] Alert: Loggey, the single header C++17 logging library`

You may also change colors for text defaults in the loggey.hpp file (will change how you can modify colors and settings)
find the loggey_settings namespace and change any of the fields to your liking!
Lets make the text color magenta by default:
Normally its:
`textColor = loggey::colors::white`
But we'll change it to:
`textColor = loggey::colors::magenta`
Now everytime we log something the text will be magenta.
We can also change colors on the fly:
`	
loggey_settings::textColor = colors::magenta;
log(ALERT, "Loggey, the single header C++17 logging library");
loggey_settings::textColor = colors::white;
log(ALERT, "Loggey is written by Spedzay");
`
This will change the color from magenta to white on the fly!
Im planning on adding a single use color change down the road so you dont have to manually reset stuff.

You can also edit fields from logType's on the fly:
`
ALERT.prefix = "Info";
`
Thats about it for Loggey right now, more features are planned!



