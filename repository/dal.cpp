#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <mysql.h>
#include <sstream>
#include "dal.h"

namespace pheide {
namespace repository {

MYSQL_RES* DAL::select(const std::string& table, const std::vector<std::string>& fields, const std::map<std::string,std::string>& where, const int limit, const std::vector<std::string>& sorting) {

	std::string q = "SELECT " + join(fields, ",") + " FROM " + table;

	if (!where.empty()) {
		q += " WHERE " + join(join(where, "="), " AND ");
	}

	if (sorting.size() > 0) {
		q += " ORDER BY " + join(sorting, ",");
	}

	if (limit > 0) {
		q += " LIMIT " + std::to_string(limit);
	}

	return query(q);
}

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

std::string DAL::join(const std::vector<std::string>& v, const std::string& separator) {
	std::stringstream ret;
	std::string delimiter = "";
	for (auto iter = v.begin(); iter != v.end(); ++iter) {
		ret << delimiter << *iter;
		delimiter = separator;
	}
	return ret.str();
}

std::vector<std::string> DAL::join(const std::map<std::string, std::string>& m, const std::string& separator) {
	std::vector<std::string> ret;
	for (auto const& ent : m) {
		ret.push_back(ent.first + separator + ent.second);
	}
	return ret;
}

} // namespace repository
} // namespace pheide
