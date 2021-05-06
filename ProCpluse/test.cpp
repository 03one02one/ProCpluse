#pragma comment(lib, "libmySQL.lib")
#pragma comment(lib, "ws2_32.lib")

#include <my_global.h>
#include <mysql.h>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	MYSQL* conn;
	char* server = "localhost";
	char* user = "root";
	char* password = "mirim2"; //root���� ��й�ȣ
	char* database = NULL; //005������ ������ �����ͺ��̽�
	int port = 3306;
	conn = mysql_init(NULL);
	/* Connect to SQL */
	if (!mysql_real_connect(conn, server,
		user, password, database, port, NULL, 0)) {
		fprintf(stderr, "%s ", mysql_error(conn));
		exit(1);
	}
	/* send SQL query */
	if (mysql_query(conn, "create database test2")) {
		fprintf(stderr, "%s ", mysql_error(conn));
		exit(1);
	}
	/* close connection */
	mysql_close(conn);
