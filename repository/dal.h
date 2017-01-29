#ifndef PHEIDE_REPOSITORY_DAL_H_
#define PHEIDE_REPOSITORY_DAL_H_

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <exception>
#include <mysql.h>

namespace pheide {
namespace repository {

class DAL {
 public:
	// TODO ues builder
	MYSQL_RES* select(const std::string&, const std::vector<std::string>&, const std::map<std::string,std::string>&, const int, const std::vector<std::string>&);
	MYSQL_RES* select(const std::string&, const std::vector<std::string>&, const std::map<std::string,std::string>&, const int);
	MYSQL_ROW selectOne(const std::string&, const std::vector<std::string>&, const std::map<std::string,std::string>&, const std::vector<std::string>&);
	MYSQL_ROW selectOne(const std::string&, const std::vector<std::string>&, const std::map<std::string,std::string>&);
 private:
	MYSQL_RES* query(const std::string&);
	std::string join(const std::vector<std::string>&, const std::string&);
	std::vector<std::string> join(const std::map<std::string,std::string>&, const std::string&);
};

} // namespace repository
} // namespace pheide

#endif // PHEIDE_REPOSITORY_DAL_H_

