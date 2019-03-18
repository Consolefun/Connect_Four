#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include<random>
#include "Board.h"


using namespace std;

Board b;
int main() {
	
	string p_1 = "R";
	string p_2 = "Y";
	
	b.ClearBoard();
	
	vector<vector<string>> board_output = b.getboard();
	// Place moves between 2 players 
	b.place_piece(p_2, board_output, 0);

	b.place_piece(p_2, board_output, 3);
	b.place_piece(p_1, board_output, 3);
	b.place_piece(p_2, board_output, 3);
	b.place_piece(p_1, board_output, 4);
	b.place_piece(p_2, board_output, 4);
	b.place_piece(p_2, board_output, 5);
	b.place_piece(p_1, board_output, 2);
	b.place_piece(p_1, board_output, 2);
	b.place_piece(p_1, board_output, 2);
	b.place_piece(p_1, board_output, 2);

	/*
	b.RandomGame(board_output, b.place_piece(p_1, board_output, 2));
	b.RandomGame(board_output, b.place_piece(p_2, board_output, 3));
	b.RandomGame(board_output, b.place_piece(p_2, board_output, 4));
	b.RandomGame(board_output, b.place_piece(p_1, board_output, 5));
	b.RandomGame(board_output, b.place_piece(p_1, board_output, 3));*/
	b.isValidMove(board_output,2);
	
	// call check for winner
	b.check_for_winner(b.lastmovex, b.lastmovey, p_2, board_output);
	b.check_for_winner(b.lastmovex, b.lastmovey, p_1, board_output);
	
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 7; j++) {
			
			cout << board_output[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}


