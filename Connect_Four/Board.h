#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include<random>
#include"Position.h"
#include"State.h"

using namespace std;

class Board {
	private:
		// variables
		vector<vector<string>>board;
		string player1 = "R";
		string player2 = "Y";
		double player1score = 0;
		double player2score = 0;
		double drawscore = 0.5;
		
	public:

		int lastmovex = 0, lastmovey = 0; // Last move that being stored whenever a piece placed
		int row = 6, col = 7;
		Board() {};
		//Constructor
		Board(int row1, int col1) {
			row = row1;
			col = col1;

		}
		void setboard(vector<vector<string>>board1) {
			Position p;
			board[p.get_row()][p.get_col()] = board1[p.get_row()][p.get_col()];
		}
		// Drop down the pieces base on player's color
		string place_piece(string player, vector<vector<string>>&arr, int col);
		// Check for winner in all directions
		bool check_for_winner(int row, int col, string player, vector<vector<string>>board_output) {

			if (check_diagonal_SW_NE(row, col, player, board_output)) return true;
			else if (check_diagonal_NW_SE(row, col, player, board_output)) return true;
			else if (check_vertical(row, col, player, board_output)) return true;
			else if (check_horizontal(row, col, player, board_output)) return true;
			else return false;
		}
		bool check_diagonal_SW_NE(int row, int col, string player, vector<vector<string>>board_output);
		bool check_diagonal_NW_SE(int row, int col, string player, vector<vector<string>>board_output);
		bool check_vertical(int row, int col, string player, vector<vector<string>>board_output);
		bool check_horizontal(int row, int col, string player, vector<vector<string>>board_output);
		// get the board
		vector<vector<string>> getboard() { return board; }
		// fill the board with "_"
		void ClearBoard();
		// check for coloumns that are not full
		bool isValidMove(vector<vector<string>>board_output, int col) {
			Position p;

			if (board_output[0][col] == "_")
			{
				cout << "this move is valid" << endl;
				return true;
			}
			else {
				cout << "this move is not valid" << endl;

				return false;
			}
		}

		vector<Position> getEmptyPosition();
		// Copy the source board to destination
		void c4Copy(Board dst, Board src) {
			dst.getboard() = src.getboard();
		};
		bool isFull(int col); // check if the column is full
		// Ai will be placed at random column
		bool RandomGame(vector<vector<string>> b, string player);
		// Suggest moves that best for AI best on ratio
		int SuggestMove(vector<vector<string>> b, string player);

		//Checkc if any of the players win then game over or the board is full then end in a draw
		bool gameIsOver(int row, int col) { // Check for winner
		
			bool gameOver = false;
			if (isFull(col)) {
				gameOver = true;
			}
			else if (check_for_winner(row,col,player1,board) || check_for_winner(row, col, player2, board)) {
				gameOver = true;
			}
			return gameOver;
			
		}
		


};
