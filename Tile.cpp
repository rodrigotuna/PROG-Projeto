#include "Tile.h"

/*
 *Constructor
 */
Tile::Tile() {
	letter = ' ';
	state = 0;
	available = 0;
}

/*
 *Checks if file is empty
 *returns true if it does not have a letter
 */
bool Tile::empty() const {
	return letter == ' ';
}