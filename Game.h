/**
  @file Game.h
  @author João Marinho
  @author Rodrigo Andrade
  Contains declaration of class Game
*/

#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Board.h"

#include <iostream>

using namespace std;

class Game {
    const int MAXPLAYERS = 4;
    const int MINPLAYERS = 2;
    int numberplayers;
    int turn;
	vector <Player*> players;
	Board* board;
    bool leaveprogram;
	static Game* singleton_instance;
    /**
    @brief Default constructor, private to prevent multiple object of this class
  */
    Game();

public:
    /**
      @brief Destructor
    */
    ~Game();
    /**
      @brief Gets an object of class Game
      @return singleton_instance (member variable)
      @details Checks whether member variable singleton_instance already points to an object, if it does
      @details return it, if not then it initializes singleton_instance then returns it
    */
    static Game* getinstance();
    /**
      @brief Gets member variable leaveprogram
      @return leaveprogram (member variable)
    */
    bool get_leaveprogram() const { return leaveprogram; };
    /**
      @brief Change value of member variable setleaveprogram
    */
    void set_leaveprogram(bool leaveprogram) { this->leaveprogram = leaveprogram; }
    /**
      @brief Gets member variable board
      @return board (member variable)
    */
    Board* get_board() const { return board; };
    /**
      @brief Checks if a number is a legal number of players
      @param num int a number
      @return true if it is legal
    */
    bool valid_number_players(int num);
    /**
      @brief Change value of member variable numberplayers
    */
    void set_numberplayers(int numberplayers) { this->numberplayers = numberplayers; }
    /**
      @brief Gets member variable numberplayers
      @return numberplayers (member variable)
    */
    int get_numberplayers() const { return numberplayers; };
    /**
      @brief Gets member variable player
      @return player (member variable)
      @details returns the player that is at the moment playing
    */
    Player* get_player() const { return players[turn]; };
    /**
      @brief Gets member variable turn
      @return turn (member variable)
    */
    int get_turn() const { return turn; };
    /**
      @brief Creates the players
    */
    void create_players(); 
    /**
      @brief Checks wether the player can play
      @return true if can play
    */
    bool can_play();
    /**
      @brief Checks if a letter is valid
      @param c char to be checked
      @return true if valid
    */
    int valid_letter(char c);
    /**
      @brief Checks if a letter is valid
      @return true if valid
    */
    int valid_tile(string& pos) const; 
    /**
      @brief Makes a play
    */
    void play();
    /**
     @brief Gives a player a letter
    */
    void give_playerletter();
    /**
     @brief Goes to next player
    */
    void change_player();
    /**
     @brief Print final results
    */
    void show_results() const;

};

#endif