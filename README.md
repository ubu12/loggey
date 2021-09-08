# loggey (INDEV)[![CodeFactor](https://www.codefactor.io/repository/github/spedzay/loggey/badge)](https://www.codefactor.io/repository/github/spedzay/loggey)
A cross platform C++17 single-header console logging library

## How to use?
you can compile using cmake to build the example,
but you could easily just use g++ or another compiler from the command line
and build loggey.hpp and loggey.cpp

Loggey.hpp is the code for all of loggey
and loggey.cpp is a demo application.

## How to use Loggey
To log something basic you will need to create a loggey::logType <br>
here's some syntax for that: <br>
`
logType ALERT = { colors::red,
	"Alert", logTypeFlags::addPlus };
` <br>
This will define a logType called ALERT thats prefix is "Alert" and is red. <br>
We also add [+] in front of it using the flag logTypeFlags::addPlus <br>

Now lets log some text! <br>
In our main() function or wherever you want: <br>
`
log(ALERT, "Loggey, the single header C++17 logging library");
`
<br>
This will Log `[+] Alert: Loggey, the single header C++17 logging library` <br>

You may also change colors for text defaults in the loggey.hpp file (will change how you can modify colors and settings) <br>
find the loggey_settings namespace and change any of the fields to your liking! <br>
Lets make the text color magenta by default: <br>
Normally its: <br>
`textColor = loggey::colors::white` <br>
But we'll change it to: <br>
`textColor = loggey::colors::magenta` <br>
Now everytime we log something the text will be magenta. <br>
We can also change colors on the fly: <br>
`	
loggey_settings::textColor = colors::magenta;
log(ALERT, "Loggey, the single header C++17 logging library");
loggey_settings::textColor = colors::white;
log(ALERT, "Loggey is written by Spedzay");
` <br>
This will change the color from magenta to white on the fly! <br>
Im planning on adding a single use color change down the road so you dont have to manually reset stuff. <br>

You can also edit fields from logType's on the fly: <br>
`
ALERT.prefix = "Info";
` <br>
Thats about it for Loggey right now, more features are planned! <br>



