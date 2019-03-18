#include "Board.h"

string Board::place_piece(string player, vector<vector<string>>& arr, int col)
{
	if (col >= 0 && col < 7) {
		int i;
		if (isFull(col)) return "full";
		for (i = 5; i >= 0; i--) {
			if (arr[i][col] == "_"&& player == player1) {
				arr[i][col] = player1;
				lastmovex = i;
				lastmovey = col;
				cout << "player 1 drop a piece in column " << lastmovey << endl;
				break;

			}
			else if (arr[i][col] == "_" && player == player2) {
				arr[i][col] = player2;
				lastmovex = i;
				lastmovey = col;
				cout << "player 2 drop a piece in column " << lastmovey << endl;
				break;

			}

		}

		return arr[i][col];
	}

}

bool Board::check_diagonal_SW_NE(int row, int col, string player, vector<vector<string>> board_output)
{
	int score = 1;
	int count = 1;
	

	//vector<vector<string>> board_output = b.getboard();
	while ((col - count >= 0) && (row + count < 6)) {
		if (board_output[col - count][row + count] == player) // Check NE to SW
		{
			score++;
			count++;
		}
		else break; // break from the loop if stuck
	}
	count = 1;
	while ((col + count < 5) && (row - count >= 0)) {
		if (board_output[col + count][row - count] == player) // Check SW to NE
		{
			score++;
			count++;
		}
		else break;
	}
	if (score == 4 && player == "R") {
		cout << "player 1 win" << endl;
		player1score++;
		cout << "Score is: " << player1score << endl;
		return true;
	}
	if (score == 4 && player == "Y") {
		cout << "player 2 win" << endl;
		player2score++;
		cout << "Score is: " << player2score << endl;
		return true;
	}
	else return false;
}

bool Board::check_diagonal_NW_SE(int row, int col, string player, vector<vector<string>> board_output)
{
	int score = 1;
	int count = 1;
	
	while ((col + count >= 0) && (row + count < 6)) {
		if (board_output[col - count][row + count] == player) // check NW to SE
		{
			score++;
			count++;
		}
		else break;
	}
	count = 1;
	while ((col - count < 5) && (row - count >= 0)) {
		if (board_output[col - count][row - count] == player) { // Check SE to NW
			score++;
			count++;
		}
		else break; // If stuck break
	}
	if (score == 4 && player == "R") {
		cout << "player 1 win" << endl;
		player1score++;
		cout << "Score is: " << player1score << endl;
		return true;
	}
	if (score == 4 && player == "Y") {
		cout << "player 2 win" << endl;
		player2score++;
		cout << "Score is: " << player2score << endl;
		return true;
	}
	else return false;
}

bool Board::check_vertical(int row, int col, string player, vector<vector<string>> board_output)
{
	int score = 1;
	int count = 1;

	

	while (row + count < 6) {
		if (board_output[row + count][col] == player) // Check Down
		{
			score++;
			count++;
		}
		else break; // If stuck break
	}
	if (score == 4 && player == "R") {
		cout << "player 1 win" << endl;
		player1score++;
		cout << "Score is: " << player1score << endl;
		return true;
	}
	else if (score == 4 && player == "Y") {
		cout << "player 2 win" << endl;
		player2score++;
		cout << "Score is: "<<player2score << endl;
		return true;
	}
	else return false;
}

bool Board::check_horizontal(int row, int col, string player, vector<vector<string>> board_output)
{
	int score = 1;
	int count = 1;

	
	vector<string> v = board_output[row];
	while (col - count >= 0)
	{
		if (v[col - count] == player)  //Check Left
		{
			score++;
			count++;
		}
		else break;  //If no combo is detected break from the loop
	}

	count = 1;
	while (col + count < 7)
	{
		if (v[col + count] == player)  //Check Right
		{
			score++;
			count++;
		}
		else break;  //If no combo is detected break from the loop
	}
	if (score == 4 && player == "R") {
		cout << "player 1 win" << endl;
		player1score++;
		cout << "Score is: " << player1score << endl;
		return true;
	}
	if (score == 4 && player == "Y") {
		cout << "player 2 win" << endl;
		player2score++;
		cout << "Score is: " << player2score << endl;
		return true;
	}
	else return false;
}

void Board::ClearBoard()
{
	Position p;
	board.resize(p.get_row(), vector<string>(p.get_col()));
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 7; j++) {
			board[i][j] = "_";

		}
	}

}

vector<Position> Board::getEmptyPosition()
{
	int size = this->board.size(); 
	vector<Position> emptyPositions;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (board[i][j] == "_")
				emptyPositions.push_back(Position(i,j));
		}
	}
	return emptyPositions;
}



bool Board::isFull(int col)
{
	bool full = true;

	for (int i = 0; i < col; i++) {
		if (board[0][i] == "_") {
			full = false;
		}
	}
	return full;
}

bool Board::RandomGame(vector<vector<string>>b, string player)
{
	
	while (1) {
		if (place_piece(player, b, rand() % 7) == player1) {
			player = player1;
		}
		else if (place_piece(player, b, rand() % 7) == player2) {
			player = player2;
		}
		bool winner = check_for_winner(lastmovex, lastmovey, player, b);

		if (winner != isFull(lastmovey)) { // this condition need to be recheck
			return winner;
		}
	}
}

int Board::SuggestMove(vector<vector<string>> b, string player)
{
	int best = -1;
	
	double best_ratio = 0;
	int games_per_move = 10000;
	for (int i = 0; i < 7; i++) {
		if (!isValidMove(b, i)) continue; // no valid move found
		double won = 0, lost = 0;
		for (int j = 0; j < games_per_move; j++) {
			
			place_piece(player, b, i);

			// if this is a winning move there is nothing to search, return it

			if (check_for_winner(lastmovex, lastmovey, player, b)) {
				return i;
			}
			string next = (player == player2) ? player1 : player2;
			bool winner = RandomGame(b, next);
			if (winner) {
				if (player == player1 || player == player2) {
					won++;
				}
				else {
					lost++;
				}
			}

		}
		double ratio = won / (lost + 1);
		cout << "Move " + i << endl;
		cout << "Ratio: %f"<< ratio << endl;
		if (ratio > best_ratio || best == -1) {
			best = i;
			best_ratio = ratio;
		}
	}
	return best;
}


/*
Board::Board(vector<vector<string>> b)
{
	board.resize(6, vector<string>(7));
	board = b;
}*/
