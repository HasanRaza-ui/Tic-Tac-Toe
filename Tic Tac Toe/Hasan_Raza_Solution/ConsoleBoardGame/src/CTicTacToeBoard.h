/*
 * CTicTacToeBoard.h
 *
 *  Created on: Nov 11, 2023
 *      Author: hasan.raza@stud.h-da.de
 */

#ifndef CTICTACTOEBOARD_H_
#define CTICTACTOEBOARD_H_

#include<string>
#include<iostream>
#include"CBoard.h"
#define BOARD_SIZE 3

using namespace std;

/**
 * \brief: This is the concrete strategy class for TicTacToe Board
 * It will create the required variant of Board
 * It will Place the Stone to the required position of the Board
 * It will check for the winner of the game
 * It will also display the content of the Board
 *
 */

class CTicTacToeBoard : public CBoard {

private:

	char m_tictactoeBoard[BOARD_SIZE][BOARD_SIZE];
	char m_currentPlayerSymbol;


public:
	/**
	 * \brief: it initialize the Board
	 */
	CTicTacToeBoard();

	/**
	 * \brief: It De-initialize the Board
	 *
	 */
	~CTicTacToeBoard();

	void setCurrentPlayerSymbol(char symbol);

	/**
	 * \brief: this method is used to place the stone on the required position
	 * @params: the location on the board by specifying the row and column, and the stone to be placed
	 */

	void placeStone(int row, int col, char symbol);

	/**
	 * \brief: This method will confirm the winner
	 * @return: true if there is a winner otherwise false
	 */

	bool checkForWinner(char stonesymbol) const;

	/**
	 * \brief: This method will display the content of the Board
	 *
	 */

	void displayBoard() const;

	/**
	 * \brief: It displays the current status of the required position
	 */

	bool checkPosition(int row, int col) const;


	/**
	 * \brief: It returns the stone symbol at the required position
	 */

	char checkSymbol(int row, int col) const;

	/**
	 * \brief: This method will check if there is winning move available
	 * [IN] : the stone symbol of the player
	 */

	bool checkForWinningMove(char playerSymbol) const;

	/**
	 * \brief: This method will return the symbol of the opponent player
	 * [OUT] : "X" or "O"
	 */

	char getOpponentSymbol() const;

	/**
	 * \brief: This method will return the (row, col) pair of the winning move.
	 * [OUT]: {row, col}
	 *
	 * */

	std::pair<int, int>getWinningMove(char playerSymbol) const;

};







#endif /* CTICTACTOEBOARD_H_ */
