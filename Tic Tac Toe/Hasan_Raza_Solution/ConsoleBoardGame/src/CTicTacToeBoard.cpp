/*
 * CTicTacToeBoard.cpp
 *
 *  Created on: Nov 11, 2023
 *      Author: hasan.raza@stud.h-da.de
 */

#include<iostream>
#include<string>
#include"CTicTacToeBoard.h"
using namespace std;

CTicTacToeBoard::CTicTacToeBoard(){


	m_currentPlayerSymbol = 'X';
	for(int i = 0; i < BOARD_SIZE; i++){

		for(int j = 0; j < BOARD_SIZE; j++){

			m_tictactoeBoard[i][j] = ' ';

		}
	}
}


CTicTacToeBoard::~CTicTacToeBoard(){

	for(int i = 0; i < BOARD_SIZE; i++){

		for(int j = 0; j < BOARD_SIZE; j++){

			m_tictactoeBoard[i][j] = ' ';

		}
	}
}

void CTicTacToeBoard::setCurrentPlayerSymbol(char symbol) {
        m_currentPlayerSymbol = symbol;
    }


void CTicTacToeBoard::placeStone(int row, int col, char symbol){

	if ((0 <= row) && (row < BOARD_SIZE) && (0 <= col) && (col < BOARD_SIZE)){
		if(m_tictactoeBoard[row][col] == ' '){
			m_tictactoeBoard[row][col] = symbol;
		}
		else
			cout << "The position is already occupied" << endl;

	}
	else
		cout << "Please choose the valid position (0.." << BOARD_SIZE << ") as the board is" << BOARD_SIZE << "X" << BOARD_SIZE << " Board " << endl;


}

bool CTicTacToeBoard::checkForWinner(char stonesymbol) const {
    // Check rows and columns
    for (int i = 0; i < BOARD_SIZE; i++) {
        int rowCheck = 0;
        int colCheck = 0;

        for (int j = 0; j < BOARD_SIZE; j++) {
            if (m_tictactoeBoard[i][j] == stonesymbol) {
                rowCheck += 1;
            }
            if (m_tictactoeBoard[j][i] == stonesymbol) {
                colCheck += 1;
            }
        }

        if (rowCheck == BOARD_SIZE || colCheck == BOARD_SIZE) {
            return true; // Found a winner in rows or columns
        }
    }

    // Check diagonals
    int diagonalCheck1 = 0;
    int diagonalCheck2 = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (m_tictactoeBoard[i][i] == stonesymbol) {
            diagonalCheck1 += 1;
        }
        if (m_tictactoeBoard[i][BOARD_SIZE - 1 - i] == stonesymbol) {
            diagonalCheck2 += 1;
        }
    }

    if (diagonalCheck1 == BOARD_SIZE || diagonalCheck2 == BOARD_SIZE) {
        return true; // Found a winner in diagonals
    }

    return false; // No winner found
}



void CTicTacToeBoard::displayBoard() const {
    for (int i = 0; i < BOARD_SIZE; i++) {
        cout << "\n";

        for (int j = 0; j < BOARD_SIZE; j++) {
            if (j != 0) {
                cout << " | ";  // Separators between columns
            }
            cout << " " << m_tictactoeBoard[i][j] << " ";
        }

        if (i != BOARD_SIZE - 1) {
            cout << "\n---------------\n";  // Separator between rows
        }
    }
    cout << "\n";
}

bool CTicTacToeBoard::checkPosition(int row, int col) const{

	if(m_tictactoeBoard[row][col] != ' '){
		return true;
	}
	else
		return false;
}


char CTicTacToeBoard::checkSymbol(int row, int col) const{

	return m_tictactoeBoard[row][col];

}


bool CTicTacToeBoard::checkForWinningMove(char playerSymbol) const {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if ((m_tictactoeBoard[i][0] == playerSymbol) && (m_tictactoeBoard[i][1] == playerSymbol) && (m_tictactoeBoard[i][2] == playerSymbol)) {
            return true;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if ((m_tictactoeBoard[0][j] == playerSymbol) && (m_tictactoeBoard[1][j] == playerSymbol) && (m_tictactoeBoard[2][j] == playerSymbol)) {
            return true;
        }
    }

    // Check main diagonal
    if ((m_tictactoeBoard[0][0] == playerSymbol) && (m_tictactoeBoard[1][1] == playerSymbol) && (m_tictactoeBoard[2][2] == playerSymbol)) {
        return true;
    }

    // Check anti-diagonal
    else if ((m_tictactoeBoard[0][2] == playerSymbol) && (m_tictactoeBoard[1][1] == playerSymbol) && (m_tictactoeBoard[2][0] == playerSymbol)) {
        return true;
    }
    else{
    	return false;
    }

}


char CTicTacToeBoard::getOpponentSymbol() const {
    return (m_currentPlayerSymbol == 'X') ? 'O' : 'X';
}


std::pair<int, int> CTicTacToeBoard::getWinningMove(char playerSymbol) const {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if ((m_tictactoeBoard[i][0] == playerSymbol) && (m_tictactoeBoard[i][1] == playerSymbol) && (m_tictactoeBoard[i][2] == ' ')) {
            return {i, 2};
        }
        if ((m_tictactoeBoard[i][0] == playerSymbol) && (m_tictactoeBoard[i][2] == playerSymbol) && (m_tictactoeBoard[i][1] == ' ')) {
            return {i, 1};
        }
        if ((m_tictactoeBoard[i][1] == playerSymbol) && (m_tictactoeBoard[i][2] == playerSymbol) && (m_tictactoeBoard[i][0] == ' ')) {
            return {i, 0};
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if ((m_tictactoeBoard[0][j] == playerSymbol) && (m_tictactoeBoard[1][j] == playerSymbol) && (m_tictactoeBoard[2][j] == ' ')) {
            return {2, j};
        }
        if ((m_tictactoeBoard[0][j] == playerSymbol) && (m_tictactoeBoard[2][j] == playerSymbol) && (m_tictactoeBoard[1][j] == ' ')) {
            return {1, j};
        }
        if ((m_tictactoeBoard[1][j] == playerSymbol) && (m_tictactoeBoard[2][j] == playerSymbol) && (m_tictactoeBoard[0][j] == ' ')) {
            return {0, j};
        }
    }

    // Check main diagonal
    if ((m_tictactoeBoard[0][0] == playerSymbol) && (m_tictactoeBoard[1][1] == playerSymbol) && (m_tictactoeBoard[2][2] == ' ')) {
        return {2, 2};
    }
    if ((m_tictactoeBoard[0][0] == playerSymbol) && (m_tictactoeBoard[2][2] == playerSymbol) && (m_tictactoeBoard[1][1] == ' ')) {
        return {1, 1};
    }
    if ((m_tictactoeBoard[1][1] == playerSymbol) && (m_tictactoeBoard[2][2] == playerSymbol) && (m_tictactoeBoard[0][0] == ' ')) {
        return {0, 0};
    }

    // Check anti-diagonal
    if ((m_tictactoeBoard[0][2] == playerSymbol) && (m_tictactoeBoard[1][1] == playerSymbol) && (m_tictactoeBoard[2][0] == ' ')) {
        return {2, 0};
    }
    if ((m_tictactoeBoard[0][2] == playerSymbol) && (m_tictactoeBoard[2][0] == playerSymbol) && (m_tictactoeBoard[1][1] == ' ')) {
        return {1, 1};
    }
    if ((m_tictactoeBoard[1][1] == playerSymbol) && (m_tictactoeBoard[2][0] == playerSymbol) && (m_tictactoeBoard[0][2] == ' ')) {
        return {0, 2};
    }

    return {-1, -1}; // No winning move found
}









