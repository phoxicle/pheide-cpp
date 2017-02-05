#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "query_builder.h"

namespace pheide {
namespace repository {

std::string QueryBuilder::build() {
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

	return q;
}

std::string QueryBuilder::join(const std::vector<std::string>& v, const std::string& separator) {
	std::stringstream ret;
	std::string delimiter = "";
	for (auto iter = v.begin(); iter != v.end(); ++iter) {
		ret << delimiter << *iter;
		delimiter = separator;
	}
	return ret.str();
}

std::vector<std::string> QueryBuilder::join(const std::map<std::string, std::string>& m, const std::string& separator) {
	std::vector<std::string> ret;
	for (auto const& ent : m) {
		ret.push_back(ent.first + separator + ent.second);
	}
	return ret;
}

} // namespace repository
} // namespace pheide
