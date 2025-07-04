/*
 * CPlayer.h
 *
 *  Created on: Nov 13, 2023
 *      Author: hasan.raza@stud.h-da.de
 *  \brief: This class is an abstract class for a player
 *  form which two specialized classes will be derived for Human Player
 *  and Computer Player.
 */
#ifndef CPLAYER_H_
#define CPLAYER_H_
#include<iostream>
#include<string>
#include"CBoard.h"
using namespace std;

class CPlayer {

protected:

	int m_countMove;
	bool m_computerPlayer1;
	bool m_computerPlayer2;

public:

	/**
	 * \brief: destructor for the player
	 */

	virtual ~CPlayer() = default;

	/**
	 * \brief: This method is used to make the desired move by the human or computer player on the board
	 * @param: [IN]: board
	 */

    virtual void makeMove(CBoard& board) = 0;

    /**
     * \brief: This method is to get the symbol of the current player
     */

    virtual char getPlayerSymbol() const = 0;

    /**
     * \brief: This method is used to set the player 1 is computer or not
     * @param: [bool]: true -> the player1 is computer or vice versa
     */

    virtual void setComputerPlayer1(bool set) = 0;

    /**
     * \brief: This method is used to set the player 2 is computer or not
     * @param: [bool]: true -> the player2 is computer or vice versa
     */

    virtual void setComputerPlayer2(bool set) = 0;

    //virtual bool getComputerPlayer1() = 0;

};

#endif /* CPLAYER_H_ */
