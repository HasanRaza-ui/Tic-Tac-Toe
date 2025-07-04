/*
 * CGameController.cpp
 *
 *  Created on: Nov 16, 2023
 *      Author: hasan.raza@stud.h-da.de
 */
#include"CGameController.h"


CGameController::CGameController(){

	m_gameBoard = NULL;
	m_player1 = NULL;
	m_player2 = NULL;

}

CGameController::~CGameController(){
	if(m_gameBoard){
		delete[] m_gameBoard;
	}
	if(m_player1){
		delete[] m_player1;
	}
	if(m_player2){
		delete[] m_player2;
	}
}

void CGameController::selectPlayer1(){
	m_userInterface.printMessage("Select player: 1 (1 - human, 2 - computer) :");
	int cvs = m_userInterface.getPlayerSelection();

	switch(cvs){

	case 1:
		m_player1 = new CHumanPlayer('X');
		m_userInterface.printMessage("Human Player Selected");
		m_player1->setComputerPlayer1(false);
		return;

	case 2:
		m_player1 = new CComputerPlayer('X');
		m_userInterface.printMessage("Computer Player Selected");
		m_player1->setComputerPlayer1(true);
		return;

	default:
		m_userInterface.printMessage("Please select the valid players");
		return;
	}
}

void CGameController::selectPlayer2(){
	m_userInterface.printMessage("Select player: 1 (1 - human, 2 - computer) :");
	int cvs = m_userInterface.getPlayerSelection();

	switch(cvs){

	case 1:
		m_player2 = new CHumanPlayer('O');
		m_userInterface.printMessage("Human Player Selected");
		m_player2->setComputerPlayer2(false);
		return;

	case 2:
		m_player2 = new CComputerPlayer('O');
		m_userInterface.printMessage("Computer Player Selected");
		m_player2->setComputerPlayer2(true);
		return;

	default:
		m_userInterface.printMessage("Please select the valid players");
		return;
	}
}

void CGameController::selectBoard(){

	m_gameBoard = new CTicTacToeBoard();
}

bool CGameController::startGame(){

	for(int i = 0; i < 9; i++){
		if(i == 0){
			m_userInterface.printMessage("Placing a stone in round 1");
			m_gameBoard->setCurrentPlayerSymbol('X');
			m_player1->makeMove(*m_gameBoard);
			m_userInterface.displayBoard(*m_gameBoard);
		}
		else if(i == 1){
			m_userInterface.printMessage("Placing a stone in round 2");
			m_gameBoard->setCurrentPlayerSymbol('O');
			m_player2->makeMove(*m_gameBoard);
			m_userInterface.displayBoard(*m_gameBoard);
		}
		else if(i == 2){
			m_userInterface.printMessage("Placing a stone in round 3");
			m_gameBoard->setCurrentPlayerSymbol('X');
			m_player1->makeMove(*m_gameBoard);
			m_userInterface.displayBoard(*m_gameBoard);
		}
		else if(i == 3){
			m_userInterface.printMessage("Placing a stone in round 4");
			m_gameBoard->setCurrentPlayerSymbol('O');
			m_player2->makeMove(*m_gameBoard);
			m_userInterface.displayBoard(*m_gameBoard);
		}
		else if(i == 4){
			m_userInterface.printMessage("Placing a stone in round 5");
			m_gameBoard->setCurrentPlayerSymbol('X');
			m_player1->makeMove(*m_gameBoard);
			m_userInterface.displayBoard(*m_gameBoard);
		}
		else if(i == 5){
			m_userInterface.printMessage("Placing a stone in round 6");
			m_gameBoard->setCurrentPlayerSymbol('O');
			m_player2->makeMove(*m_gameBoard);
			m_userInterface.displayBoard(*m_gameBoard);
		}
		else if(i == 6){
			m_userInterface.printMessage("Placing a stone in round 7");
			m_gameBoard->setCurrentPlayerSymbol('X');
			m_player1->makeMove(*m_gameBoard);
			m_userInterface.displayBoard(*m_gameBoard);
		}
		else if(i == 7){
			m_userInterface.printMessage("Placing a stone in round 8");
			m_gameBoard->setCurrentPlayerSymbol('O');
			m_player2->makeMove(*m_gameBoard);
			m_userInterface.displayBoard(*m_gameBoard);
		}
		else{
			m_userInterface.printMessage("Placing a stone in round 9");
			m_gameBoard->setCurrentPlayerSymbol('X');
			m_player1->makeMove(*m_gameBoard);
			m_userInterface.displayBoard(*m_gameBoard);
		}
	}
	if(m_gameBoard->checkForWinner(m_player1->getPlayerSymbol())){
		m_userInterface.printMessage("Congratulations: Player 1 win the game:");
		return true;
	}
	else if(m_gameBoard->checkForWinner(m_player2->getPlayerSymbol())){
		m_userInterface.printMessage("Congratulations: Player 2 win the game:");
		return true;
	}
	else{
		m_userInterface.printMessage("The Game has been draw: Neither Player 1 Nor Player 2 win the game");
		return true;
	}
	return false;
}

