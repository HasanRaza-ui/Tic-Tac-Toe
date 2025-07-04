/*
 * CTicTacToeBoard.h
 *
 *  Created on: Dec 16, 2023
 *      Author: cvalley
 */

#ifndef CTICTACTOEBOARD_H_
#define CTICTACTOEBOARD_H_
#include"CBoard.h"
#include"CScreen.h"
#include <utility>   // Include for std::pair
class CScreen;  // Forward declaration for CScreen

class CTicTacToeBoard : public CBoard {

public:

	CTicTacToeBoard(CScreen &screen);

	~CTicTacToeBoard();
	/**
	 * \brief: This method will confirm the winner
	 * @return: true if there is a winner otherwise false
	 */

	bool checkForWinner(char stonesymbol) const;

	/**
	 * \brief: This method will check if there is winning move available
	 * [IN] : the stone symbol of the player
	 */

	bool checkForWinningMove(char playerSymbol) const;

	/**
	 * \brief: This method will return the (row, col) pair of the winning move.
	 * [OUT]: {row, col}
	 *
	 * */

	std::pair<int, int> getWinningMove(char playerSymbol) const;

	/**
	 * \brief: It displays the current status of the required position
	 */

	bool checkPosition(int row, int col);

};




#endif /* CTICTACTOEBOARD_H_ */
