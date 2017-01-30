#include <iostream>
#include <mysql.h>
#include <map>
#include "tab_repository.h"
#include "dal.h"
#include "query_builder.h"
#include "../model/tab_model.h"
#include "../model/tab_model_adapter.h"

namespace pheide {
namespace repository {

pheide::model::TabModel TabRepository::selectById(int page_id, int tab_id) {

	QueryBuilder builder;
	DAL dal;
	auto result = dal.queryRow(builder
			.withTable("tab")
			.withFields({"*"})
			.withLimit(1)
			.withWhere({
					{"uid", std::to_string(tab_id)},
					{"pageid", std::to_string(page_id)}
				})
			.build());
	pheide::model::TabModel tab_model = pheide::model::TabModelAdapter(result);
	return tab_model;
}

std::vector<pheide::model::TabModel> TabRepository::selectByPageId(int page_id) {
	QueryBuilder builder;
	DAL dal;
	auto result = dal.query(builder
			.withTable("tab")
			.withFields({"*"})
			.withWhere({
					{"pageid", std::to_string(page_id)}
				})
			.withSorting({"sorting ASC"})
			.build());

	std::vector<pheide::model::TabModel> ret;
	MYSQL_ROW row;
	while ((row = ::mysql_fetch_row(result))) {
		ret.push_back(pheide::model::TabModelAdapter(row));
	}

	return ret;
}

} // namespace repository
} // namespace pheide




