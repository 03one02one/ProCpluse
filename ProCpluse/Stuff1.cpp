#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void main() {
	char name[20];
	char cost[20];

	ofstream fout("stuff.txt");

	for (int i = 0; i < 12; i++) {
		cout << "������ �Է��Ͻÿ� : ";
		cin >> name;

		cout << "������ �Է��Ͻÿ� : ";
		cin >> cost;

		fout << name << setw(10) << cost << endl;

		cout << name << setw(10) << cost << endl;

		cout << endl;
	}
}