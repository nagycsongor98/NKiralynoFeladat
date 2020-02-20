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

void forwardChecking(int** forwardCheckingBoard, int* freePosition, int n, int row, int col) {
	int i, j;
	for (i = col; i < n; i++) {
		if (forwardCheckingBoard[row][i] == 0) {
			freePosition[i]--;
		}
		forwardCheckingBoard[row][i]++;
	}

	for (i = row, j = col; i >= 0 && j < n; i--, j++) {
		if (forwardCheckingBoard[i][j] == 0) {
			freePosition[j]--;
		}
		forwardCheckingBoard[i][j]++;
	}

	for (i = row, j = col; i < n && j < n; i++, j++) {
		if (forwardCheckingBoard[i][j] == 0) {
			freePosition[j]--;
		}
		forwardCheckingBoard[i][j]++;
	}
}

void forwardCheckingBack(int** forwardCheckingBoard, int* freePosition, int n, int row, int col) {
	int i, j;
	for (i = col; i < n; i++) {
		forwardCheckingBoard[row][i]--;
		if (forwardCheckingBoard[row][i] == 0) {
			freePosition[i]++;
		}
	}

	for (i = row, j = col; i >= 0 && j < n; i--, j++) {
		forwardCheckingBoard[i][j]--;
		if (forwardCheckingBoard[i][j] == 0) {
			freePosition[j]++;
		}
	}

	for (i = row, j = col; i < n && j < n; i++, j++) {
		forwardCheckingBoard[i][j]--;
		if (forwardCheckingBoard[i][j] == 0) {
			freePosition[j]++;
		}
	}
}

bool placingTheQueensForwardChecking(int** board, int** forwardCheckingBoard, int* freePosition, int n, int col)
{
	if (col >= n) {
		return true;
	}

	for (int i = col; i < n; i++) {
		if (freePosition[i] == 0) {
			return false;
		}
	}

	for (int i = 0; i < n; i++) {
		if (forwardCheckingBoard[i][col] == 0) {
			board[i][col] = 1;

			forwardChecking(forwardCheckingBoard, freePosition, n, i, col);
			//printBoard(forwardCheckingBoard, n);
			//cout << endl;
			

			if (placingTheQueensForwardChecking(board, forwardCheckingBoard, freePosition, n, col + 1)) {
				return true;
			}

			board[i][col] = 0;
			forwardCheckingBack(forwardCheckingBoard, freePosition, n, i, col);
			//cout << "back\n";
			//printBoard(forwardCheckingBoard, n);
			//cout << endl;
		}
	}
	return false;
}


int main()
{
	cout << "Choose an algorithm:\n";
	cout << "\t1 Backtracking\n";
	cout << "\t2 Backtracking + MVR + forward checking\n";
	cout << "\t3 Backtracking + MVR + AC-3\n";
	int algorithm;
	cin >> algorithm;
	system("CLS");
	int n;
	cout << "Size of the tabla: ";
	cin >> n;
	cout << endl;
	int** board;
	int** forwardCheckingBoard;
	int* freePosition = new int[n];
	board = new int* [n];
	forwardCheckingBoard = new int* [n];
	for (int i = 0; i < n; i++) {
		board[i] = new int[n];
		forwardCheckingBoard[i] = new int[n];
	}

	for (int i = 0; i < n; i++) {
		freePosition[i] = n;
		for (int j = 0; j < n; j++) {
			board[i][j] = 0;
			forwardCheckingBoard[i][j] = 0;
		}
	}

	switch (algorithm) {
	case 1:
		//backtracking
		if (!placingTheQueens(board, n, 0)) {
			cout << "Solution don't exist\n";
		}
		else {
			printBoard(board, n);
		}
		break;
	case 2:
		//backtracking + MVR + forward checking
		if (!placingTheQueensForwardChecking(board, forwardCheckingBoard, freePosition, n, 0)) {
			cout << "Solution don't exist\n";
		}
		else {
			printBoard(board, n);
		}
		break;
	case 3:
		//backtracking + MVR + AC-3
		cout << "Not implemented :)\n";
		break;
	default:
		cout << "Algorithm don't exist\n";
	}

	return 0;
}

