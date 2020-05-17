#include "Player.h"
#include "utilities.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

/*
 *Constructor
 */
Player::Player() {
	points = 0;
	chosenletter = ' ';
}

/*
 *Prints player's hand
 */
void Player::show_hand() const {
	for (size_t i = 0; i < hand.size(); i++) {
		setcolor(241); cout << hand[i];
		setcolor(15); cout  << " ";
	}
	cout << endl;
}
/*
 *Check if leter c is in hand
 *parameter c char to be checked
 *return true if it is in hand
 */
bool Player::valid_letter(char c) {
	return find(hand.begin(), hand.end(), c) != hand.end();
}

/*
 *Take letter c for hand
 *parameter c char to be take
 */
void Player::take_chosenletter(char c) {
	hand.erase(lower_bound(hand.begin(), hand.end(), c));
	sort(hand.begin(), hand.end());
	this->chosenletter = c;
}

/*
 *Add letter that came from the pool to the player's hand
 *parameter c char to be added
 */
void Player::add_from_pool(char c) {
	hand.push_back(c);
	sort(hand.begin(), hand.end());
}


