/*
 * Cell.cpp
 *
 *  Created on: Nov 6, 2015
 *      Author: caner
 */

#include "Cell.h"

Cell::Cell() : coorX(0), coorY(0), cellType('.')
{ 						}

Cell::Cell(int coorx, int coory, char celltype) : coorX(coorx), coorY(coory), cellType(celltype)
{							}

void Cell::setCoorX(int x){
	coorX=x;
}

void Cell::setCoorY(int Y){
	coorY=Y;
}

void Cell::setCellType(char cell){
	cellType=cell;
}
