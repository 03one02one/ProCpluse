#pragma comment(lib, "libmySQL.lib")
#pragma comment(lib, "ws2_32.lib")

#include <ctime>
#include <fstream>
#include <iomanip>
#include <my_global.h>
#include <mysql.h>
#include <iostream>
#include <string>
#include<windows.h>
using namespace std;

string str_query;
string input_stuff;
int stuff_cnt;

MYSQL_ROW row;
MYSQL_RES* res;


void hello() {
	cout << "\n\n\n";
	cout << "                      ";
	cout << "♬언제나 즐거운 proCplus 어서와 즐거운 proCplus 즐거운 쇼핑 proCplus♬ \n" << endl;
	cout << "                      ";
	cout << "어서오십오. proCpuls에 오신것을 진심으로 환영합니다." << endl;
}

MYSQL* DBconn() {
	MYSQL* conn;
	conn = mysql_init(0);
	mysql_options(conn, MYSQL_SET_CHARSET_NAME, "euckr");
	mysql_options(conn, MYSQL_INIT_COMMAND, "SET NAMES euckr");
	conn = mysql_real_connect(conn, "localhost", "root", "mirim2", "stuff", 3306, NULL, 0);

	return conn;

}
int Stuff() {

	int num_fields;

	string order;

	cout << "                      ";
	cout << "상품을 적어주세요 : ";
	cin >> input_stuff;

	cout << "\n" << "                      ";
	cout << "상품이 맞는 지 확인해주세요. \n\n";
	cout << "                      " << input_stuff << "\n" << endl;
	cout << "                      ";
	cout << "맞으면 y, 틀리면 n를 적어주세요 : ";
	cin >> order;

	if (order == "y") {
		cout << "                      ";
		cout << "상품의 개수를 적어주세요 : ";
		cin >> stuff_cnt;
		cout << "\n";
	}
	else if (order == "n") {
		while (true) {
			cout << "                      ";
			cout << "상품을 적어주세요 : ";
			cin >> input_stuff;

			cout << "\n" << "                      ";
			cout << "상품이 맞는 지 확인해주세요. \n\n";
			cout << "                      " << input_stuff << "\n" << endl;
			cout << "                      ";
			cout << "맞으면 y, 틀리면 n를 적어주세요 : ";
			cin >> order;

			if (order == "y") {
				break;
			}
		}
		cout << "                      ";
		cout << "상품의 개수를 적어주세요 : ";
		cin >> stuff_cnt;
		cout << "\n";
	}
	else {
		cout << "\n" << "                      ";
		cout << "올바른 값을 입력해주세요." << endl;

		cout << "                      ";
		cout << "맞으면 y, 틀리면 n를 적어주세요 : ";
		cin >> order;

		if (order == "y") {
			cout << "                      ";
			cout << "상품의 개수를 적어주세요 : ";
			cin >> stuff_cnt;
			cout << "\n";
		}
		else if (order == "n") {
			while (true) {
				cout << "                      ";
				cout << "상품을 적어주세요 : ";
				cin >> input_stuff;

				cout << "\n" << "                      ";
				cout << "상품이 맞는 지 확인해주세요. \n\n";
				cout << "                      " << input_stuff << "\n" << endl;
				cout << "                      ";
				cout << "맞으면 y, 틀리면 n를 적어주세요 : ";
				cin >> order;

				if (order == "y") {
					break;
				}
			}
			cout << "                      ";
			cout << "상품의 개수를 적어주세요 : ";
			cin >> stuff_cnt;
			cout << "\n";
		}
	}

	return 0;

}

void sale(MYSQL* conn) {
	ifstream fin("sale.txt");

	string buffer;
	string division = "유제품";

	while (fin.peek() != EOF) {
		getline(fin, buffer);
		cout << buffer << endl;
	}

	string query = "select * from proc where name='" + input_stuff + "'";
	const char* c = query.c_str();
	int qstate = mysql_query(conn, c);

	if (!qstate) {
		res = mysql_store_result(conn);
		row = mysql_fetch_row(res);

		if (row[4] == division) {
			cout << "                      ";
			cout << "이 달의 할인이 적용 되어 " << row[2] << "에서 " << atoi(row[2]) * stuff_cnt * 0.9 << "원 할인되셨습니다." << endl;
		}
		else {
			cout << "                      ";
			cout << "총 가격은 " << atoi(row[2]) * stuff_cnt << "원 입니다" << endl;
		}

	}
	else {
		cout << "디비 에러" << mysql_errno(conn) << endl;
	}

}

MYSQL* Member() {
	MYSQL* conn;
	conn = mysql_init(0);
	mysql_options(conn, MYSQL_SET_CHARSET_NAME, "euckr");
	mysql_options(conn, MYSQL_INIT_COMMAND, "SET NAMES euckr");
	conn = mysql_real_connect(conn, "localhost", "root", "mirim2", "customer", 3306, NULL, 0);

	return conn;
}

class Customer {
public:
	void ShowPayMent() {
		Sleep(3000);
		system("cls");
		cout << "\n\n\n";
		cout << "						 ";
		cout << "...결제중..." << endl;
		Sleep(3000);
		cout << "\n\n";
		cout << "			              ";
		cout << "결제가 정상적으로 완료되었습니다." << endl;
	}
};

class Membership : public Customer {
private:
	string number;
public:
	void PayMent(MYSQL* conn) {
		cout << "                      ";
		cout << "회원넘버가 어떻게 되십니까? : ";
		cin >> number;

		string query = "select * from membership where number='" + number + "'";
		const char* c = query.c_str();
		int qstate = mysql_query(conn, c);
		if (!qstate) {
			res = mysql_store_result(conn);
			row = mysql_fetch_row(res);
			cout << "                      ";
			cout << atoi(row[2]) + 30 << "포인트가 적립되셨습니다." << endl;
		}
	}
};

class nMember : public Customer {};

void PayMent() {
	MYSQL* conn_1 = Member();
	Membership m;
	nMember nm;
	string order;

	cout << "\n";
	cout << "                      ";
	cout << "결제를 진행하시겠습니까? (y/n) : ";
	cin >> order;

	if (order == "y") {
		cout << "\n";
		cout << "                      ";
		cout << "회원이십니까? (y/n) : ";
		cin >> order;
		if (order == "y") {
			m.PayMent(conn_1);
			m.ShowPayMent();
		}
		else if (order == "n") {
			nm.ShowPayMent();
		}
	}
	else if (order == "n") {
		cout << "                      ";
		cout << "결제가 취소되었습니다." << endl;
	}
}

void Bye() {
	cout << "                      ";
	cout << "proCpuls를 이용해주셔서 감사합니다." << endl;
}
void main(void) {
	MYSQL* conn = DBconn();
	hello();
	Stuff();
	sale(conn);
	PayMent();
	Bye();
}
