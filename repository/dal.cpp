#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <mysql.h>
#include "dal.h"

namespace pheide {
namespace repository {

MYSQL_RES* DAL::select(std::string table, std::vector<std::string> fields, int limit, std::vector<std::string> sorting) {

	std::string q = "SELECT * FROM tab";
	return query(q);
}

MYSQL_RES* DAL::query(std::string q) {
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

} // namespace repository
} // namespace pheide
