#pragma comment(lib, "libmySQL.lib")
#pragma comment(lib, "ws2_32.lib")

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <my_global.h>
#include <mysql.h>

using namespace std;

int main(int argc, char** argv) {
	string str_query;
	string input_stuff;
	int stuff_cnt;

	MYSQL* conn;
	MYSQL_RES* res;
	MYSQL_ROW row;
	int num_fields;

	char* server = "localhost";
	char* user = "root";
	char* password = "mirim2"; //root���� ��й�ȣ
	char* database = "procpluse"; //005������ ������ �����ͺ��̽�
	int port = 3306;

	conn = mysql_init(NULL);

	if (!mysql_real_connect(conn, server, user, password, database, port, NULL, 0)) {
		fprintf(stderr, "%s ", mysql_error(conn));
		exit(1);
	}

	cout << "��ǰ�� �����ּ��� : ";
	cin >> input_stuff;

	cout << "��ǰ�� ������ �����ּ��� : ";
	cin >> stuff_cnt;

	//������ ������ �˻��ϱ� ���� ��ɾ� ����
	str_query = "select cost from suff where name='";
	str_query += input_stuff;
	str_query += "'";

	//fruit ���̺� ��� �ڷ� �˻�
	if (mysql_query(conn, str_query.c_str())) {
		fprintf(stderr, "%s ", mysql_error(conn));
		exit(1);
	}

	//�� ���� ���� ��� �� ���
	res = mysql_use_result(conn);
	num_fields = mysql_num_fields(res);
	row = mysql_fetch_row(res);
	//�����ͺ��̽� �˻� ��(row)�� ������ ������ �� ������ ����Ѵ�.
	printf("�� ���� : %d ", atoi(row[0]) * stuff_cnt);
	/* close connection */
	mysql_close(conn);


	mysql_close(conn);
}