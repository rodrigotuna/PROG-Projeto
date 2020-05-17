#include "Word.h"


/*
 *Constructor
 */
Word::Word() {
    direction = ' ';
}

/*
 *Overload of opertator >>
 *reads a class Word from a istream
 *parameter in istream to read from
 *parameter word Word to be read
 *retrun in istream
 */ 
istream& operator>>(istream& in, Word& word) {
	in >> word.position;
	in >> word.direction;
	in >> word.name;
	return in;
}

