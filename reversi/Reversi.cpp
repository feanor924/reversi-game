/*
 * Reversi.cpp
 *
 *  Created on: Nov 6, 2015
 *      Author: caner
 */

#include "Reversi.h"
#include <cstdlib>
#include <fstream>

Reversi::Reversi() :currentX(10), currentY(10){
	fillVector();
}

Reversi::Reversi(int gameSize){
	currentX=gameSize;
	currentY=gameSize;
	fillVector();
}

Reversi::Reversi(int currentx,int currenty) :currentX(currentx), currentY(currenty)
{				}

void Reversi::setCurrentX(int X){
	currentX=X;
}

void Reversi::setCurrentY(int Y){
	currentY=Y;
}

int Reversi::checkLives(int coory,int coorx,char character)const{

	for (int i=0;i<gameCells.size();++i){
		for (int y=0; y<gameCells[i].size(); ++y){
			if ( gameCells[i][y].getCoorX() == coorx && gameCells[i][y].getCoorY() == coory ){
				if ( gameCells[i][y].getCellType() == character )
					return 1;
				else
					return 0;
			}

		}
	}
	return -1;
}

void Reversi::printBoard()const{

	char str[25]={'a','b','c','d','e','f','g','h','i','j','k',
	'l','m','n','o','p','r','s','t','u','v','y','z'};

	cout << " " << " "<<" ";
	for (int i=0; i<getCurrentX();++i){
		cout << str[i];
		cout << " ";
	}
	cout <<endl;
	for ( int i=0; i<getCurrentY(); ++i){
		cout <<i+1;
		cout << " ";
		if ( i+1 < 10 )
			cout << " ";
		for (int j=0; j<getCurrentX(); ++j){
			if ( checkLives(i,j,'X') == 1 )
				cout << "X ";
			else if ( checkLives (i,j,'O') == 1)
				cout << "O ";
			else if ( checkLives (i,j,'.') == -1)
				cout << ". ";
		}
		cout <<endl;
	}
}

void Reversi::readFromFile(char *fileName){

	ifstream source;
	source.open(fileName);
	char line;
	char ctype;
	int rowc=0,columnc=0;
	vector <Cell> v1;
	Cell c1;
	while ( source.eof() == false  ){
		source.get(line);
		source.get(ctype);
		if ( line == 'O'){
			c1.setCoorX(columnc);
			c1.setCoorY(rowc);
			c1.setCellType('O');
			v1.push_back(c1);
		}
		if ( line == 'X'){
			c1.setCoorX(columnc);
			c1.setCoorY(rowc);
			c1.setCellType('X');
			v1.push_back(c1);
		}
		++columnc;
		if ( ctype == '\n'){
			++rowc;
			columnc=0;
		}
	}

	if ( gameCells[0].size() != 0)
		gameCells[0].clear();

	gameCells.push_back(v1);
	setCurrentX(rowc+1);
	setCurrentY(rowc+1);

	source.close();
}

void Reversi::writetoFile(char *fileName)const{

	ofstream output;
	output.open(fileName);

	for ( int i=0; i<getCurrentY(); ++i){
		for (int j=0; j<getCurrentX(); ++j){
			if ( checkLives(i,j,'X') == 1 && getCurrentX()-1 != j  )
				output <<"X ";
			else if (checkLives(i,j,'X') == 1 && getCurrentX()-1 == j )
				output <<"X";
			if ( checkLives (i,j,'O') == 1 && getCurrentX()-1 != j  )
				output <<"O ";
			else if (checkLives(i,j,'O') == 1 && getCurrentX()-1 == j )
				output <<"O";
			if ( checkLives (i,j,'.') == -1  && getCurrentX()-1 != j)
				output <<". ";
			else if (checkLives(i,j,'.') == -1 && getCurrentX()-1 == j )
				output <<".";
		}
		if ( i != getCurrentY()-1)
			output <<"\n";
	}

	output.close();
}

void Reversi::fillVector(){

	vector <Cell> v1;
	Cell c1;

	gameCells.clear();

	for (int i=0;i<getCurrentY();++i){
		for (int j=0;j<getCurrentX();++j){
			if ( i == getCurrentY()/2-1 && j == getCurrentX()/2-1  ){
				++numberofcell;
				c1.setCoorX(j);
				c1.setCoorY(i);
				c1.setCellType('X');
				v1.push_back(c1);
			}
			else if ( i == getCurrentY()/2-1 && (j == (getCurrentX()/2)) ){
				++numberofcell;
				c1.setCoorX(j);
				c1.setCoorY(i);
				c1.setCellType('O');
				v1.push_back(c1);
			}
			else if ( ( i == (getCurrentY()/2) ) && j == getCurrentX()/2-1 ){
				++numberofcell;
				c1.setCoorX(j);
				c1.setCoorY(i);
				c1.setCellType('O');
				v1.push_back(c1);
			}
			else if ( ( i == (getCurrentY()/2) ) && j == ( (getCurrentX()/2) ) ){
				++numberofcell;
				c1.setCoorX(j);
				c1.setCoorY(i);
				c1.setCellType('X');
				v1.push_back(c1);
			}
		}
	}
	gameCells.push_back(v1);
}

void Reversi::makeMove(int coor_y, int coor_x, char ch1){

	Cell c1;
	c1.setCoorY(coor_y);
	c1.setCoorX(coor_x);
	c1.setCellType(ch1);
	gameCells[0].push_back(c1);
}

int Reversi::isLegal(int row,int column,int *arr1,char ch,int *size1, int *num){

	int i,j,k=0,p=0;
	int num1=0,num2=0;
	int colc;
	if ( row < 0 || column < 0 || row > getCurrentY() || column > getCurrentX() )
		return -1;
	//DOWN(1)
	if (p==1)
		p=0;
	num1=num2;
	for (i=row+1;i<getCurrentY();++i){
		if ( i == row+1 && checkLives(i,column,ch) == 1 )
			break;
		else if ( checkLives(i,column,ch) == -1 )
			break;
		else if ( checkLives(i,column,ch) == 0){
			for (int z=i;z<getCurrentY();++z){
				++num1;
				if ( checkLives(z,column,ch) == -1 ){
					p=0;
					break;
				}
				if ( checkLives(z,column,ch) == 1 ){
					p=1;
					break;
				}
			}
		}
		if ( p==0){
			num1=num2;
			break;
		}
		else if (p==1){
			num2=num1;
			arr1[k]=1;
			++k;
			break;
		}
	}
	//UP
	if (p==1)
		p=0;
	for (i=row-1;i>0;--i){
		if ( i == row-1 && checkLives(i,column,ch) == 1 )
			break;
		else if ( checkLives(i,column,ch) == -1  )
			break;
		else if ( checkLives(i,column,ch) == 0){
			for(int z=i;z>=0;--z){
				++num1;
				if ( checkLives(z,column,ch) == -1 ){
					p=0;
					break;
				}
				if ( checkLives(z,column,ch) == 1 ){
					p=1;
					break;
				}
			}
			if ( p==0){
				num1=num2;
				break;
			}
			else if (p==1){
				num2=num1;
				arr1[k]=2;
				++k;
				break;
			}
		}
	}
	//RIGHT(3)
	if (p==1)
		p=0;
	for (i=column+1;i<getCurrentX();++i){
		if ( i == column+1 && checkLives(row,i,ch) == 1 )
			break;
		else if ( checkLives(row,i,ch) == -1  )
			break;
		else if ( checkLives(row,i,ch) == 0 ){
			for (int z=i;z<getCurrentX();++z){
				++num1;
				if ( checkLives(row,z,ch) == -1 ){
					p=0;
					break;
				}
				if ( checkLives(row,z,ch) == 1 ){
					p=1;
					break;
				}
			}
			if ( p==0){
				num1=num2;
				break;
			}
			else if (p==1){
				num2=num1;
				arr1[k]=3;
				++k;
				break;
			}
		}
	}

	//LEFT(4)
	if (p==1)
		p=0;
	for (i=column-1;i>0;--i){
		if ( i == column-1 && checkLives(row,i,ch) == 1 )
			break;
		else if ( checkLives(row,i,ch) == -1  )
			break;
		else if ( checkLives(row,i,ch) == 0){
			for (int z=i;z>=0;--z){
				++num1;
				if ( checkLives(row,z,ch) == -1 ){
					p=0;
					break;
				}
				if ( checkLives(row,z,ch) == 1 ){
					p=1;
					break;
				}
			}
			if ( p==0){
				num1=num2;
				break;
			}
			else if (p==1){
				num2=num1;
				arr1[k]=4;
				++k;
				break;
			}
		}
	}
	//SAG UST(5)
	if (p==1)
		p=0;
	j=column+1;
	for (i=row-1;i>0;--i){
		if ( i == row-1 && j == column+1 && checkLives(i,j,ch) == 1 )
			break;
		else if ( checkLives(i,j,ch) == -1  )
			break;
		if ( j<getCurrentX() ){
			colc=j;
			if ( checkLives(i,colc,ch) == 0 ){
				for (int z=i;z>0;--z){
					++num1;
					if ( checkLives(z,colc,ch) == -1 ){
						p=0;
						break;
					}
					if ( checkLives(z,colc,ch) == 1 ){
						p=1;
						break;
					}
					++colc;
				}
			}
			if ( p==0){
				num1=num2;
				break;
			}
			else if (p==1){
				num2=num1;
				arr1[k]=5;
				++k;
				break;
			}
		}
		++j;
	}
	//SAG ALT(6)
	if (p==1)
		p=0;
	j=column+1;
	for (i=row+1;i<getCurrentY();++i){
		if ( i == row+1 && j == column+1 && checkLives(i,j,ch) == 1 )
			break;
		if ( checkLives(i,j,ch) == -1  )
			break;
		if ( j<getCurrentX()){
			colc=j;
			if ( checkLives(i,colc,ch) == 0 ){
				for (int z=i;z<getCurrentY();++z){
					++num1;
					if ( checkLives(z,colc,ch) == -1 ){
						p=0;
						break;
					}
					if ( checkLives(z,colc,ch) == 1 ){
						p=1;
						break;
					}
					++colc;
				}
			}
			if ( p==0){
				num1=num2;
				break;
			}
			else if (p==1){
				num2=num1;
				arr1[k]=6;
				++k;
				break;
			}
		}
		++j;
	}
	//SOL UST(7)
	if (p==1)
		p=0;
	j=column-1;
	for (i=row-1;i>0;--i){
		if ( i == row-1 && j == column-1 && checkLives(i,j,ch) == 1 )
			break;
		if ( checkLives(i,j,ch) == -1  )
			break;
		if ( j>=0 ){
			colc=j;
			if ( checkLives(i,colc,ch) == 0 ){
				for (int z=i;z>0;--z){
					++num1;
					if ( checkLives(z,colc,ch) == -1){
						p=0;
					break;
					}
					if ( checkLives(z,colc,ch) == 1 ){
						p=1;
					}
					--colc;
				}
			}
			if ( p==0){
				num1=num2;
				break;
			}
			else if (p==1){
				num2=num1;
				arr1[k]=7;
				++k;
				break;
			}
		}
		--j;
	}

	//SOL ASAGI(8)
	if (p==1)
		p=0;
	j=column-1;
	for (i=row+1;i<getCurrentY();++i){
		if ( i == row+1 && j == column+1 && checkLives(i,j,ch) == 1 )
			break;
		if ( checkLives(i,j,ch) == -1  )
			break;
		if ( j>=0 ){
			colc=j;
			if ( checkLives(i,colc,ch) == 0 ){
				for (int z=i;z<getCurrentX();++z){
					++num1;
					if ( checkLives(z,colc,ch) == -1 ){
						p=0;
						break;
					}
					if ( checkLives(z,colc,ch) == 1 ){
						p=1;
						break;
					}
					--colc;
				}
			}
			if ( p==0){
				num1=num2;
				break;
			}
			else if (p==1){
				num2=num1;
				arr1[k]=8;
				++k;
				break;
			}
		}
		--j;
	}

	if ( num2 > 0 ){
		*num=num2;
	}
	if ( k > 0 ){
		*size1=k;
		return 1;
	}
	*size1=0;
	return -1;
}

void Reversi::yutma(int row, int column, int *arr1, char ch, int size1){

	int i=0,j,k=0;

	for (k=0;k<size1;++k){
		if ( arr1[k] == 1){
			for (i=row+1;i<getCurrentY();++i){
				if ( checkLives(i,column,ch) != 1){
					makeMove2(i,column,ch);
				}
				else
					break;
			}
		}
		else if ( arr1[k] == 2 ){
			for (i=row-1;i>0;--i){
				if ( checkLives(i,column,ch) != 1)
					makeMove2(i,column,ch);
				else
					break;
			}
		}
		else if ( arr1[k] == 3 ){
			for (i=column+1;i<getCurrentY();++i){
				if ( checkLives(row,i,ch) != 1)
					makeMove2(row,i,ch);
				else
					break;
			}
		}
		else if ( arr1[k] == 4 ){
			for (i=column-1;i>0;--i){
				if ( checkLives(row,i,ch) != 1)
					makeMove2(row,i,ch);
				else
					break;
			}
		}
		else if ( arr1[k] == 5 ){
			j=column+1;
			for (i=row-1;i>0;--i){
				if ( checkLives(i,j,ch) != 1 )
					makeMove2(i,j,ch);
				else
					break;
				++j;
			}
		}
		else if ( arr1[k] == 6 ){
			j=column+1;
			for (i=row+1;i<getCurrentX();++i){
				if ( checkLives(i,j,ch) != 1)
					makeMove2(i,j,ch);
				else
					break;
				++j;
			}
		}
		else if ( arr1[k] == 7 ){
			j=column-1;
			for (i=row-1;i>0;--i){
				if ( checkLives(i,j,ch) != 1)
					makeMove2(i,j,ch);
				else
					break;
				--j;
			}
		}
		else if ( arr1[k] == 8 ){
			j=column-1;
			for (i=row+1;i<getCurrentX();++i){
				if ( checkLives(i,j,ch) != 1)
					makeMove2(i,j,ch);
				else
					break;
				--j;
			}
		}
	}
}

int Reversi::whoWon(int userCell,int compCell)const{
	if ( userCell > compCell)
		return 1;
	return -1;
}

bool Reversi::isFilled()const{
	for (int i=0;i<getCurrentY();++i){
		for (int j=0;j<getCurrentX(); ++j){
			if ( checkLives(i,j,'.') == -1)
				return false;
		}
	}
	return true;
}

bool Reversi::isFinished(int *arr1,char ch){

	int size1=0,counter=0,number;
	for (int i=0;i<getCurrentY();++i){
		for (int j=0;j<getCurrentX(); ++j){
			if ( checkLives(i,j,'.') == -1 && isLegal(i,j,arr1,ch,&size1,&number) == 1 )
				++counter;
		}
	}
	if ( counter > 0 )
		return false;
	return true;
}

int Reversi::compMove(int *row, int *col,int *arr1,int *arr2){

	int size1=0;
	int size=0,number1=0,number2=0;

	for (int i=0;i<getCurrentY();++i){
		for (int j=0;j<getCurrentX();++j){
			if ( checkLives(i,j,'.') == -1){
				if ( isLegal(i,j,arr1,'X',&size1,&number1) == 1 ){
					if ( number1 > number2){
						*row=i;
						*col=j;
						for (int k=0;k<size1;++k)
							arr2[k]=arr1[k];
						number2=number1;
						size=size1;
					}
				}
			}
		}
	}

	if ( number2 == 0)
		return -1;

	makeMove(*row,*col,'X');

	cout <<"Computer Played: "<<"ROW:"<<*row+1<<"  "<<"COLUMN: "<<*col+1<<endl;

	yutma(*row,*col,arr2,'X',size);

	return 1;
}

void Reversi::playGame(){

	int arr1[10],size1,arr2[10];
	int row,col=0,ert=0,num=0,rowc;
	char column;
	int userCell=0,compCell=0,legal;

	char str1[25]={'A','B','C','D','E','F','G','H','I',	'J','K','L',
	'M','N','O','P','R','S','T','U','V','Y','Z'};

	cout <<"Enter the size"<<endl;
	cin >>rowc;

	while ( rowc%2 != 0 || rowc < 4 || rowc > 20){
		cout <<"ILLEGAL SIZE TRY AGAIN"<<endl;
		cout <<"Enter the size"<<endl;
		cin >>rowc;
	}

	setCurrentX(rowc);
	setCurrentY(rowc);
	fillVector();

	int * ro = new int;
	int * co = new int;
	cout <<"--------INITIAL BOARD--------"<<endl<<endl;
	printBoard();

	cout <<endl;

	cin >>row>>column;
	--row;

	for (int j=0;j<30;++j){
		if ( str1[j] == column)
			break;
		++col;
	}
	while ( checkLives(row,col,'X') == 1 || checkLives(row,col,'O') == 1){
		cout <<"ILLEGAL MOVE, TRY AGAIN"<<endl;
		col=0;
		cin >>row>>column;
		--row;
		for (int j=0;j<30;++j){
			if ( str1[j] == column)
				break;
			++col;
		}
	}

	while ( isFilled() == false && isFinished(arr1,'O')  == false
		&& isFinished(arr1,'X')  == false  ){
		legal = isLegal(row,col,arr1,'O',&size1,&num);
		if ( legal == 1 ){
			++numberofcell;
			makeMove(row,col,'O');
			yutma(row,col,arr1,'O',size1);
			cout <<"--------USER--------"<<endl<<endl;
			printBoard();
			if ( compMove(ro,co,arr1,arr2) == 1){
				cout <<"--------COMPUTER--------"<<endl<<endl;
				printBoard();
			}
			else
				ert=1;
		}
		else if( legal == -1){
			++ert;
			cout <<"ILLEGAL MOVE, TRY AGAIN"<<endl;
			col=0;
			cin >>row>>column;
			--row;
			for (int j=0;j<30;++j){
				if ( str1[j] == column)
					break;
				++col;
			}
			while ( checkLives(row,col,'X') == 1 || checkLives(row,col,'O') == 1){
				cout <<"ILLEGAL MOVE, TRY AGAIN"<<endl;
				col=0;
				cin >>row>>column;
				--row;
				for (int j=0;j<30;++j){
					if ( str1[j] == column)
						break;
					++col;
				}
			}
		}
		if ( isFilled() != false || isFinished(arr1,'O')  != false ||
		isFinished(arr1,'X')  != false){
				break;
		}
		if ( ert == 0){
			col=0;
			cin >>row>>column;
			--row;
			for (int j=0;j<30;++j){
				if ( str1[j] == column)
					break;
				++col;
			}
		}
		ert=0;
	}
	numberOfCells(&compCell,&userCell);

	if ( whoWon(userCell,compCell) == 1)
		cout <<endl<< "-----USER WIN"<<endl<<"-----USER CELL:"<<userCell<<endl<<"-----COMPUTER CELL:"<<compCell<<endl;
	else
		cout <<endl<<"-----COMPUTER WIN"<<endl<<"-----USER CELL:"<<userCell<<endl<<"-----COMPUTER CELL:"<<compCell<<endl;

	delete ro;
	delete co;
}

void Reversi::makeMove2(int coor_y,int coor_x,char ch1){

	for (int i=0;i<gameCells.size();++i){
		for (int y=0; y<gameCells[i].size(); ++y){
			if ( gameCells[i][y].getCoorX() == coor_x && gameCells[i][y].getCoorY() == coor_y )
				gameCells[i][y].setCellType(ch1);
		}
	}
}

void Reversi::numberOfCells(int *comp,int *user){

	for (int i=0;i<getCurrentY();++i){
		for (int j=0;j<getCurrentX(); ++j){
			if ( checkLives(i,j,'X') == 1)
				++*comp;
			else if ( checkLives(i,j,'O') == 1 )
				++*user;
		}
	}

}


bool Reversi::isBetter(const Reversi &game1)const{

	int count=0,count1=0;

	for (int i=0;i<gameCells.size();++i){
		for (int y=0; y<gameCells[i].size(); ++y){
			if ( gameCells[i][y].getCellType() == 'O')
				++count;
		}
	}

	for (int i=0;i<game1.gameCells.size();++i){
		for (int y=0; y<game1.gameCells[i].size(); ++y){
			if ( game1.gameCells[i][y].getCellType() == 'O')
				++count1;
		}
	}

	if ( count > count1)
		return true;

	return false;

}

void Reversi::play(const Cell &c1){

	int num=0,legal,size1=0;
	int arr1[10];
	int userCell=0,compCell=0;

	if ( isFilled() == false && isFinished(arr1,'O')  == false
		&& isFinished(arr1,'X')  == false  ){
		legal = isLegal(c1.getCoorY(),c1.getCoorX(),arr1,'O',&size1,&num);
		if ( legal == 1 ){
			++numberofcell;
			makeMove(c1.getCoorY(),c1.getCoorX(),'O');
			yutma(c1.getCoorY(),c1.getCoorX(),arr1,'O',size1);
			cout <<"--------USER--------"<<endl<<endl;
			printBoard();
		}
		else if( legal == -1)
			cout <<"ILLEGAL MOVE, TRY AGAIN"<<endl;

	}
	if ( isFilled() != false || isFinished(arr1,'O')  != false ||
		isFinished(arr1,'X')  != false){
		numberOfCells(&compCell,&userCell);
		if ( whoWon(userCell,compCell) == 1)
			cout <<endl<< "-----USER WIN"<<endl<<"-----USER CELL:"<<userCell<<endl<<"-----COMPUTER CELL:"<<compCell<<endl;
		else
			cout <<endl<<"-----COMPUTER WIN"<<endl<<"-----USER CELL:"<<userCell<<endl<<"-----COMPUTER CELL:"<<compCell<<endl;
	}

}

void Reversi::play(){

	int * ro = new int;
	int * co = new int;
	int arr1[10],arr2[10];
	int userCell=0,compCell=0;

	if ( compMove(ro,co,arr1,arr2) == 1){
		++numberofcell;
		cout <<"--------COMPUTER--------"<<endl<<endl;
		printBoard();
	}
	else
		cout << "There is no to move"<<endl;

	if ( isFilled() != false || isFinished(arr1,'O')  != false ||
		isFinished(arr1,'X')  != false){
		numberOfCells(&compCell,&userCell);
		if ( whoWon(userCell,compCell) == 1)
			cout <<endl<< "-----USER WIN"<<endl<<"-----USER CELL:"<<userCell<<endl<<"-----COMPUTER CELL:"<<compCell<<endl;
		else
			cout <<endl<<"-----COMPUTER WIN"<<endl<<"-----USER CELL:"<<userCell<<endl<<"-----COMPUTER CELL:"<<compCell<<endl;
	}

}

int Reversi::numberOfCell(){

	return numberofcell;
}

