/*
 * CComputerPlayer.cpp
 *
 *  Created on: Nov 13, 2023
 *      Author: hasan.raza@stud.h-da.de
 */
#include"CComputerPlayer.h"


CComputerPlayer::CComputerPlayer(char s){

	m_symbol = s;
}

CComputerPlayer::~CComputerPlayer(){}


void CComputerPlayer::setComputerPlayer1(bool set){
	m_computerPlayer1 = set;
}

void CComputerPlayer::setComputerPlayer2(bool set){
	m_computerPlayer2 = set;
}

char CComputerPlayer::getPlayerSymbol() const{
	return m_symbol;
}

void CComputerPlayer::makeMove(CBoard& board) {
	if (m_computerPlayer1) {
		// Computer is player 1
		if (makeWinningMove(board)) {
			return;
		} else if (blockOpponentWinningMove(board)) {
			return;
		}
		else if(makeMoveInCenter(board)) {
			return;
		}
		else if(makeMoveInCorner(board)) {
			return;
		}
		else {
			makeMoveInEdge(board);
			return;
		}
	}
	else{
		if(m_computerPlayer2) {
			// Computer is player 2
			if (blockOpponentWinningMove(board)) {
				return;
			} else if (makeWinningMove(board)) {
				return;
			}
			else if(makeMoveInCenter(board)) {
				return;
			}
			else if(makeMoveInCorner(board)) {
				return;
			}
			else {
				makeMoveInEdge(board);
				return;
			}

		}
	}

	// If no winning or blocking moves, make strategic moves

}

bool CComputerPlayer::makeWinningMove(CBoard& board) {
	if (board.checkForWinningMove(m_symbol)) {
		if(board.getWinningMove(m_symbol).first && board.getWinningMove(m_symbol).second){
			board.placeStone(board.getWinningMove(m_symbol).first, board.getWinningMove(m_symbol).second, m_symbol);
			return true;
		}
	}
	return false;
}

bool CComputerPlayer::blockOpponentWinningMove(CBoard& board) {

	if (board.checkForWinningMove(board.getOpponentSymbol())) {
		if(board.getWinningMove(m_symbol).first && board.getWinningMove(m_symbol).second){
			board.placeStone(board.getWinningMove(m_symbol).first, board.getWinningMove(m_symbol).second, m_symbol);
			return true;
		}
	}
	return false;
}

bool CComputerPlayer::makeMoveInCenter(CBoard& board) {
    if (!board.checkPosition(1, 1)) {
        board.placeStone(1, 1, m_symbol);
        return true;
    }
    return false;
}

bool CComputerPlayer::makeMoveInCorner(CBoard& board) {
    static const std::pair<int, int> corners[] = {{0, 0}, {0, 2}, {2, 0}, {2, 2}};
    for (const auto& corner : corners) {
        if (!board.checkPosition(corner.first, corner.second)) {
            board.placeStone(corner.first, corner.second, m_symbol);
            return true;
        }
    }
    return false;
}

void CComputerPlayer::makeMoveInEdge(CBoard& board) {
    static const std::pair<int, int> edges[] = {{0, 1}, {1, 0}, {1, 2}, {2, 1}};
    for (const auto& edge : edges) {
        if (!board.checkPosition(edge.first, edge.second)) {
            board.placeStone(edge.first, edge.second, m_symbol);
            return;
        }
    }
}





