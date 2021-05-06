#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void main() {
	char name[20];
	char cost[20];

	ofstream fout("stuff.txt");

	for (int i = 0; i < 12; i++) {
		cout << "물건을 입력하시오 : ";
		cin >> name;

		cout << "가격을 입력하시오 : ";
		cin >> cost;

		fout << name << setw(10) << cost << endl;

		cout << name << setw(10) << cost << endl;

		cout << endl;
	}
}