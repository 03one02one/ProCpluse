#pragma comment(lib, "libmySQL.lib")
#pragma comment(lib, "ws2_32.lib")

#include <ctime>
#include <fstream>
#include <iomanip>
#include <my_global.h>
#include <mysql.h>
#include <iostream>
#include <string>

using namespace std;

MYSQL_ROW row;
MYSQL_RES* res;

MYSQL* DBconn() {
	MYSQL* conn;
	conn = mysql_init(0);
	mysql_options(conn, MYSQL_SET_CHARSET_NAME, "euckr");
	mysql_options(conn, MYSQL_INIT_COMMAND, "SET NAMES euckr");
	conn = mysql_real_connect(conn, "localhost", "root", "mirim2", "customer", 3306, NULL, 0);

	return conn;

}

class Customer {
private:
	int number;
public:
	Customer(int number) {
		this->number;
	}
	void ShowPayment() {
		cout << "결제를 진행하겠습니다." << endl;
	}
};

class Member : Customer {
private:
	int point;
public:
	Member(int number, int point) : Customer(number) {
		this->point;
	}

	void ShowPayment() {
		cout << point << "포인트가 적립되셨습니다." << endl;
	}
};

class nMembers : Customer {};

void main(MYSQL* conn) {
	system("cls");

	int member_n;
	cout << "회원넘버가 어떻게 되십니까?";
	cin >> member_n;

	string query = "select * from proc where number='" + member_n + "'";
	const char* c = query.c_str();
	int qstate = mysql_query(conn, c);

	if (!qstate) {
		res = mysql_store_result(conn);
		row = mysql_fetch_row(res);

		Member suyeon(atoi(row[2]), )
}



