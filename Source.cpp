//Mason Hamilton
//This is all my own work
//Libaries included
#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;


//creating my blank board game
char board[6][7] = {
		{'_', '_', '_', '_', '_', '_', '_'},
		{'_', '_', '_', '_', '_', '_', '_'},
		{'_', '_', '_', '_', '_', '_', '_'},
		{'_', '_', '_', '_', '_', '_', '_'},
		{'_', '_', '_', '_', '_', '_', '_'},
		{'_', '_', '_', '_', '_', '_', '_'}
};
//Fuction used to print out my game board
void printGame() {
	cout << "                 Connect four  " << endl;
	for (int i = 0; i < 6; i++) {
		cout << "              ";
		for (int j = 0; j < 7; j++) {
			cout << board[i][j] << "  ";
		}
		cout << endl;
	}
	cout << "              ^  ^  ^  ^  ^  ^  ^" << endl;
	cout << "              z  x  c  v  b  n  m" << endl << endl;
}

//Taking the users input and placeing the token in the correct coloumn
void placeMark() {

	cout << "Enter the letter to place a marker in that column: " << endl << endl;;
	char userInput;

	cin >> userInput;
	cout << endl;
	userInput = tolower(userInput);
	if (userInput == 'z') {
		int j = 0;
		for (int i = 5; i > -1;) {
			if (board[i][j] == '_') {
				board[i][j] = '$';
				break;
			}
			else if (i == 0) {
				cout << "This lane is full, lost your turn" << endl;
				break;
			}
			i--;
		}
	}
	else if (userInput == 'x') {
		int j = 1;
		for (int i = 5; i > -1;) {
			if (board[i][j] == '_') {
				board[i][j] = '$';
				break;
			}
			else if (i == 0) {
				cout << "This lane is full, lost your turn" << endl;
				break;
			}
			i--;
		}
	}
	else if (userInput == 'c') {
		int j = 2;
		for (int i = 5; i > -1;) {
			if (board[i][j] == '_') {
				board[i][j] = '$';
				break;
			}
			else if (i == 0) {
				cout << "This lane is full, lost your turn" << endl;
				break;
			}
			i--;
		}
	}
	else if (userInput == 'v') {
		int j = 3;
		for (int i = 5; i > -1;) {
			if (board[i][j] == '_') {
				board[i][j] = '$';
				break;
			}
			else if (i == 0) {
				cout << "This lane is full, lost your turn" << endl;
				break;
			}
			i--;
		}
	}
	else if (userInput == 'b') {
		int j = 4;
		for (int i = 5; i > -1;) {
			if (board[i][j] == '_') {
				board[i][j] = '$';
				break;
			}
			else if (i == 0) {
				cout << "This lane is full, lost your turn" << endl;
				break;
			}
			i--;
		}
	}
	else if (userInput == 'n') {
		int j = 5;
		for (int i = 5; i > -1;) {
			if (board[i][j] == '_') {
				board[i][j] = '$';
				break;
			}
			else if (i == 0) {
				cout << "This lane is full, lost your turn" << endl;
				break;
			}
			i--;
		}
	}
	else if (userInput == 'm') {
		int j = 6;
		for (int i = 5; i > -1;) {
			if (board[i][j] == '_') {
				board[i][j] = '$';
				break;
			}
			else if (i == 0) {
				cout << "This lane is full, lost your turn" << endl;
				break;
			}
			i--;
		}
	}
	else {
		cout << "You typed the wrong letter, lost your turn" << endl;
	}
}

void LCM() {

	int cost = 0;
	//check for column winners
	for (int i = 5; i > -1; i--) {
		for (int j = 6; j > -1; j--) {
			if (board[i][j] == '#') {
				if (board[i - 1][j] == '#') {
					if (board[i - 2][j] == '#') {
						if (board[i - 3][j] == '_') {
							board[i - 3][j] = '#';
							cout << "Value was +10 so we placed and won!" << endl << endl;
							return;
						}
					}
				}
			}
		}
	}
	//check for row winners
	for (int i = 5; i > -1; i--) {
		for (int j = 6; j > -1; j--) {
			if (board[i][j] == '#') {
				if (board[i][j - 1] == '#') {
					if (board[i][j - 2] == '#') {
						if (board[i][j - 3] == '_') {
							board[i][j - 3] = '#';
							cout << "Value was +10 so we placed and won!" << endl << endl;
							return;
						}
					}
				}
			}
		}
	}

	for (int i = 5; i > -1; i--) {
		for (int j = 6; j > -1; j--) {
			if (board[i][j] == '#') {
				if (board[i + 1][j] == '#') {
					if (board[i + 2][j] == '#') {
						if (board[i + 3][j] == '_') {
							board[i + 3][j] = '#';
							cout << "Value was +10 so we placed and won!" << endl << endl;
							return;
						}
					}
				}
			}
		}
	}
	//check for row winners
	for (int i = 5; i > -1; i--) {
		for (int j = 6; j > -1; j--) {
			if (board[i][j] == '#') {
				if (board[i][j + 1] == '#') {
					if (board[i][j + 2] == '#') {
						if (board[i][j + 3] == '_') {
							board[i][j + 3] = '#';
							cout << "Value was +10 so we placed and won!" << endl << endl;
							return;
						}
					}
				}
			}
		}
	}

	//block coloumn winners
	for (int i = 5; i > -1; i--) {
		for (int j = 6; j > -1; j--) {
			if (board[i][j] == '$') {
				if (board[i - 1][j] == '$') {
					if (board[i - 2][j] == '$') {
						if (board[i - 3][j] == '_') {
							board[i - 3][j] = '#';
							cout << "Value was -10 if not placed" << endl << endl;
							return;
						}
					}
				}
			}

		}
	}

	//block row winners
	for (int i = 5; i > -1; i--) {
		for (int j = 6; j > -1; j--) {
			if (board[i][j] == '$') {
				if (board[i][j - 1] == '$') {
					if (board[i][j - 2] == '$') {
						if (board[i][j - 3] == '_') {
							board[i][j - 3] = '#';
							cout << "Value was -10 if not placed" << endl << endl;
							return;
						}
					}
				}
			}
		}
	}

	//block coloumn winners
	for (int i = 5; i > -1; i--) {
		for (int j = 6; j > -1; j--) {
			if (board[i][j] == '$') {
				if (board[i + 1][j] == '$') {
					if (board[i + 2][j] == '$') {
						if (board[i + 3][j] == '_') {
							board[i + 3][j] = '#';
							cout << "Value was -10 if not placed" << endl << endl;
							return;
						}
					}
				}
			}

		}
	}

	//block row winners
	for (int i = 5; i > -1; i--) {
		for (int j = 6; j > -1; j--) {
			if (board[i][j] == '$') {
				if (board[i][j + 1] == '$') {
					if (board[i][j + 2] == '$') {
						if (board[i][j + 3] == '_') {
							board[i][j + 3] = '#';
							cout << "Value was -10 if not placed" << endl << endl;
							return;
						}
					}
				}
			}
		}
	}

	for (int i = 5; i > -1; i--) {
		for (int j = 6; j > -1; j--) {
			if (board[i][j] == '#') {
				if (board[i - 1][j] == '#') {
					if (board[i - 2][j] == '#') {
						if (board[i - 3][j] == '_') {
							board[i - 3][j] = '#';
							cout << "Value was 0 " << endl << endl;
							return;
						}
					}
					else if (board[i - 2][j] == '_') {
						board[i - 2][j] = '#';
						cout << "Value was 0 " << endl << endl;
						return;
					}
				}
				else if (board[i - 1][j] == '_') {
					board[i - 1][j] = '#';
					cout << "Value was 0 " << endl << endl;
					return;
				}

			}
			
				//puts a token on an empty section
			else if (board[i][j] == '_') {
				board[i][j] = '#';
				cout << "Value was 0 " << endl << endl;
				return;
			}
		}
	}
}

int main() {
	cout << endl << endl;
	cout << "			Welcome to my Connect 4 LCV game" << endl;
	cout << "				You will go first" << endl;
	cout << "			To place a token enter that coloumn letter" << endl;
	cout << "			Your token's = $   Computer token's = #  Empty slot's = _ " << endl;
	cout << endl << endl;
	printGame();
	for (int i = 0; i < 25; i++) {
		placeMark();
		printGame();
		cout << "        	 Your token's = $   Computer token's = #  Empty slot's = _ " << endl << endl;
		LCM();
		printGame();
	}


}