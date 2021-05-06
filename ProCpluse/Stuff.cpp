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
	char* password = "mirim2"; //root계정 비밀번호
	char* database = "procpluse"; //005강에서 생성한 데이터베이스
	int port = 3306;

	conn = mysql_init(NULL);

	if (!mysql_real_connect(conn, server, user, password, database, port, NULL, 0)) {
		fprintf(stderr, "%s ", mysql_error(conn));
		exit(1);
	}

	cout << "상품을 적어주세요 : ";
	cin >> input_stuff;

	cout << "상품의 개수를 적어주세요 : ";
	cin >> stuff_cnt;

	//과일의 가격을 검색하기 위한 명령어 생성
	str_query = "select cost from suff where name='";
	str_query += input_stuff;
	str_query += "'";

	//fruit 테이블 모든 자료 검색
	if (mysql_query(conn, str_query.c_str())) {
		fprintf(stderr, "%s ", mysql_error(conn));
		exit(1);
	}

	//총 구매 가격 계산 후 출력
	res = mysql_use_result(conn);
	num_fields = mysql_num_fields(res);
	row = mysql_fetch_row(res);
	//데이터베이스 검색 값(row)과 수량의 곱으로 총 가격을 계산한다.
	printf("총 가격 : %d ", atoi(row[0]) * stuff_cnt);
	/* close connection */
	mysql_close(conn);


	mysql_close(conn);
}