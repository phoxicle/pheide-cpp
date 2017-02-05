#include <string>
#include <exception>
#include <mysql.h>
#include "dal.h"

namespace pheide {
namespace repository {

MYSQL_RES* DAL::query(const std::string& q) {
	// Connect
	MYSQL mysql;
	MYSQL *connection = mysql_init(&mysql);
	// TODO use config file
	::mysql_real_connect(&mysql,"localhost","root","root","pheide",0,0,0);
	if (connection == NULL) {
		throw std::runtime_error(::mysql_error(&mysql));
	}

	int state = ::mysql_query(connection, q.c_str());
	if (state != 0) {
		throw std::runtime_error(mysql_error(connection));
	}

	MYSQL_RES *result = mysql_store_result(connection);

	return result;
}

MYSQL_ROW DAL::queryRow(const std::string& q) {
	MYSQL_RES* res = query(q);
	return ::mysql_fetch_row(res);
}

} // namespace repository
} // namespace pheide
