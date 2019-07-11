#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include<random>
#include "Board.h"

// Connect four resources
//https://cs.nyu.edu/courses/fall16/CSCI-UA.0101-009/notes/Lecture12.pdf

using namespace std;

Board b(6, 7);
void showgameboard(vector<vector<string>> board);
string switchplayer(string currentplayer);
int main() {

	string player = "R";
	int col;
	string user1_input;
	string user2_input;
	b.FillBoard();
	
	vector<vector<string>> board_output = b.getboard();
	
	// Place moves between 2 players 

	// call check for winner
	//b.check_for_winner(b.get_lastmovex(), b.get_lastmovey(), p_2, board_output);
	//b.check_for_winner(b.get_lastmovex(), b.get_lastmovey(), p_1, board_output);

	while (true) {
		showgameboard(board_output);
		std::cout << "Player " + player + ", enter the column where you'd like to drop your piece: " << endl;
		cin >> col;
		if (b.place_piece(player, board_output, col)) {
			if (b.check_for_winner(b.get_lastmovex(), b.get_lastmovey(), player, board_output)) {
				cout << "player " + player + " Wins!" << endl;
				//showgameboard(board_output);
				break;
			}
			
			player = switchplayer(player);
		}
	}

	system("pause");
	return 0;
}

void showgameboard(vector<vector<string>> board) {
	for (int i = 0; i < b.getboard().size(); i++) {
		for (int j = 0; j < b.getboard()[i].size(); j++) {
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


