#include "Board.h"
#include "utilities.h"

#include <algorithm>

/*
 *Constructor
 */
Board::Board() {
	rows = 0;
	columns = 0;
}

/*
 *Prints the board
 */
void Board::show_board() const {
	cout << " ";
	for (int i = 0; i < columns; i++) {
		setcolor(159); cout << char('a'+ i);
		cout << " ";
	}

	for (int i = 0; i < rows; i++) {
		setcolor(15); cout << '\n';
		setcolor(159); cout << char(i + 'A');
		for (int j = 0; j < columns; j++) {
			if (tiles[i][j].empty()) {
				setcolor(15);
			}
			else {
				if (tiles[i][j].get_state()) setcolor(241); else setcolor(244);
			}
			cout << tiles[i][j].get_letter();
			cout << " ";
		}
	}
	setcolor(15); cout << '\n';
}

/*
 *Reads board file
 *parameter: in - file where the board information is written
 */
void Board::read_board(istream& in) {
	size_t rows;
	in >> rows;
	set_rows(rows);

	char X;
	in >> X;

	size_t columns;
	in >> columns;
	set_columns(columns);

	while (!in.eof()) {
		Word word;
		in >> word;
		words.push_back(word);
	}
}

/*
 *Creates the tiles array with the correct size
 */
void Board::create_tiles() {
	for (int i = 0; i < rows; i++) {
		vector <Tile> v;
		for (int j = 0; j < columns; j++) {
			Tile tile;
			v.push_back(tile);
		}
		tiles.push_back(v);
	}
}

/*
 *Puts the letters in the correct place
 */
void Board::add_words() {
	for (size_t i = 0; i < words.size() ; i++) {
		string name = words[i].get_name();
		string position = words[i].get_position();
		int x = first_coordinate(position);
		int y = second_coordinate(position);

			if (words[i].get_direction() == 'H') {
				for (size_t j = 0; j < name.size(); j++) {
					if (tiles[x][y + j].empty()) {
						tiles[x][y + j].set_letter(name[j]);
						pool.push_back(name[j]);
					}
			    }
		    }
			if (words[i].get_direction() == 'V') {
				for (size_t j = 0; j < name.size(); j++) {
					if (tiles[x + j][y].empty()) {
						tiles[x + j][y].set_letter(name[j]);
						pool.push_back(name[j]);
					}
				}
			}

			if (!tiles[x][y].get_available()) {
				tiles[x][y].set_available(true);
				playable_letters.insert(name[0]);
			}
	}

}

/*
 *Checks wether a charcter can be played
 *parameter: c- character to be tested
 *Returns true if it can be played
 */
bool Board::valid_letter(char c) const {
	return playable_letters.count(c);
}

/*
 *Checks wether pair of coordinates exists in the board
 *parameter: x - first coordinate
 *parameter: y - second coordinate
 *Returna true if (x,y) does not exist in the board
 */
bool Board::outofbounds(int x, int y) const {
	return x < 0 || x >= rows&& y < 0 && y >= columns;
}

/*
 *Checks wether the char c is not in coordinates (x,y)
 *parameter: x - first coordinate
 *parameter: y - second coordinate
 *parameter: c - character to be checked
 *Returns true if the char c and the char in (x,y) do not match
 */
bool Board::different_letter(int x, int y, char c) const {
	return tiles[x][y].get_letter() != c;
}

/*
 *Checks wether the tile in position(x,y) can be played
 *parameter: x - first coordinate
 *parameter: y - second coordinate
 *Returns true if it can't be played
 */
bool Board::unavailable_tile(int x, int y) const {
	return !tiles[x][y].get_available();
}

/*
 *Marks tile (x,y) as playble and adds it to the set
 *parameter: x - first coordinate
 *parameter: y - second coordinate
 */
void Board::add(int x, int y) {
	char c = tiles[x][y].get_letter();
	playable_letters.insert(c);
	tiles[x][y].set_available(true);
}

/*
 *Marks tile (x,y) as played and removes it to the set
 *parameter: x - first coordinate
 *parameter: y - second coordinate
 */
void Board::take(int x, int y) {
	char c = tiles[x][y].get_letter();
	playable_letters.erase(playable_letters.find(c));
	tiles[x][y].set_available(false);
	tiles[x][y].set_state(true);
}

/*
 *Checks wether the tile next to (x,y) has been played
 *parameter: x - first coordinate
 *parameter: y - second coordinate
 *parameter: direction - true(vertical)/false(horizntal)
 *returns true if it has been played
 */
bool Board::nexttile_played(int x, int y, bool direction) {
	if (direction) {
		if (x == rows - 1) return false; else x++;
	}
	else {
		if (y == columns - 1) return false; else y++;
	}

	return tiles[x][y].get_state();
}

/*
 *Checks wether the tile next to (x,y) has not been played and not been set as available
 *parameter: x - first coordinate
 *parameter: y - second coordinate
 *parameter: direction - true(vertical)/false(horizntal)
 *returns true if it has not been played and set as available
 */
bool Board::nexttile_unplayed(int x, int y, bool direction) {
	if (direction) {
		if (x == rows - 1) return false; else x++;
	}
	else {
		if (y == columns - 1) return false; else y++;
	}

	return !tiles[x][y].get_state() && !tiles[x][y].empty() && !tiles[x][y].get_available();
}

/*
 *Checks wether the tile next to (x,y) is empty or does not exist
 *parameter: x - first coordinate
 *parameter: y - second coordinate
 *parameter: direction - true(vertical)/false(horizntal)
 *returns true if it is empty or does not exist
 */
bool Board::nexttile_empty(int x, int y, bool direction) {
	if (direction) {
		if (x == rows - 1) return true; else x++;
	}
	else {
		if (y == columns - 1) return true; else y++;
	}

	return tiles[x][y].empty();
}

/*
 *Checks wether the tile previous to (x,y) has been played
 *parameter: x - first coordinate
 *parameter: y - second coordinate
 *parameter: direction - true(vertical)/false(horizntal)
 *returns true if it has not been played and set as available
 */
bool Board::prevtile_played(int x, int y, bool direction) {
	if (direction) {
		if (x == 0) return false; else x--;
	}
	else {
		if (y == 0) return false; else y--;
	}

	return tiles[x][y].get_state();
}

/*
 *Checks wether the tile next to (x,y) is empty or does not exist
 *parameter: x - first coordinate
 *parameter: y - second coordinate
 *parameter: direction - true(vertical)/false(horizntal)
 *returns true if it is empty or does not exist
 */
bool Board::prevtile_empty(int x, int y, bool direction) {
	if (direction) {
		if (x == 0) return true; else x--;
	}
	else {
		if (y == 0) return true; else y--;
	}

	return tiles[x][y].empty();
}

/*
 *Calculates how many points playing (x,y) makes and makes the changes to the board in one direction
 *parameter: x - first coordinate
 *parameter: y - second coordinate
 *parameter: direction - true(vertical)/false(horizntal)
 *returns number of points for playing (x,y) in one direction
 */
int Board::get_points1D(int x, int y, bool direction) {
	if (nexttile_played(x, y, direction)) {
		if (direction) {
			if (nexttile_empty(x + 1, y, direction)) {
				return 1;
			}
			if (nexttile_unplayed(x + 1, y, direction)) {
				add(x + 2, y);
			}
		}
		else {
			if (nexttile_empty(x, y + 1 , direction)) {
				return 1;
			}
			if (nexttile_unplayed(x, y + 1, direction)) {
				add(x, y + 2);
			}
		}
	}

	if (nexttile_empty(x, y, direction)) {
		if (prevtile_played(x, y, direction)) {
			return 1;
		}
	}

	if (nexttile_unplayed(x,y,direction)) {
		if (prevtile_played(x, y, direction) || prevtile_empty(x, y, direction)) {
			if (direction) add(x + 1, y); else add(x, y + 1);
		}
	}

	return 0;
}

/*
 *Calculates how many points playing (x,y) gains and makes the changes to the board
 *parameter: x - first coordinate
 *parameter: y - second coordinate
 *returns number of points for playing (x,y)
 */
int Board::get_points(int x, int y) {
	int pointsV = get_points1D(x, y, true);
	int pointsH = get_points1D(x, y, false);
	take(x, y);
	return pointsV + pointsH;
}

/*
 *Takes a char from the pool
 *returns a char that has been removed from the pool
 *returns ' ' if empty
 */
char Board::takefrompool() {
	if (pool.empty())
		return ' ';
	random_shuffle(pool.begin(), pool.end());
	char c = pool.back();
	pool.pop_back();
	return c;
}

/*
 *Takes a char from the pool
 *returns a char that has been removed from the pool
 */
void Board::addtopool(char c) {
	pool.push_back(c);
}

/*
 *Checks wether the game is over
 *returns true if all tiles have been played
 */
bool Board::gameover() const{
	return playable_letters.empty();
}
