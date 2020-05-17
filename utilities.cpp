#include "utilities.h"

#include <ctime>
#include <cstdlib>
#include <windows.h>

/*
 *Changes the text and the background color of the console
 *parameter color - color to be changed
 */
void setcolor(unsigned int color)
{
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hcon, color);
}

/*
 *Transforms a string that indicates a position into the first coordinate
 *parameter s string that has the position
 *return The corresponding index
 */
int first_coordinate(string& s) {
	return s[0] - 'A';
}

/*
 *Transforms a string that indicates a position into the second coordinate
 *parameter s string that has the position
 *return The corresponding index
 */
int second_coordinate(string& s) {
	return s[1] - 'a';
}


/*
This functions checks if a string is an integer
parameter: const string &s-The function will check if this string is an integer
return value- true if string is an integer and false if not
source:http://stackoverflow.com/questions/2844817/how-do-i-check-if-a-c-string-is-an-int
*/
bool isInteger(const string& s)
{
	if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

	char* p;
	strtol(s.c_str(), &p, 10);

	return (*p == 0);
}


/*
This function converts a string to an integer and returns -1 if string is not an integer
parameter: string s-string that is going to be converted
return value - integer that corresponds to the string
*/
int convint(string& s) {
	if (!isInteger(s)) {
		return -1;
	}
	else {
		return stoi(s);
	}
}

/*
This functions eliminates extra spaces between characters, so that if there is at least one space in
the string, this function returns a string with no spaces. It also eliminates extra
spaces at the beginning and at the end of a string
parameter: string s - string that will have paces eliminated from
return value: string s without spaces
*/
string remove_spaces(string& s) {
	size_t i = 0;
	while (i < s.size()) {
		if (s[i] == ' ') {
			s.erase(i, 1);
		}
		else {
			i++;
		}
	}
	return s;
}

