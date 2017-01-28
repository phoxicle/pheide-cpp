#ifndef PHEIDE_REPOSITORY_DAL_H_
#define PHEIDE_REPOSITORY_DAL_H_

#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <mysql.h>

namespace pheide {
namespace repository {

class DAL {
 public:
	MYSQL_RES* select(std::string, std::vector<std::string>, int, std::vector<std::string>);
 private:
	MYSQL_RES* query(std::string);
};

} // namespace repository
} // namespace pheide

#endif // PHEIDE_REPOSITORY_DAL_H_

