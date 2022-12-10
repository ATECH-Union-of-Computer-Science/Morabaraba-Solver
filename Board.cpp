#include <array>

using namespace std;

const char NR = -2; //Represents that a position on the 2D array does not exist on the board. (Not Real)
const char NC = -1; //Represents that a position on the board does not have a cow on it. (No Cow)
const char P1 = 0; //Represents that a position on the board has Player 1's cow on it.
const char P2 = 1; //Represents that a position on the board has Player 2's cow on it.

class Morabaraba {
	private:
	array<array<char, 7>, 7> board;
	bool turn;
	bool over;
	char winner;
	char cows[2];
	bool millCheck(const int& x, const int& y);
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
	bool place(const int& x, const int& y); //Actually place a cow. Returns true if placement creates a mill.
	bool validMovement(const int& originalX, const int& originalY, const int& finalX, const int& finalY); //Check if a move is valid, returns true if it is.
	bool move(const int& originalX, const int& originalY, const int& finalX, const int& finalY); //Actually move a cow from (originalX, originalY) to (finalX, finalY). Returns true if movement creates a mill.
	void print();
	
}

char Morabaraba::getWinner() {
	return winner;
}

bool Morabaraba::getTurn() {
	return turn;
}

bool Morabaraba:isOver() {
	return over;
}

bool validPlacement(const int& x, const int& y) {
	if (x < board.size() && x >= 0 && y < board[0].size() && y >= 0) return board[x][y] == NC;
	return false;
}

bool place(const int& x, const int& y) {
	board[x][y] = turn;
	cows[turn]++;
	if (millCheck(x, y)) {
		
	}
	turn = !turn;
}

bool validMovement(const int& originalX, const int& originalY, const int& finalX, const int& finalY) {
	if (finalX < board.size() && finalX >= 0 && finalY < board[0].size() && finalY >= 0) {
		int diff = (abs(originalX - finalX) + abs(originalY - finalY));
		if (diff <= 2 && diff > 0) return board[finalX][finalY] == NC;
	}
	return false;
}
