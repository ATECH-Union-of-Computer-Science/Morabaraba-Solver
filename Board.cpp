#include <array>

using namespace std;

/*
TODO:
	Implement millCheck().
	Implement move().
	Implement print().
	Implement validShot().
	Implement shoot().
*/

const char NR = -2; //Represents that a position on the 2D array does not exist on the board. (Not Real)
const char NC = -1; //Represents that a position on the board does not have a cow on it. (No Cow)
const char P1 = 0; //Represents that a position on the board has Player 1's cow on it.
const char P2 = 1; //Represents that a position on the board has Player 2's cow on it.
const char M1 = 2; //Represents a a player 1 cow that is a part of a mill.
const char M2 = 3; //Represents a player 2 cow that is a part of a mill.

class Morabaraba {
	private:
	array<array<char, 7>, 7> board;
	bool turn;
	bool over;
	char winner;
	char cows[2];
	char millCheck(const int& x, const int& y); //Returns how many mills have been created after a movement or placement at a certain position (0 - 2)
	bool inBounds(const int& x, const int& y); //Returns if a position is in the bounds of a board.
	public:
	Morabaraba() {
		board = {{NC, NR, NR, NC, NR, NR, NC},
				 {NR, NC, NR, NC, NR, NC, NR},
				 {NR, NR, NC, NC, NC, NR, NR},
				 {NC, NC, NC, NR, NC, NC, NC},
				 {NR, NR, NC, NC, NC, NR, NR},
				 {NR, NC, NR, NC, NR, NC, NR},
				 {NC, NR, NR, NC, NR, NR, NC}};
		turn = false;
		over = false;
		winner = 0;
		cows[0] = 0;
		cows[1] = 0;
	}
	char getWinner();
	bool getTurn();
	bool isOver();
	bool validPlacement(const int& x, const int& y); //Check if it is valid to place a cow at (x,y).
	bool place(const int& x, const int& y); //Actually place a cow. Returns how many mills were created.
	bool validMovement(const int& originalX, const int& originalY, const int& finalX, const int& finalY); //Check if a move is valid, returns true if it is.
	char move(const int& originalX, const int& originalY, const int& finalX, const int& finalY); //Actually move a cow from (originalX, originalY) to (finalX, finalY). Returns how many mills were created.
	void print();
	bool validShot(const int& x, const int& y); //Return if it is valid to shoot a certain position.
	void shoot(const int& x, const int& y); //Actually shoot the position given.
	
}

char Morabaraba::millCheck(const int& x, const int& y) {
	
}

bool Morabaraba::inBounds(const int& x, const int& y) {
	return x < board.size() && x >= 0 && y < board[0].size() && y >= 0;
}

char Morabaraba::getWinner() {
	return winner;
}

bool Morabaraba::getTurn() {
	return turn;
}

bool Morabaraba::isOver() {
	return over;
}

bool Morabaraba::validPlacement(const int& x, const int& y) {
	if (inBounds(x, y)) return board[x][y] == NC;
	return false;
}

char Morabaraba::place(const int& x, const int& y) {
	board[x][y] = turn;
	cows[turn]++;
	turn = !turn;
	return millCheck(x, y);
}

bool Morabaraba::validMovement(const int& originalX, const int& originalY, const int& finalX, const int& finalY) {
	if (inBounds(finalX, finalY)) {
		int diff[1] = abs(originalX - finalX);
		int diff[0] = abs(originalY - finalY)
		int i = 2;
		while (i--) {
			if (diff[i] > 1) return false;
		}
		return board[finalX][finalY] == NC;
	}
	return false;
}

char Morabaraba::move(const int& originalX, const int& originalY, const int& finalX, const int& finalY) {
	
}

void Morabaraba::print() {

}
