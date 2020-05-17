#include "menus.h"
#include "Game.h"
#include "utilities.h"

#include <iostream>
#include <string>
#include <fstream>


using namespace std;
/*
This function gets information from the board file into the class Board
*/
void read_board() {
	Game* game = Game::getinstance();//gets intance of class Game
	ifstream file_board; //players file
	string filename_board; //name of the file with the players
	bool errormessage = false; //if true it will display an error message

	do {
		if (errormessage) {
			cout << "\n\nThe path you introduced is not valid." << endl;
		}
		errormessage = true;
		cout << "Introduce the path of the file with the board (or press l if you want to leave): ";
		cin.clear();
		getline(cin, filename_board); //read file name
		if ((filename_board.size() == 1) && (filename_board[0] == 'l')) {
			game->set_leaveprogram(true);
		}
		else {
			file_board.open(filename_board); //open file 
		}
	} while (file_board.fail() && !game->get_leaveprogram());

	if (!game->get_leaveprogram()) { //read from file and treat input
		game->get_board()->read_board(file_board);
		game->get_board()->create_tiles();
		game->get_board()->add_words();
	}
	system("CLS");
}

/*
This function gets information from the number of players that will play the game
*/
void read_players() {
	Game* game = Game::getinstance(); //gets intance of class Game
	bool errormessage = false;  //if true it will display an error message
	string no_players; //number of players(string)
	int players_int; //number of players (int)

	do {
		if (errormessage) {
			cout << "\n\nThe number you introduced is not valid." << endl;
		}
		errormessage = true;

		cout << "Introduce the number of players, between 2 and 4 (or press l if you want to leave): ";
		cin.clear();
		getline(cin,no_players); //get user's input
		if ((no_players.size() == 1) && (no_players[0] == 'l')) {
			game->set_leaveprogram(true);
		}

		players_int = convint(no_players); //convert string to int

	} while (!game->get_leaveprogram() && !game->valid_number_players(players_int));

	if (!game->get_leaveprogram()) { //treat input
		game->set_numberplayers(players_int);
		game->create_players();
	}

	system("CLS");

}

/*
This function reads the letter chosen by the player to be played
*/
void read_letter() {
	Game* game = Game::getinstance(); //gets intance of class Game
	int errormessage = 0;  //if true it will display an error message
	string letter; //letter fro playing player's hand
	do {
		switch (errormessage) { //error messages 
		case 1: cout << "\n\nYou do not have that letter." << endl;
			break;
		case 2: cout << "\n\nThat letter is not playable. " << endl;
			break;
		case 3: cout << "\n\nThe letter you introduced is not valid." << endl;
			break;
		}
		cout << "Which letter do you want to play? : ";
		getline(cin, letter); //get input from user
		letter = remove_spaces(letter);

		if (letter.size() != 1) {
			errormessage = 3;
		}
		else {
			errormessage = game->valid_letter(letter[0]); //get error message
		}

	} while (errormessage != 0);

	game->get_player()->take_chosenletter(letter[0]); //treat input
}

/*
This function reads the position chosen by the player to be played
*/
void read_position() {
	Game* game = Game::getinstance(); //gets intance of class Game
	int errormessage = 0;  //if different than 0 it will display an error message
	string position;
	do {
		switch (errormessage) { //print error messages
		case 1: cout << "\n\nThat position is not available in the board" << endl;
			break;
		case 2: cout << "\n\nThe letter in that position does not match the letter you have chosen" << endl;
			break;
		case 3: cout << "\n\nThat tile is not yet unlocked" << endl;
			break;
		case 4: cout << "\n\nInvalid input" << endl;
			break;
		}

		cout << "In which position would you like to place it?: ";
		getline(cin, position); //read from user input
		position = remove_spaces(position);

		if (position.size() != 2) {
			errormessage = 4;
		}
		else {
			errormessage = game->valid_tile(position); //get error message
		}

	} while (errormessage != 0);

	game->get_player()->set_position(position); //treat input
}

/*
This function indicates who is playing
*/
void player_message() {
	Game* game = Game::getinstance(); //gets intance of class Game
	cout << "Player " << game->get_turn() + 1; //prints who is playing
	cout << " (" << game->get_player()->get_points() << " points)"; //prints player's points
	cout << " it's your turn... " << endl;
}

/*
This function appears if the player can't play
It reads the letter that the plyer wants to send back to the pool
*/
void cant_play() {
	Game* game = Game::getinstance(); //gets intance of class Game
	bool errormessage = false; //if true will display an error message
	string letter; //letter chosen by the user
	cout << "You can't play this round" << endl;
	do {
		if (errormessage) {
			cout << "\n\nThe letter you introduced is not valid." << endl;
		}
		cout << "Which letter do you want to send back to the pool? : ";
		getline(cin, letter);
		letter = remove_spaces(letter);

	} while (!(letter.size() == 1 && game->get_player()->valid_letter(letter[0])));

	game->get_player()->take_chosenletter(letter[0]); //removes the chosen lettter from the player's hand
	game->get_board()->addtopool(letter[0]); //adds the letter back to the pool
	system("CLS"); //clears screen
}

/*
 This function performs half of 
*/
void half_move() {
	Game* game = Game::getinstance(); //gets intance of class Game
	read_letter(); //reads a letter from the user
	read_position(); //reads a position from the user
	game->play(); //performs the move
	system("CLS"); //clears screen
}

/*
 This function shows the board, who is playing and the player's hand
*/
void iniciate_screen() {
	Game* game = Game::getinstance(); //gets intance of class Game
	game->get_board()->show_board(); //prints the board
	player_message(); //indicates who is playing
	game->get_player()->show_hand(); //prints the player's tiles
}

/*
 Aggregates above functions and plays the game
*/
void main_game() {
	Game* game = Game::getinstance(); //gets intance of class Game
	while (!game->get_board()->gameover()) { // while de game isn't over
		iniciate_screen(); //print board and playing player's hand
		if (game->can_play()) {
			half_move();
			if (game->can_play()) {
				iniciate_screen();
				half_move();
				game->give_playerletter();
				game->give_playerletter();
			}
			else {
				game->give_playerletter();
			}
		}
		else {
			cant_play();
			iniciate_screen();
			cant_play();
			game->give_playerletter();
			game->give_playerletter();
		}

		game->change_player();
		system("CLS");
	}
	game->show_results();
}