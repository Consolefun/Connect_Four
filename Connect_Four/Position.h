#pragma once
class Position {
	private:
		int row = 6;
		int col = 7;
	public:
		Position() {};
		Position(int x, int y) { row = x; col = y; }
		int get_row() { return row; }
		void set_row(int x) { row = x; }
		int get_col() { return col; }
		void set_col(int y) { col = y; }
};
