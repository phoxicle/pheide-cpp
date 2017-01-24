#ifndef PHEIDE_ABSTRACT_REPOSITORY_H_
#define PHEIDE_ABSTRACT_REPOSITORY_H_

#include <iostream>
#include <string>
#include <exception>
#include <mysql.h>

namespace pheide {
namespace repository {

class AbstractRepository {
 public:
	void connect();
	std::string selectByTitle(std::string);
 private:
	MYSQL_RES *result;
	MYSQL_ROW row;
	MYSQL *connection, mysql;

	int state;
};

} // namespace repository
} // namespace pheide

#endif // PHEIDE_ABSTRACT_REPOSITORY_H_

