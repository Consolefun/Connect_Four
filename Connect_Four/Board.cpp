#include "Board.h"

bool Board::place_piece(string player, vector<vector<string>>& arr, int col)
{
	bool result = false;
	
	int i;

	for (i = board.size() - 1; i >= 0; --i) {
		if (arr[i][col] == "_"&& player == player1) {
			arr[i][col] = player1;
			lastmovey = col;
			lastmovex = i;
			cout << "player 1 drop a piece in column " << lastmovey << endl;
			return true;

		}
		else if (arr[i][col] == "_" && player == player2) {
			arr[i][col] = player2;
			lastmovey = col;
			lastmovex = i;
			cout << "player 2 drop a piece in column " << lastmovey << endl;
			return true;

		}

	}
	if (isFull(col)) {
		printf(" This column is full ");
		cout << endl;
		return false;
	}

	return result;
	

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

	
	vector<vector<string>> v = board_output;
	while (col - count >= 0)
	{
		if (v[row][col - count] == player)  //Check Left
		{
			score++;
			count++;
		}
		else break;  //If no combo is detected break from the loop
	}

	count = 1;
	while (col + count < 7)
	{
		if (v[row][col + count] == player)  //Check Right
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

vector<vector<string>> Board::FillBoard()
{
	//board.resize(row);
	board.resize(row, vector<string>(col));
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			board[i][j] = "_";
		}
		
	}
	
	return board;
}



bool Board::isFull(int col)
{

	if (board[0][col] != "_") {
		return false;
	}
	else {
		return true;
	}
		
	
	
}


