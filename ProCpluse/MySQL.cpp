#include <my_global.h>
#include <winsock2.h>
#include <mysql.h>
#pragma comment(lib, "libmysql.lib")

void main() {
	printf("MySQL client Version : %s)n", mysql_get_client_info());
}