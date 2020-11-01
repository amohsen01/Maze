#pragma once
#include <iostream>
#include<fstream>
#include <vector>
using namespace std;

class Cell
{
private: bool above, below, left, right;
	   char data;

public:
	Cell(bool a = 0, bool b = 0, bool l = 0, bool f = 0, char d = ' ') {
		above = a;
		below = b;
		left = l;
		right = f;
		data = d;
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
	void setData(char x) { data = x; }
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
	void printAbove() {

		(above) ? printf("---+") : printf("   +");

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
	}
};
void loadMaze(string nameofFile, vector<Cell>& x) {
	ifstream in;
	in.open(nameofFile);
	if (!in)
	{
		cout << "error or file not found!" << endl;
		exit(1);
	}
	else {
		char str1[100], str2[100], str3[100], strbuf[2] = { '1','b' };
		in.getline(str1, 100);
		in.getline(str2, 100);
		in.getline(str3, 100);
		int line = 1, cell = 1;
		Cell buff;
		while (!in.eof()) {
			int i = 0, j = 0, k = 1, t;
			while (i < strlen(str1) - 1) {
				if (str1[i] == '+') i++; // new cell
				if (str1[i] == '-') buff.setAbove(1);
				else if (str1[i] == ' ') buff.setBelow(0);
				// else error
				i = i + 3; // wall above
				if (str2[j] == '|') buff.setLeft(1);
				else if (str2[j] == ' ') buff.setLeft(false);
				// else error
				// left wall
				j = j + 2;
				if (str2[j] != ' ') buff.setData(str2[j]);
				else buff.setData(' ');
				j = j + 2;
				if (str2[j] == '|') buff.setRight(1);
				else if (str2[j] == ' ') buff.setRight(0);
				// else error
				if (str3[k] == ' ') buff.setBelow(0);
				else if (str3[k] == '-') buff.setBelow(1);
				// else error
				k = k + 4; // wall below
				x.push_back(buff);
				buff.Reset();
			}
			strcpy_s(str1, str3);
			in.getline(str2, 100);
			in.getline(str3, 100);
			line++;
		}
	}

}
void setStart(int p1, int p2, vector<Cell>& x) {
	p1 = p1--;
	x[((5 * p1) + p2) - 1].setData('S');

}
void setGoal(int p1, int p2, vector<Cell>& x) {
	p1 = p1--;
	x[((5 * p1) + p2) - 1].setData('G');

}
void Printline(vector<Cell> x, int start = 0) {

	for (int i = start; i < start + 4; i++) {
		if (i - start != 0 && x[i - 1].checkLeft()) {
			x[i].printData(); x[i].printRight();
		}
		else if (i - start != 0 && x[i - 1].checkRight()) {
			x[i].printData(); x[i].printRight();
		}
		else { x[i].printLeft(); x[i].printData(); x[i].printRight(); }
	}
	(x[start + 4].checkData()) ? printf("%c ", x[start + 4].getData()) : printf("  ");
	(x[start + 4].checkRight()) ? printf(" |\n") : printf(" \n");
	printf("+");
	for (int i = start; i < start + 4; i++) {
		x[i].printBelow();

	}
	(x[start + 4].checkBelow()) ? printf("---+\n") : printf("   +\n");
}
void PrintMaze(vector<Cell> x) {
	int n = 0;
	printf("+");
	for (int i = n; i < n + 4; i++) {
		x[i].printAbove();

	}
	(x[n + 4].checkAbove()) ? printf("---+\n") : printf("   +\n");
	while (n <= 20) {
		Printline(x, n);
		n = n + 5;
	}
}