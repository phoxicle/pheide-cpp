#include <iostream>
#include <string>
#include <exception>
#include <mysql.h>
#include "abstract_repository.h"

namespace pheide {
namespace repository {

void AbstractRepository::connect() {
	mysql_init(&mysql);

	// TODO use config file
	connection = mysql_real_connect(&mysql,"localhost","root","root","pheide",0,0,0);
	if (connection == NULL) {
		throw std::runtime_error(mysql_error(&mysql));
	}
}

std::string AbstractRepository::selectByTitle(std::string title) {
	connect();

	state = mysql_query(connection, "SHOW TABLES");
	if (state != 0) {
		std::cout << mysql_error(connection) << std::endl;
	}
	result = mysql_store_result(connection);
	std::cout << "tables: " << mysql_num_rows(result) << std::endl;

	return "i am a title";
}

} // namespace repository
} // namespace pheide
