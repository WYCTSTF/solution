all: a generator std

a:a.cpp
	g++ a.cpp -o a -std=c++17 -Wall -Wextra -fsanitize=

generator:generator.cpp
	g++ generator.cpp -o g -std=c++17

std:std.cpp
	g++ std.cpp -o std -std=c++17 -Wall -Wextra -fsanitize=