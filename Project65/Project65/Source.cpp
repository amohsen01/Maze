
#include"Cell.h"

int main() {
	string name;
	int n1, n2;
	vector<Cell> info;
	cout << "Name of file?: ";
	cin >> name;
	loadMaze(name,info);
	PrintMaze(info);
	cout << "Where is the start: ";
	cin >> n1>>n2;
	setStart(n1, n2, info);
	cout << "Where is the Goal: ";
	cin >> n1 >> n2;
	setGoal(n1, n2, info);
	PrintMaze(info);
}
