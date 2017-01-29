#include <iostream>
#include <mysql.h>
#include <map>
#include "tab_repository.h"
#include "dal.h"
#include "../model/tab_model.h"
#include "../model/tab_model_adapter.h"

namespace pheide {
namespace repository {

pheide::model::TabModel TabRepository::selectById(int page_id, int tab_id) {

	std::map<std::string,std::string> where {
		{"uid", std::to_string(tab_id)},
		{"pageid", std::to_string(page_id)}
	};

	DAL dal;
	auto result = dal.selectOne("tab", {"*"}, where);
	pheide::model::TabModel tab_model = pheide::model::TabModelAdapter(result);
	return tab_model;
}

} // namespace repository
} // namespace pheide




