#ifndef PHEIDE_REPOSITORY_QUERY_BUILDER_H_
#define PHEIDE_REPOSITORY_QUERY_BUILDER_H_

#include <string>
#include <vector>
#include <map>

namespace pheide {
namespace repository {

class QueryBuilder {
 public:
	QueryBuilder& withTable(const std::string& t) {
		table = t;
		return *this;
	}

	QueryBuilder& withFields(const std::vector<std::string>& t) {
		fields = t;
		return *this;
	}

	QueryBuilder& withWhere(const std::map<std::string,std::string>& t) {
		where = t;
		return *this;
	}

	QueryBuilder& withLimit(const int t) {
		limit = t;
		return *this;
	}

	QueryBuilder& withSorting(const std::vector<std::string>& t) {
		sorting = t;
		return *this;
	}

	std::string build();
 private:
	std::string table;
	std::vector<std::string> fields;
	std::map<std::string,std::string> where;
	int limit;
	std::vector<std::string> sorting;

	std::string join(const std::vector<std::string>&, const std::string&);
	std::vector<std::string> join(const std::map<std::string,std::string>&, const std::string&);
};

} // namespace repository
} // namespace pheide

#endif // PHEIDE_REPOSITORY_QUERY_BUILDER_H_

