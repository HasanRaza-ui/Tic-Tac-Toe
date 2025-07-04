/*
 * CUserInterface.h
 *
 *  Created on: Nov 16, 2023
 *      Author: hasan.raza@stud.h-da.de
 *      \brief: This class acts as the main interface between the user and the game.
 */

#ifndef CUSERINTERFACE_H_
#define CUSERINTERFACE_H_
#include <iostream>
#include <string>
#include "CBoard.h"
#include "CPlayer.h"
#include "CConsoleIO.h"
using namespace std;

class CUserInterface {
private:
	CConsoleIO m_console;

public:

	/**
	 * \brief: this method is used for display of the current status of the board
	 */
    void displayBoard(const CBoard& board);

    /**
     * \brief: This method is used to get the move from the user
     */

    std::pair<int, int> getUserMove();

    /**
     * \brief: This method is used to show the winner
     */

    void showWinner(const CPlayer& winner, const CBoard& board);
    // Other display-related functions...

    /**
     * \brief: This method is used to get the player whether player 1 is Human/Computer and Player 2 is Human/Computer
     */
    int getPlayerSelection();

    /**
     * \brief: This method is used to print the message to the console
     */
    void printMessage(const string msg);
};




#endif /* CUSERINTERFACE_H_ */
