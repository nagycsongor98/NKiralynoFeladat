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

bool placingTheQueens(int** board, int n, int col, int &solution)
{
	if (col >= n) {
		return true;
	}

	for (int i = 0; i < n; i++) {
		if (goodPosition(board, n, i, col)) {
			board[i][col] = 1;
			solution++;

			if (placingTheQueens(board, n, col + 1, solution)) {
				return true;
			}

			board[i][col] = 0;
			solution++;
		}
	}
	return false;
}

void forwardChecking(int** forwardCheckingBoard, int* freePosition, int n, int row, int col) {
	int i, j;
	for (i = 0; i < n; i++) {
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

	for (i = row-1, j = col-1; i < n && j >= 0; i++, j--) {
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

	for (i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--) {
		if (forwardCheckingBoard[i][j] == 0) {
			freePosition[j]--;
		}
		forwardCheckingBoard[i][j]++;
	}
}

void forwardCheckingBack(int** forwardCheckingBoard, int* freePosition, int n, int row, int col) {
	int i, j;
	for (i = 0; i < n; i++) {
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

	for (i = row-1, j = col-1; i < n && j >= 0; i++, j--) {
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

	for (i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--) {
		forwardCheckingBoard[i][j]--;
		if (forwardCheckingBoard[i][j] == 0) {
			freePosition[j]++;
		}
	}
}

int MVR(int* freePosition, int n) {
	int res = 0;
	for (int i = 0; i < n; i++) {
		if (freePosition[i] < freePosition[res]) {
			res = i;
		}
	}
	return res;
}



bool placingTheQueensForwardChecking(int** board, int** forwardCheckingBoard, int* freePosition, int n, int col, int free, int& solution)
{
	if (free == 0) {
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
			int freeP = freePosition[col];
			freePosition[col] = n + 1;
			solution++;

			forwardChecking(forwardCheckingBoard, freePosition, n, i, col);
			//printBoard(forwardCheckingBoard, n);
			//cout << endl;
			
			int nextCol = MVR(freePosition, n);

			if (placingTheQueensForwardChecking(board, forwardCheckingBoard, freePosition, n, nextCol,free-1, solution)) {
				return true;
			}

			board[i][col] = 0;
			freePosition[col] = freeP;
			solution++;
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
	cout << "Size of the table: ";
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

	int solution;
	switch (algorithm) {
	case 1:
		//backtracking
		solution = 0;
		if (!placingTheQueens(board, n, 0,solution)) {
			cout << "Solution don't exist\n";
		}
		else {
			//printBoard(board, n);
			cout << "Solution :"<<solution<<endl;
		}
		break;
	case 2:
		//backtracking + MVR + forward checking
		solution = 0;
		if (!placingTheQueensForwardChecking(board, forwardCheckingBoard, freePosition, n, 0, n, solution)) {
			cout << "Solution don't exist\n";
		}
		else {
			//printBoard(board, n);
			cout << "Solution :" << solution << endl;
		}
		break;
	case 3:
		//backtracking + MVR + AC-3
		solution = 0;
		cout << "Not implemented :)\n";
		break;
	default:
		cout << "Algorithm don't exist\n";
	}

	return 0;
}

