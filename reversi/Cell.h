/*
 * Cell.h
 *
 *  Created on: Nov 6, 2015
 *      Author: caner
 */

#include <iostream>
#include <vector>
#ifndef CELL_H_
#define CELL_H_

using namespace std;


class Cell {
	public:

		Cell();
		Cell(int coorx, int coory,char celltype);
		void setCoorX(int x);
		void setCoorY(int y);
		void setCellType(char cell);
		inline int getCoorX()const	{	return coorX; }
		inline int getCoorY()const {   return coorY; }
		char getCellType()const {	return cellType; }

	private:
		int coorX;
		int coorY;
		char cellType;
};

#endif /* CELL_H_ */
