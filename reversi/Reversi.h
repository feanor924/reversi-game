/*
 * Reversi.h
 *
 *  Created on: Nov 6, 2015
 *      Author: caner
 */

#include <iostream>
#include <vector>
#include <stdio.h>
#include "Cell.h"
#ifndef REVERSI_H_
#define REVERSI_H_

using namespace std;

class Reversi {

	public:

		Reversi();
		Reversi(int gameSize);
		Reversi(int currentx, int currenty);
		void setCurrentX(int X);
		void setCurrentY(int Y);
		inline int getCurrentX()const { return currentX; 	};
		inline int getCurrentY()const { return currentY;	};
		void readFromFile(char *fileName);
		void writetoFile (char *fileName)const;
		void printBoard()const;
		void playGame();
		bool isBetter(const Reversi &game2)const;
		void play(const Cell &c1);
		void play();
		static int numberOfCell();

	private:

		int currentX;
		int currentY;
		vector< vector<Cell> > gameCells;
		static int numberofcell;
		int whoWon(int userCell,int compCell)const;
		bool isFilled()const;
		bool isFinished(int arr1[10],char ch);
		int checkLives(int coory,int coorx,char character)const;
		void makeMove(int coor_y,int coor_x, char ch1);
		void fillVector();
		void numberOfCells(int *comp,int *user);
		void yutma(int row,int column,int arr1[10],char ch,int size1);
		int isLegal(int row,int column,int *arr1,char ch,int *size1,int *num);
		int compMove(int *row,int *col,int arr1[10],int arr2[10]);
		void makeMove2(int coor_y,int coor_x, char ch1);
};

#endif /* REVERSI_H_ */
