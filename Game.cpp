#include "Game.h"
#include "utilities.h"

#include <string>
#include <algorithm>

using namespace std;

Game* Game::singleton_instance = NULL; //Initially singleton_instance points to null

/*
 * Private Default Constructor
 */
Game::Game(){
	numberplayers = 0;
	turn = 0;
	leaveprogram = false;
	board = new Board();
}

/*
 *Destructor
 */
Game::~Game() {
	delete board;
	for (int i = 0; i < numberplayers; i++) {
		delete players[i];
	}
	delete singleton_instance;
	singleton_instance = NULL;
}

/*
 Gets instance of Club Class
 */
Game* Game::getinstance() {
	if (!singleton_instance) {
		singleton_instance = new Game;
	}
	return singleton_instance;
}

/*
 *Checks if a given number of players is valid
 *parameter: num - number of players
 *returns true if it is valid 
 */
bool Game::valid_number_players(int num) {
	return (num >= MINPLAYERS && num <= MAXPLAYERS);
}

/*
 Creates the vector players with pointers to a class Player
 */
void Game::create_players() {
	for (int i = 0; i < numberplayers; i++) {
		Player *player = new Player; //initalizes a pointer to a class Player
		players.push_back(player); 
		for (int j = 0; j < 7; j++) {
			char c = board->takefrompool(); //takes a letter from the pool
			players[i]->add_from_pool(c); //adds the letter to the players hand
		}
	}
}

/*
 *Checks the player that is playing can play
 *returns true if it is valid
 */
bool Game::can_play() {
	vector<char> hand = players[turn]->get_hand();
	for (size_t i = 0; i < hand.size(); i++) {
		if (board->valid_letter(hand[i])) { 
			return true;
		}
	}
	return false;
}

/*
 *Checks if char can be played
 *parameter: c char to be checked
 *returns 0 if valid or a different number depending on the mistake
 */
int Game::valid_letter(char c) {
	if (!players[turn]->valid_letter(c))
		return 1;
	if (!board->valid_letter(c))
		return 2;
	return 0;
}

/*
 *Checks if position s can be played
 *parameter: s string with the position
 *returns 0 if valid or a different number depending on the mistake
 */
int Game::valid_tile(string& pos) const {
	int x = first_coordinate(pos);
	int y = second_coordinate(pos);
	char c = players[turn]->get_chosenletter();
	if (board->outofbounds(x, y)) {
		return 1;
	}
	if (board->different_letter(x, y, c)) {
		return 2;
	}
	if (board->unavailable_tile(x, y)) {
		return 3;
	}

	return 0;
}

/*
 *Makes play 
 */
void Game::play() {
	string pos = players[turn]->get_position();
	int x = first_coordinate(pos);
	int y = second_coordinate(pos);
	int points = board->get_points(x,y);
	players[turn]->add_points(points);
}

/*
 *Gives the player a letter from the pool
 *If the pool is empty the player won't recieve anything
 */
void Game::give_playerletter() {
	char c = board->takefrompool();
	if (c == ' ')
		return;
	players[turn]->add_from_pool(c);
}

/*
 *Changes member variable turn to next player
 */
void Game::change_player() {
	turn++;
	turn %= numberplayers;
}

/*
 *Prints results
 */
void Game::show_results() const {
	int maxpoints = 0;
	vector <int> winners;
	for (int i = 0; i < numberplayers; i++) {
		cout << "Player " << i + 1 << "     " << players[i]->get_points() << " points." << endl;

		if (players[i]->get_points() > maxpoints) {
			winners.clear();
			winners.push_back(i + 1);
			maxpoints = players[i]->get_points();
		}

		if (players[i]->get_points() == maxpoints) {
			winners.push_back(i + 1);
		}

	}
	cout << "The winner is:";
	for (size_t i = 0; i < winners.size(); i++) {
		cout << " Player " << winners[i];
	}
}

