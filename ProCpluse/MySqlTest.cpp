#include <iostream>
#include <winsock2.h>
#include <mysql.h>
using namespace std;

#pragma comment(lib, "libmysql.lib")

const char* host = "localhost";
const char* user = "root";
const char* pw = "mirim2";
const char* db = "bbs";

int main(int argc, TCHAR* argv[]) {
	MYSQL* connection = NULL;
	MYSQL conn;
	MYSQL_RES* sql_result;
	MYSQL_ROW sql_row;

	if (mysql_init(&conn) == NULL) {
		printf("mysql_init() error!");
	}

	connection = mysql_real_connect(&conn, host, user, pw, db, 3306, (const char*)NULL, 0);
	if (connection == NULL) {
		cout << "에러 : " << mysql_errno(&conn) << mysql_error(&conn) << "\n" << endl;
		return 1;
	}
	else {
		printf("연결 성공\n");

		if (mysql_select_db(&conn, db)) {
			cout << "에러 : " << mysql_errno(&conn) << mysql_error(&conn) << "\n" << endl;
			return 1;
		}

	}

	return 0;
}
