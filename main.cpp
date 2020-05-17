#include <iostream>
#include "Game.h"
#include "menus.h"

using namespace std;

int main() {
	Game* game = Game::getinstance();
	read_board();
	if (game->get_leaveprogram()) {
		return 1;
	}
	read_players();
	if (game->get_leaveprogram()) {
		return 1;
	}
	
	main_game();
}