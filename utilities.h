/**
  @file utilities.h
  @author João Marinho
  @author Rodrigo Andrade
  Contains utility functions
*/

#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
#include <string>

using namespace std;

#define BLACK 0 
#define BLUE 1 
#define GREEN 2 
#define CYAN 3 
#define RED 4
#define MAGENTA 5 
#define BROWN 6
#define LIGHTGRAY 7
#define DARKGRAY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14
#define WHITE 15

/**
  @brief Changes the text color
  @param color int to be changed to 
*/
void setcolor(unsigned int color);
/**
  @brief Changes a position in string into number
  @param s String that indicates the position
  @return index of the first coordinate
*/
int first_coordinate(string& s);
/**
  @brief Changes a position in string into number
  @param s String that indicates the position
  @return index of the second coordinate
*/
int second_coordinate(string& s);
/**
  @brief Checks if given string is an Integer
  @param s String to be checked
  @return True if string only contains numbers
  @details From http://stackoverflow.com/questions/2844817/how-do-i-check-if-a-c-string-is-an-int
*/
bool isInteger(const string& s);
/**
  @brief Converts an integer into a String
  @param s String to be converted
  @return Integer that was in string
*/
int convint(string& s);
/**
  @brief Eliminates extra spaces in string
  @param s String to have spaces removed
  @return String without extra spaces
  @details It removes all spaces in the beggining and in the end, if there are spaces between the characteres
  @details they are removed
*/
string remove_spaces(string& s);


#endif
