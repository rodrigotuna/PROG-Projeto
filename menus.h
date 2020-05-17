/**
  @file menus.h
  @author João Marinho
  @author Rodrigo Andrade
  Contains i/o menus
*/

#ifndef MENUS_H
#define MENUS_H

/**
  @brief Reads file with board
*/
void read_board();
/**
  @brief Reads the number of players
*/
void read_players();
/**
  @brief indicates who is playing
*/
void player_message();
/**
  @brief Reads letter chosen to be played by user
*/
void read_letter();
/**
  @brief Reads position chosen to be played by user
*/
void read_position();
/**
  @brief Reads letter chosen to be added to the pool
  @details Appears if player can't play
*/
void cant_play();
/**
  @brief Performs one move
*/
void half_move();
/**
  @brief Iniciates screen for one move
*/
void iniciate_screen();
/**
  @brief Reads file with board
*/
void main_game();

#endif





