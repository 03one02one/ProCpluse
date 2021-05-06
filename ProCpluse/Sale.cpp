#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void main() {
	ofstream fout("sale.txt");

	fout << "                      ";
	fout << "--------------이 달의 할인--------------" << endl;
	fout << "                      ";
	fout << "|		 			     |" << endl;
	fout << "                      ";
	fout << "|    	   유제품 전 품목    	     |" << endl;
	fout << "                      ";
	fout << "|			                     |" << endl;
	fout << "                      ";
	fout << "|      	       8%!! 할인             |" << endl;
	fout << "                      ";
	fout << "|			                     |" << endl;
	fout << "                      ";
	fout << "|    지금 당장 ProCpluse에서 만나요.   |" << endl;
	fout << "                      ";
	fout << "-----------------------------------------" << endl;
}