/*
 * CComputerPlayer.h
 *
 *  Created on: Nov 13, 2023
 *      Author: hasan.raza@stud.h-da.de
 *      \brief: This is the specialized class for Computer Player:
 *      Computer will decide about his move in such a way that it may never looses the game
 */

#ifndef CCOMPUTERPLAYER_H_
#define CCOMPUTERPLAYER_H_
#include"CPlayer.h"
using namespace std;

class CComputerPlayer : public CPlayer {

private:
	char m_symbol;
public:
	/**
	 * \brief: This will initialize the symbol for the current player: If computer player is 1 -> "X" else -> "O"
	 */
	CComputerPlayer(char s);
	/**
	 *  \brief: deconstructor of the object: currently it is not doing anything
	 */

	~CComputerPlayer();

	/**
	 * \brief: this will decide for the particular move for the computer
	 * @param CBoard& board      [IN] : Board instance
	 */

	void makeMove(CBoard& board);

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

	/**
	 * \brief: This method is to get the symbol of the current player
	 */

	char getPlayerSymbol() const;


	/**
	 * \brief: This will check for the winning move if available
	 * @param CBoard& board      [IN] : Board instance  [OUT]: true if there is winning move available else fase
	 *
	 */
	bool makeWinningMove(CBoard& board);

	/**
	 * \brief: this method will check if the opponent is winning then block the winning move
	 * @param CBoard& board      [IN] : Board instance  [OUT]: true if there is winning move available else false
	 */
	bool blockOpponentWinningMove(CBoard& board);

	/**
	 * \brief: This method will place the stone in the center
	 * @param CBoard& board      [IN] : Board instance  [OUT]: true if there is winning move available else false
	 *
	 */
	bool makeMoveInCenter(CBoard& board);

	/**
	 * \brief: This method will place the stone in the corner of the board
	 * @param CBoard& board      [IN] : Board instance  [OUT]: true if there is winning move available else false
	 */
	bool makeMoveInCorner(CBoard& board);

	/**
	 * \brief: This method will place the stone on the edge
	 * @param CBoard& board      [IN] : Board instance
	 */
	void makeMoveInEdge(CBoard& board);



};



#endif /* CCOMPUTERPLAYER_H_ */
