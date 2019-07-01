#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include<random>
#include "Board.h"

// Connect four resources
//https://cs.nyu.edu/courses/fall16/CSCI-UA.0101-009/notes/Lecture12.pdf

using namespace std;

Board b;
void showgameboard(vector<vector<string>> board);
int main() {
	
	string p_1 = "R";
	string p_2 = "Y";
	string user1_input;
	string user2_input;
	b.FillBoard();
	
	vector<vector<string>> board_output = b.getboard();
	// Place moves between 2 players 
	b.place_piece(p_2, board_output, 0);

	b.place_piece(p_2, board_output, 3);
	
	
	// call check for winner
	b.check_for_winner(b.get_lastmovex(), b.get_lastmovey(), p_2, board_output);
	//b.check_for_winner(b.get_lastmovex(), b.get_lastmovey(), p_1, board_output);
	while (true) {
		showgameboard(board_output);
		
	}
	
	system("pause");
	return 0;
}

void showgameboard(vector<vector<string>> board) {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 7; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}
string switchplayer(string currentplayer) {
	if (currentplayer == "R") {
		return "Y";
	}
	else {
		return "R";
	}
}


