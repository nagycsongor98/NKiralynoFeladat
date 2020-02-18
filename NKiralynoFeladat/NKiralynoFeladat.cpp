#include <iostream>

using namespace std;

void printBoard(int** board, int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

bool goodPosition(int** board, int n, int row, int col)
{
	int i, j;
	for (i = 0; i < col; i++)
		if (board[row][i])
			return false;

	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (board[i][j])
			return false;

	for (i = row, j = col; j >= 0 && i < n; i++, j--)
		if (board[i][j])
			return false;

	return true;
}

bool placingTheQueens(int** board, int n, int col)
{
	if (col >= n) {
		return true;
	}

	for (int i = 0; i < n; i++) {
		if (goodPosition(board, n, i, col)) {
			board[i][col] = 1;

			if (placingTheQueens(board, n, col + 1)) {
				return true;
			}

			board[i][col] = 0;
		}
	}
	return false;
}
int main()
{
	int n;
	cout << "Size of the tabla: ";
	cin >> n;
	cout << endl;
	int** board;
	board = new int* [n];
	for (int i = 0; i < n; i++) {
		board[i] = new int[n];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			board[i][j] = 0;
		}
	}


	if (!placingTheQueens(board, n, 0)) {
		printf("Solution don't exist");
	}
	else {
		printBoard(board, n);
	}
	return 0;
}

