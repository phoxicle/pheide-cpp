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

	std::map<std::string,std::string> where {
		{"uid", std::to_string(tab_id)},
		{"pageid", std::to_string(page_id)}
	};

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

} // namespace repository
} // namespace pheide




