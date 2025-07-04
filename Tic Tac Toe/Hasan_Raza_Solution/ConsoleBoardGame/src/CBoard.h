/*
 * CBoard.h
 * brief: Interface of TicTacToe Board
 *
 *  Created on: Nov 11, 2023
 *      Author: hasan.raza@stud.h-da.de
 */

#ifndef CBOARD_H_
#define CBOARD_H_

#include<string>
using namespace std;


/*
 * \brief: This class is an abstract or interface class for the Tic Tac Toe Game
 * from which different variants of the TicTacToe Board (3x3, 6x6, 9x9) can be derived.
 *
 * Strategy Interface (pure virtual class)
*/

class CBoard{

public:

	CBoard(){};

	virtual ~CBoard() = default;

	/**
	 * \brief: Places the stone ('x' or 'o') on the desired place of the board
	 */

	virtual void placeStone(int row, int col, char symbol) = 0;

	/**
	 *  \brief: It implements the algorithm for checking and declaring the winner, looser or game draw
	 */

	virtual bool checkForWinner(char stonesymbol) const = 0;

	/**
	 * \brief: It displays the current status of the board
	 */

	virtual void displayBoard() const = 0;

	/**
	 * \brief: It displays the current status of the required position
	 */

	virtual bool checkPosition(int row, int col) const = 0;


	/**
	 * \brief: It returns the stone symbol at the required position
	 */

	virtual char checkSymbol(int row, int col) const = 0;

	/**
	 * \brief: This method will check if there is winning move available
	 * [IN] : the stone symbol of the player
	 */


	virtual bool checkForWinningMove(char playerSymbol) const = 0;

	/**
	 * \brief: This method will return the symbol of the opponent player
	 * [OUT] : "X" or "O"
	 */

	virtual char getOpponentSymbol() const = 0;

	/**
	 * \brief: This method will return the (row, col) pair of the winning move.
	 * [OUT]: {row, col}
	 *
	 * */



	virtual std::pair<int, int> getWinningMove(char playerSymbol) const = 0;

	/**
	 * \brief: This method set the current player symbol attribute
	 * @param: [IN]: char symbol
	 */

	virtual void setCurrentPlayerSymbol(char symbol) = 0;

};



#endif /* CBOARD_H_ */
