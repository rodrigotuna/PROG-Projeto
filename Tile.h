/**
  @file Tile.h
  @author João Marinho
  @author Rodrigo Andrade
  Contains declaration of class Tile
*/

#ifndef TILE_H
#define TILE_H
class Tile
{
	char letter;
	bool state;
	bool available;
public:
	/**
	  @brief Constructor
	*/
	Tile();
	/**
   @brief Gets member variable available
   @return available (member variable)
   */
	bool get_available() const { return available; };
	/**
	  @brief Gets member variable state
	  @return state (member variable)
	*/
	bool get_state() const { return state; };
	/**
	  @brief Gets member variable letter
	  @return letter (member variable)
	*/
	char get_letter() const { return letter; };
	/**
	  @brief Change value of member variable state
	*/
	void set_state(bool state) { this->state = state; };
	/**
	  @brief Change value of member variable letter
	*/
	void set_letter(char letter) { this->letter = letter; };
	/**
	  @brief Change value of member variable available
	*/
	void set_available(bool available) { this->available = available; };
	/**
	  @brief Checks if tile is empty
	  @return true if does not have a letter
	*/
	bool empty() const;
};

#endif