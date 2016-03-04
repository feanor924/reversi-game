//============================================================================
// Name        : hw4.cpp
// Author      : caner
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Reversi.h"
using namespace std;

int Reversi::numberofcell=0;

int main() {

	Reversi rev1;
	Reversi rev2,rev3,rev4,rev5;
	Cell c1;

	//REVERSI-1 GAME TAKE INFO FROM TXT
	rev1.readFromFile("Caner.txt");

	cout << "REVERSI-1 GAME TAKE INFO FROM TXT"<<endl;
	rev1.printBoard();

	cout <<endl;
	cout << "TEST GAME !!!!! -TAKE CELL POSITION( play(Cell) -play() ) AND PLAY COMPUTER" <<endl;
	cout << "TEST GAME !!!!! -TAKE CELL POSITION( play(Cell) -play() ) AND PLAY COMPUTER" <<endl;
	cout <<endl;

	// REVERSI-1 GAME TAKE CELL POSITIONS
	cout << "REVERSI-1 GAME TAKE CELL POSITIONS"<<endl;
	cout <<endl;
	c1.setCoorX(3);
	c1.setCoorY(4);
	rev1.play(c1);

	// REVERSI-1 GAME WILL BE WRITTEN TO LOG.TXT
	cout <<endl;
	cout << "REVERSI-1 WRITTEN TO LOG.TXT"<<endl;
	rev1.writetoFile("Log.txt");

	// REVERSI-1 GAME READ FROM LOG.TXT
	rev1.readFromFile("Log.txt");
	cout <<endl;
	cout << "REVERSI-1 GAME READ FROM LOG.TXT"<<endl;
	rev1.printBoard();

	// REVERSI-1 GAME WILL BE PLAYED BY COMPUTER
	rev1.play();

	c1.setCoorX(4);
	c1.setCoorY(3);
	rev1.play(c1);

	rev1.play();

	c1.setCoorX(6);
	c1.setCoorY(4);
	rev1.play(c1);
	rev1.play();

	c1.setCoorX(2);
	c1.setCoorY(4);
	rev1.play(c1);
	rev1.play();

	c1.setCoorX(3);
	c1.setCoorY(2);
	rev1.play(c1);

	rev1.play();

	c1.setCoorX(5);
	c1.setCoorY(6);
	rev1.play(c1);

	rev1.play();

	cout <<endl<<endl;

	cout << "REVERSI-2 GAME"<<endl;
	rev2.printBoard();

	cout << "REVERSI-3 GAME"<<endl;
	rev3.printBoard();

	cout << "REVERSI-4 GAME"<<endl;
	rev4.printBoard();

	cout << "REVERSI-5 GAME"<<endl;
	rev5.printBoard();

	cout <<endl<<endl;

	cout << "TOTAL NUMBER OF CELLS(REVERSI-1 + REVERSI-2 + REVERSI-3 + REVERSI-4 + REVERSI-5): "<<rev1.numberOfCell()<<endl;
	cout <<endl;
	cout << "TEST GAME ENDED !!! NOW LETS TEST playGame() function"<<endl;
	cout << "TEST GAME ENDED !!! NOW LETS TEST playGame() function"<<endl;
	cout <<endl;

	//REVERSI 2 GAME - (ASK GAME SIZE AND PLAY THEN COMPUTER PLAY ETC...
	rev2.playGame();

	cout <<endl;

	cout << "REVERSI-1 GAME"<<endl;
	rev1.printBoard();

	cout <<endl<<endl;


	cout << "REVERSI-2 GAME"<<endl;
	rev2.printBoard();


	cout << endl;

	if ( rev1.isBetter(rev2) == true)
		cout << "REVERSI-1 GAME IS BETTER THAN REVERSI-2 "<<endl;
	else
		cout << "REVERSI-2 GAME IS BETTER THAN REVERSI-1 "<<endl;

	cout <<endl;

	cout << "REVERSI-3 GAME"<<endl;
	rev3.printBoard();

	cout << "REVERSI-4 GAME"<<endl;
	rev4.printBoard();

	cout << "REVERSI-5 GAME"<<endl;
	rev5.printBoard();

	cout << "TOTAL NUMBER OF CELLS(REVERSI-1 + REVERSI-2 + REVERSI-3 + REVERSI-4 + REVERSI-5): "<<rev1.numberOfCell()<<endl;

	return 0;
}