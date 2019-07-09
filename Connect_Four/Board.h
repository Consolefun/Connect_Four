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
		int row = 6;
		int col = 7;
		int lastmovex = 0;
		int lastmovey = 0;
		double player1score = 0;
		double player2score = 0;
		double drawscore = 0.5;
		
	public:

		Board() {};
		//Constructor
		Board(int row1, int col1) {
			row = row1;
			col = col1;

		}
		int get_row() { return row; }
		int get_col() { return col; }
		int get_lastmovex() { return lastmovex; }
		int get_lastmovey() { return lastmovey; }
		// Drop down the pieces base on player's color
		bool place_piece(string player, vector<vector<string>>&arr, int col);
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
		vector<vector<string>> FillBoard();
		
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

		
		// Copy the source board to destination
		void c4Copy(Board dst, Board src) {
			dst.getboard() = src.getboard();
		};
		bool isFull(int col); // check if the column is full

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
