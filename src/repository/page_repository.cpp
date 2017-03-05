#include <iostream>
#include <mysql.h>
#include <map>
#include "page_repository.h"
#include "dal.h"
#include "query_builder.h"
#include "../model/page_model.h"
#include "../model/page_model_adapter.h"

namespace pheide {
namespace repository {


std::vector<model::PageModel> PageRepository::selectAll() {
	QueryBuilder builder;
	DAL dal;

	auto result = dal.query(builder
			.withTable("page")
			.withFields({"*"})
			.build());

	std::vector<model::PageModel> pages;
	MYSQL_ROW row;
	while ((row = ::mysql_fetch_row(result))) {
		pages.push_back(model::PageModelAdapter(row));
	}

	return pages;
}

model::PageModel PageRepository::selectById(int id) {
	QueryBuilder builder;
	DAL dal;

	auto result = dal.queryRow(builder
			.withTable("page")
			.withFields({"*"})
			.withLimit(1)
			.withWhere({
					{"uid", std::to_string(id)}
				})
			.build());
	model::PageModel page_model = model::PageModelAdapter(result);

	return page_model;
}


model::PageModel PageRepository::selectByDefault() {
	QueryBuilder builder;
	DAL dal;

	auto result = dal.queryRow(builder
			.withTable("page")
			.withFields({"*"})
			.withLimit(1)
			.withWhere({
					{"isdefault", "1"}
				})
			.build());
	model::PageModel page_model = model::PageModelAdapter(result);

	return page_model;
}

} // namespace repository
} // namespace pheide




