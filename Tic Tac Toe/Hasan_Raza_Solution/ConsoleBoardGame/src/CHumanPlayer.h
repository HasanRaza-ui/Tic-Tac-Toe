/*
 * CHumanPlayer.h
 *
 *  Created on: Nov 13, 2023
 *      Author: hasan.raza@stud.h-da.de
 *      \brief: This is the specialized class for Human Player:
 *      Human Will enter his/her desired position for placing the stone.
 */

#ifndef CHUMANPLAYER_H_
#define CHUMANPLAYER_H_
#include "CPlayer.h"
#include "CUserInterface.h"
using namespace std;

class CHumanPlayer : public CPlayer {

private:
	char m_symbol;
	CUserInterface m_ui;
public:

	/**
	 * \brief: destructor for the player
	 */
	CHumanPlayer(char s);

	~CHumanPlayer();

	/**
	 * \brief: This method is used to make the desired move by the human or computer player on the board
	 * @param: [IN]: board
	 */

	void makeMove(CBoard& board);

	/**
	 * \brief: This method is to get the symbol of the current player
	 */

	char getPlayerSymbol() const;

	/**
	 * \brief: This method is used to set the player 1 is computer or not
	 * @param: [bool]: true -> the player1 is computer or vice versa
	 */

	void setComputerPlayer1(bool set);

	/**
	 * \brief: This method is used to set the player 2 is computer or not
	 * @param: [bool]: true -> the player2 is computer or vice versa
	 */

	void setComputerPlayer2(bool set);

	//bool getComputerPlayer1();

};



#endif /* CHUMANPLAYER_H_ */
