/**
  @file Board.h
  @author João Marinho
  @author Rodrigo Andrade
  Contains declaration of class Board
*/

#ifndef BOARD_H
#define BOARD_H
#include "Word.h"
#include "Tile.h"


#include <iostream>
#include <vector>
#include <set>


using namespace std;


class Board
{
	int rows;
	int columns;
	vector <vector<Tile>> tiles;
	vector <Word> words;
	multiset<char> playable_letters;
	vector <char> pool;
	/**
	  @brief Adds (x,y) to tiles that can be played
	  @param x index of 1st coordinate
	  @param y index of 2ndt coordinate
	*/
	void add(int x, int y);
	/**
	  @brief Marks (x,y) as played
	  @param x index of 1st coordinate
	  @param y index of 2ndt coordinate
	*/
	void take(int x, int y);
	/**
	  @brief Check if the tile next to (x,y) has been played
	  @param x index of 1st coordinate
	  @param y index of 2ndt coordinate
	  @param direction bool to be checked (true/false) = (V/H)
	  @return true if next tile has been played
	*/
	bool nexttile_played(int x, int y,bool direction);
	/**
	  @brief Check if the tile next to (x,y) is empty
	  @param x index of 1st coordinate
	  @param y index of 2ndt coordinate
	  @param direction bool to be checked (true/false) = (V/H)
	  @return true if next tile is empty
	*/
	bool nexttile_empty(int x, int y, bool direction);
	/**
	  @brief Check if the tile next to (x,y) has not been played
	  @param x index of 1st coordinate
	  @param y index of 2ndt coordinate
	  @param direction bool to be checked (true/false) = (V/H)
	  @return true if next tile has not been played
	*/
	bool nexttile_unplayed(int x, int y, bool direction);
	/**
	  @brief Check if the tile previous to (x,y) has been played
	  @param x index of 1st coordinate
	  @param y index of 2ndt coordinate
	  @param direction bool to be checked (true/false) = (V/H)
	  @return true if previous tile has been played
	*/
	bool prevtile_played(int x, int y, bool direction);
	/**
	  @brief Check if the tile previous to (x,y) is empty
	  @param x index of 1st coordinate
	  @param y index of 2ndt coordinate
	  @param direction bool to be checked (true/false) = (V/H)
	  @return true if previous tile is empty
	*/
	bool prevtile_empty(int x, int y, bool direction);
	/**
	  @brief Calculate points gained by playing
	  @param x index of 1st coordinate
	  @param y index of 2ndt coordinate
	  @param direction bool to be checked (true/false) = (V/H)
	  @return points gained in one direction
	  @details Makes changes to the board
	*/
	int get_points1D(int x, int y, bool direction);

public:
	/**
	  @brief Constructor
	*/
	Board();
	/**
	  @brief Change value of member variable rows
	*/
	void set_rows(size_t rows) { this->rows = rows; };
	/**
	  @brief Change value of member variable columns
	*/
	void set_columns(size_t columns) { this->columns = columns; };
	/**
	  @brief Creates the tiles
	*/
	void create_tiles();
	/**
	  @brief Prints the board
	*/
	void show_board() const;
	/**
	  @brief Change value of member variable columns
	  @param in istream to read the board from
	*/
	void read_board(istream& in);
	/**
	  @brief Adds word to the board
	  @details creates plyable_letters set and the pool 
	*/
	void add_words();
	/**
	  @brief Checks if a char can be played
	  @param c char to be checked
	  @return true if can be played
	*/
	bool valid_letter(char c) const;
	/**
	  @brief Check if coordinate (x,y) exists
	  @param x index of 1st coordinate
	  @param y index of 2ndt coordinate
	  @return true if does not exist
	*/
	bool outofbounds(int x, int y) const;
	/**
	  @brief Check if tile in coordinate (x,y) has the letter c
	  @param x index of 1st coordinate
	  @param y index of 2ndt coordinate
	  @param c char to be checked
	  @return true if does letters do not match
	*/
	bool different_letter(int x, int y, char c) const;
	/**
	  @brief Check if tile in coordinate (x,y) can be played
	  @param x index of 1st coordinate
	  @param y index of 2ndt coordinate
	  @return true if can't be played
	*/
	bool unavailable_tile(int x, int y) const;
	/**
	  @brief Calculates how many points of gained by playing (x,y)
	  @param x index of 1st coordinate
	  @param y index of 2ndt coordinate
	  @return true number of points
	  @details makes adjustments to the board
	*/
	int get_points(int x, int y);/**
	  @brief Takes a char from the pool and removes it
	  @return a char from the pool
	  @details returns ' ' if empty
	*/
	char takefrompool();
	/**
	  @brief Adds char to the pool
	  @param c char to be added
	*/
	void addtopool(char c);
	/**
	  @brief Check if game is over
	  @return true if the game is over
	*/
	bool gameover() const;

};

#endif
