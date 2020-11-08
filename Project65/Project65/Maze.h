#pragma once
#include<iostream>
#include <fstream>
#include<stack>
#include"Cell.h"
class Maze
{
public:
	Maze() {
	
	}
	int getx() {
		return row;
	}
	int gety() { return col; }
	void Printline(int start = 0) {

		for (int i = start; i < start + 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (i - start == 0) {
					maze[i][j].printLeft(); maze[i][j].printData(); maze[i][j].printRight();
				}
				else { maze[i][j].printData(); maze[i][j].printRight(); }
			}
		}
			cout << endl;
			printf("+");
			for (int i = start; i < start + 5; i++) {
				buffer[i].printBelow();
				
			}cout << endl;
		}
		
	
	void printMaze(){
		int n = 0;
		printf("+");
		for (int i = 0; i < 5; i++) {
			buffer[i].printAbove();
		}cout << endl;
		while (n <= 20) {
			Printline(n);
			n = n + 5;
		}
	}
	void convertto2d() {
		int maxX=buffer[0].getX(), maxY=buffer[0].getY();
		for (auto ym : buffer) {
			if (ym.getY() > maxY) {
				maxY = ym.getY();
			}
		}
		for (auto xm : buffer) {
			if (xm.getX() > maxX) {
				maxX = xm.getX();
			}
		}
		maxY++;
		row = maxX++;
		col = maxY++;
		
		for (int j = 0; j < row; j++) {
			for (int i = 0; i < col; i++) {
				buff2d.push_back(buffer[row*j+i]);
			}maze.push_back(buff2d);
		}
	}
	void loadMaze(string nameofFile) {
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
				int i = 0, j = 0, k = 1, t=0;
				while (i < strlen(str1) - 1) {
					if (str1[i] == '+') { i++; buff.setY(t++); }; // new cell
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
					buff.setX(line);
					buffer.push_back(buff);
					buff.Reset();
				}
				strcpy_s(str1, str3);
				in.getline(str2, 100);
				in.getline(str3, 100);
				line++;
			}
		}

	}
	//void DFS();
	//void BFS();
	//Cell* getStart();
	//Cell* getGoal();
	//void setStart(int x, int y)//it takes the x (i.e. col) and y(i.e. row) indices of the array (not the coordinates) as parameters
	//{
	//	
	//		if (t[(5*y)+x] == Goal) //if the cell is the Goal cell...
	//			cout << "Error: Same coordinates as the end point\n"; //prints an error
	//		else //else...
	//		{
	//			if (Start != nullptr) //if Start is not nullptr (i.e. There is a Start cell already)...
	//				Start->setStatus(' '); //sets the status to " ", in order to remove the 'S' from the old start point
	//			Start = &arr[y][x]; //Change the start cell to the address of the new cell
	//			Start->setStatus('S'); //Set the status of the new start position to 'S'
	//			cout << "The goal has been set successfully\n"; //prints success message
	//			this->display(); //Display the maze
	//		}
	//	
	//}

	//void setGoal(int x, int y);

private:
	
	vector<Cell> buffer,buff2d;
	int row, col; 
	vector<vector<Cell>> maze;
	Cell* Start, * Goal; 
};

void setStart(int p1, int p2, vector<Cell>& q) {
	p1 = p1--;
	q[((5 * p1) + p2) - 1].setData('S');

}
void setGoal(int p1, int p2, vector<Cell>& q) {
	p1 = p1--;
	q[((5 * p1) + p2) - 1].setData('G');

}
//void Success(Cell* current, Maze* m)
//{
//	stack<Cell*> tmp; //declare an empty stack
//	while (current != nullptr)
//	{
//		if (current != m->getStart() && current != m->getGoal()) //If the current cell is not the start or the goal cell, set its status to '@'
//			current->setData('@');
//		tmp.push(current); //push the current cell
//		current = current->getprev(); //advance the current cell to the previous cell
//	}
//
//	//printing the cell path in the reverse order (start to goal)
//	while (!tmp.empty())
//	{
//		cout << "(" << tmp.top()->getX() << "," << tmp.top()->getY() << ") ";
//		tmp.pop();
//	}
//	cout << endl;
//}

//void Maze::DFS()
//{
//	if (Start == nullptr) //check if the start is a nullptr
//	{
//		cout << "Error: Start point is not initialized\n"; //prints error
//		return;
//	}
//	else //else...
//	{
//		for (int i = 0; i < row; i++)
//		{
//			for (int j = 0; j < col; j++)
//			{
//				//Here, we are resetting each cell in the maze before applying the algorithim, in case a different algorithim was used before.
//				t[(5*i)+j].setVisited(false); //before applying the algorithim, set the visited member of each cell to false
//				if ((&t[(5 * i) + j] != Start) && (&t[(5 * i) + j] != Goal)) //and the status member of each cell (except the start and goal cell) to ' '
//					t[(5 * i) + j].setData(' ');
//			}
//		}
//		stack<Cell*> S;
//		S.push(Start);
//		S.top()->setprev(nullptr); 
//		Cell* current; 
//		while (!S.empty()) 
//		{
//			current = S.top(); 
//			S.pop();
//			if (current == Goal) 
//			{
//				Success(current, this); 
//				return; //return
//			}
//			if (!current->checkVisit()) //check if the current is not visited before, to avoid infinite loop
//			{
//				if (current != Start && current != Goal) //and if current is not the start and goal cell
//					current->setData('*'); //Set its status to '*'
//				current->setVisited(true); //set the current's visited member to true
//				Cell** neighbors = current->getneighbors(); //getting the neighbors array of the current cell
//				for (int i = 0; i < 4; i++) //loop through all the 4 neighbors
//				{
//					if (neighbors[i] != nullptr && !neighbors[i]->checkVisit()) //if the neighbor is not a nullptr and wasn't visited before
//					{
//						neighbors[i]->setprev(current); //set this neighbor's prev member to the current cell
//						S.push(neighbors[i]); //push the neighbor in the stack
//					}
//				}
//			}
//		}
//		cout << "Error: Goal was not found\n"; //if the function didn't return by now, then prints that no goal was found
//		return;
//	}
//}
