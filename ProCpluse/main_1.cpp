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
	cout << "�ݾ����� ��ſ� proCplus ��� ��ſ� proCplus ��ſ� ���� proCplus�� \n" << endl;
	cout << "                      ";
	cout << "����ʿ�. proCpuls�� ���Ű��� �������� ȯ���մϴ�." << endl;
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
	cout << "��ǰ�� �����ּ��� : ";
	cin >> input_stuff;

	cout << "\n" << "                      ";
	cout << "��ǰ�� �´� �� Ȯ�����ּ���. \n\n";
	cout << "                      " << input_stuff << "\n" << endl;
	cout << "                      ";
	cout << "������ y, Ʋ���� n�� �����ּ��� : ";
	cin >> order;

	if (order == "y") {
		cout << "                      ";
		cout << "��ǰ�� ������ �����ּ��� : ";
		cin >> stuff_cnt;
		cout << "\n";
	}
	else if (order == "n") {
		while (true) {
			cout << "                      ";
			cout << "��ǰ�� �����ּ��� : ";
			cin >> input_stuff;

			cout << "\n" << "                      ";
			cout << "��ǰ�� �´� �� Ȯ�����ּ���. \n\n";
			cout << "                      " << input_stuff << "\n" << endl;
			cout << "                      ";
			cout << "������ y, Ʋ���� n�� �����ּ��� : ";
			cin >> order;

			if (order == "y") {
				break;
			}
		}
		cout << "                      ";
		cout << "��ǰ�� ������ �����ּ��� : ";
		cin >> stuff_cnt;
		cout << "\n";
	}
	else {
		cout << "\n" << "                      ";
		cout << "�ùٸ� ���� �Է����ּ���." << endl;

		cout << "                      ";
		cout << "������ y, Ʋ���� n�� �����ּ��� : ";
		cin >> order;

		if (order == "y") {
			cout << "                      ";
			cout << "��ǰ�� ������ �����ּ��� : ";
			cin >> stuff_cnt;
			cout << "\n";
		}
		else if (order == "n") {
			while (true) {
				cout << "                      ";
				cout << "��ǰ�� �����ּ��� : ";
				cin >> input_stuff;

				cout << "\n" << "                      ";
				cout << "��ǰ�� �´� �� Ȯ�����ּ���. \n\n";
				cout << "                      " << input_stuff << "\n" << endl;
				cout << "                      ";
				cout << "������ y, Ʋ���� n�� �����ּ��� : ";
				cin >> order;

				if (order == "y") {
					break;
				}
			}
			cout << "                      ";
			cout << "��ǰ�� ������ �����ּ��� : ";
			cin >> stuff_cnt;
			cout << "\n";
		}
	}

	return 0;

}

void sale(MYSQL* conn) {
	ifstream fin("sale.txt");

	string buffer;
	string division = "����ǰ";

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
			cout << "�� ���� ������ ���� �Ǿ� " << row[2] << "���� " << atoi(row[2]) * stuff_cnt * 0.9 << "�� ���εǼ̽��ϴ�." << endl;
		}
		else {
			cout << "                      ";
			cout << "�� ������ " << atoi(row[2]) * stuff_cnt << "�� �Դϴ�" << endl;
		}

	}
	else {
		cout << "��� ����" << mysql_errno(conn) << endl;
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
		cout << "...������..." << endl;
		Sleep(3000);
		cout << "\n\n";
		cout << "			              ";
		cout << "������ ���������� �Ϸ�Ǿ����ϴ�." << endl;
	}
};

class Membership : public Customer {
private:
	string number;
public:
	void PayMent(MYSQL* conn) {
		cout << "                      ";
		cout << "ȸ���ѹ��� ��� �ǽʴϱ�? : ";
		cin >> number;

		string query = "select * from membership where number='" + number + "'";
		const char* c = query.c_str();
		int qstate = mysql_query(conn, c);
		if (!qstate) {
			res = mysql_store_result(conn);
			row = mysql_fetch_row(res);
			cout << "                      ";
			cout << atoi(row[2]) + 30 << "����Ʈ�� �����Ǽ̽��ϴ�." << endl;
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
	cout << "������ �����Ͻðڽ��ϱ�? (y/n) : ";
	cin >> order;

	if (order == "y") {
		cout << "\n";
		cout << "                      ";
		cout << "ȸ���̽ʴϱ�? (y/n) : ";
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
		cout << "������ ��ҵǾ����ϴ�." << endl;
	}
}

void Bye() {
	cout << "                      ";
	cout << "proCpuls�� �̿����ּż� �����մϴ�." << endl;
}
void main(void) {
	MYSQL* conn = DBconn();
	hello();
	Stuff();
	sale(conn);
	PayMent();
	Bye();
}
