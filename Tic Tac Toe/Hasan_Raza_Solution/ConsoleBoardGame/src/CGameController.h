/*
 * CGameController.h
 *
 *  Created on: Nov 16, 2023
 *      Author: hasan.raza@stud.h-da.de
 *      \brief: This class will control the whole game
 */

#ifndef CGAMECONTROLLER_H_
#define CGAMECONTROLLER_H_
#include<iostream>
#include<string>
#include"CBoard.h"
#include "CTicTacToeBoard.h"
#include"CPlayer.h"
#include"CHumanPlayer.h"
#include"CComputerPlayer.h"
#include"CUserInterface.h"

class CGameController {
private:
	CBoard* m_gameBoard;
	CUserInterface m_userInterface;
	CPlayer* m_player1;
	CPlayer* m_player2;


public:

	/**
	 * \brief: This is the constructor
	 */
	CGameController();

	/**
	 * \brief: destructor for the game controller
	 */

	~CGameController();

	/**
	 *
	 * \brief: This method selects the player 1
	 */
	void selectPlayer1();

	/**
	 *
	 * \brief: This method selects the player 1
	 */

	void selectPlayer2();

	/**
	 *
	 * \brief: This method selects the board
	 */
	void selectBoard();

	/**
	 *
	 * \brief: This method starts the game
	 */
	bool startGame();
	// Other game control functions...
};




#endif /* CGAMECONTROLLER_H_ */
