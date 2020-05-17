/**
  @file Word.h
  @author João Marinho
  @author Rodrigo Andrade
  Contains declaration of class Word
*/

#ifndef WORD_H
#define WORD_H
#include <iostream>
#include <fstream>

using namespace std;

class Word
{
	string name;
	string position;
	char direction;

public:
	/**
	  @brief Constructor
	*/
	Word();
	/**
	  @brief Reads a class Word from the istream in
	  @param in istream to read the board from
	  @param Word word to be read
	*/
	friend istream& operator>>(istream& in, Word& word);
	/**
      @brief Gets member variable name
      @return name (member variable)
    */
	string get_name() const { return name; };
	/**
      @brief Gets member variable direction
      @return direction (member variable)
    */
	char get_direction() const { return direction; };
	/**
      @brief Gets member variable position
      @return position (member variable)
    */
	string get_position() const { return position; };

};

#endif

