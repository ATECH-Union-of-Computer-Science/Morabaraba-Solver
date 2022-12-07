#include <array>

class Morabaraba {
	private:
	array<array<char, 7>, 7> board;
	bool turn;
	char winner;
	public:
	Morabaraba() {
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[0].size(); j++) {
				board[i][j] = 0;
			}
		}
		turn = false;
		winner = 0;
	}
	char getWinner();
	bool isOver();
	bool validPlacement(int x, int y);
	void place(int x, int y);
	bool validMovement(int originalX, int originalY, int finalX, int finalY);
	void move(int originalX, int originalY, int finalX, int finalY)
	void print();
	bool getTurn();
}

Morabaraba::getWinner() {
	return winner;
}

