
#include"Maze.h"

int main() {
	string name;
	Maze test;
	int n1, n2;
	vector<Cell> info;
	cout << "Name of file?: ";
	cin >> name;
	test.loadMaze(name);
	test.printMaze();
	test.convertto2d();
	cout << test.getx() << endl;
	cout << test.gety() << endl;
}
