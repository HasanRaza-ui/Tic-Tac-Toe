/*
 * CHumanPlayer.cpp
 *
 *  Created on: Nov 13, 2023
 *      Author: hasan.raza@stud.h-da.de
 */
#include"CHumanPlayer.h"

CHumanPlayer::CHumanPlayer(char s){
	m_symbol = s;
}

CHumanPlayer::~CHumanPlayer(){}

void CHumanPlayer::makeMove(CBoard& board){
	std::pair<int, int> rowcol;
	rowcol = m_ui.getUserMove();
	board.placeStone(rowcol.first, rowcol.second, m_symbol);

}


void CHumanPlayer::setComputerPlayer1(bool set){
	m_computerPlayer1 = set;
}

void CHumanPlayer::setComputerPlayer2(bool set){
	m_computerPlayer2 = set;
}



char CHumanPlayer::getPlayerSymbol() const{
	return m_symbol;
}






