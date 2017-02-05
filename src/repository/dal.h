#ifndef PHEIDE_REPOSITORY_DAL_H_
#define PHEIDE_REPOSITORY_DAL_H_

#include <string>
#include <exception>
#include <mysql.h>

namespace pheide {
namespace repository {

class DAL {
 public:
	MYSQL_RES* query(const std::string&);
	MYSQL_ROW queryRow(const std::string&);
};

} // namespace repository
} // namespace pheide

#endif // PHEIDE_REPOSITORY_DAL_H_

