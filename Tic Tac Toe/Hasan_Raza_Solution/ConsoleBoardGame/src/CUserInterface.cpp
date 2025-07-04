/*
 * CUserInterface.cpp
 *
 *  Created on: Nov 16, 2023
 *      Author: hasan.raza@stud.h-da.de
 */


#include"CUserInterface.h"

void CUserInterface::displayBoard(const CBoard& board){
	board.displayBoard();
}

int CUserInterface::getPlayerSelection(){

	int player = 0;
	cin >> player;
	return player;

}

void CUserInterface::printMessage(const string msg) {
	m_console.displayMessage(msg);
}

void CUserInterface::showWinner(const CPlayer& winner, const CBoard& board){
	if(board.checkForWinner(winner.getPlayerSymbol())){
		if(winner.getPlayerSymbol() == 'X'){
			board.displayBoard();
			cout << "\n" << "The player 1 is winner" <<endl;
		}
		else{
			board.displayBoard();
			cout << "\n" << "The player 2 is winner" <<endl;
		}
	}
}

std::pair<int, int> CUserInterface::getUserMove(){
	cout << "Please put the required position (x , x) on which you want to place your stone: x varies from 0..2 " << endl;
	std::pair<int , int> input;
	std::cout << "Enter the row number of the desired location: ";
	std::cin >> input.first;
	std::cout << "Enter the col number of the desired location: ";
	std::cin >> input.second;
	return input;
}
