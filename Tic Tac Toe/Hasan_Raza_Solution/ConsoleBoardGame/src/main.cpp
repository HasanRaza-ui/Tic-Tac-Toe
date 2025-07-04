//============================================================================
// Name        : ConsoleBoardGame.cpp
// Author      : Hasan Raza
// Version     :
// Copyright   : This program is the part of the lab task of ASDT and copyright of h-da and Hasan Raza
// Description : Console Board Game -> TicTacToe Console Board Game, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include"CGameController.h"
using namespace std;

int main() {

	// object of the game CGameController
	CGameController game;
	// Selection of Board
	game.selectBoard();

	// Infinite loop for continuing the game
	while(1){

		game.selectPlayer1();
		game.selectPlayer2();
		if(game.startGame()){
			game.~CGameController();
		}

	}

	return 0;
}
