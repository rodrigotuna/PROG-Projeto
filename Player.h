/**
  @file Player.h
  @author João Marinho
  @author Rodrigo Andrade
  Contains declaration of class Player
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>

using namespace std;

class Player
{
	const size_t MAXLETTERS = 7;
	vector <char> hand;
	char chosenletter;
	string position;
	int points;
public:
	Player();
	/**
      @brief Gets member variable chosenletter
      @return chosenletter (member variable)
    */
	char get_chosenletter() const { return chosenletter; };
	/**
	  @brief Gets member variable position
	  @return position (member variable)
	*/
	string get_position() const { return position; };
	/**
	  @brief Change value of member variable position
	*/
	void set_position(string& position) { this->position = position; };
	/**
	  @brief Gets member variable hand
	  @return hand (member variable)
	*/
	vector <char> get_hand() const { return hand; };
	/**
	  @brief Gets member variable chosenletter
	  @return chosenletter (member variable)
	*/
	int get_points() const { return points; };
	/**
	  @brief Prints the letters in the player's hand
	*/
	void show_hand() const;
	/**
	  @brief Checks if the player has the letter c in the hand
	  @param c char to be checked
	  @return true if c is in hand
	*/
	bool valid_letter(char c);
	/**
	  @brief Remove letter c
	  @param c char to be taken
	*/
	void take_chosenletter(char c);
	/**
	  @brief Checks if the player has the letter c in the hand
	  @param c char to be added
	*/
	void add_from_pool(char c);
	/**
	  @brief Adds a number to member value points
	  @param n number to be added
	*/
	void add_points(int n) { this->points += n; };
	
};

#endif

