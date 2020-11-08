#pragma once
#include <iostream>
#include<fstream>
#include <vector>
using namespace std;

class Cell
{
private: bool above, below, left, right, visited;
	int x, y;
	Cell* neighbors[4] = { 0,0,0,0 }, * prev;
		char status;
	   char data;

public:
	Cell(bool a = 0, bool b = 0, bool l = 0, bool f = 0, char d = ' ',int xc=0,int yc=0, Cell*p=0  ) {
		above = a;
		below = b;
		left = l;
		right = f;
		data = d;
		x = xc;
		y = yc;
		prev = p;

	}
	void setAbove(bool x) {
		above = x;
	}
	void setBelow(bool x) {
		below = x;
	}
	void setLeft(bool x) {
		left = x;
	}
	void setRight(bool x) {
		right = x;
	}
	void setData(char x) { 
		data = x; 
	}
	bool checkRight() {
		return right;
	}
	bool checkLeft() {
		return left;
	}
	bool checkData() {
		if (data == ' ') return false;
		else return true;
	}
	bool checkBelow() {
		return below;
	}
	bool checkAbove() {
		return above;
	}
	bool checkVisit() {
		return visited;
	}
	void printAbove() {
		(above) ? printf("---+") : printf("   +");
	}
	void setVisited(bool v) { 
		visited = v;
	}
	void setY(int h) {
		y = h;
	}
	void setX(int w) {
		x = w;
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	void setneighborup(Cell* up) {
		neighbors[0] = up; 
	} 
	void setneighborright(Cell* right) {
		neighbors[1] = right;
	}
	void setneighbordown(Cell* down) {
		neighbors[2] = down; 
	}
	void setneighborleft(Cell* left) {
		neighbors[3] = left; 
	}
	void setprev(Cell* p) {
		prev = p; 
	}
	Cell** getneighbors() { 
		return neighbors; 
	}
	Cell* getprev() { 
		return prev; 
	}
	char getData() {
		return data;
	}
	void printBelow() {
		(below) ? printf("---+") : printf("   +");
	}
	void printLeft() {
		(left) ? printf("|") : printf(" ");
	}
	void printRight() {
		(right) ? printf("|") : printf(" ");
	}
	void printData() {
		(data != ' ') ? printf(" %c ", data) : printf("   ");
	}
	void Reset() {
		data = ' ';
		above = below = left = right = 0;
		x = y = 0;
		prev = nullptr;
		for (int i = 0; i < 4; i++) {
			neighbors[i] = 0;
		}
	}
};


