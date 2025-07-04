/*
 * CTicTacToeBoard.cpp
 *
 *  Created on: Dec 16, 2023
 *      Author: cvalley
 */
#include"CTicTacToeBoard.h"

CTicTacToeBoard::CTicTacToeBoard(CScreen& screen) : CBoard(screen) {

}

CTicTacToeBoard::~CTicTacToeBoard(){

	CBoard::~CBoard();
}

bool CTicTacToeBoard::checkForWinner(char stonesymbol) const{



	return false;
}

bool CTicTacToeBoard::checkForWinningMove(char stonesymbol) const{



	return false;
}


std::pair<int, int> CTicTacToeBoard::getWinningMove(char stonesymbol) const{



	return false;
}


bool CTicTacToeBoard::checkPosition(int row, int col){

	bool result = false;
	if(m_tictactoeBoard[row][col] == ' '){
		result = true;
	}

	if(result){

		return true;
	}
	else
		return false;
}








