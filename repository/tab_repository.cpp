#include <iostream>
#include <mysql.h>
#include "tab_repository.h"
#include "dal.h"
#include "../model/tab_model.h"

namespace pheide {
namespace repository {

pheide::model::TabModel TabRepository::selectById(int page_id, int tab_id) {
	DAL dal;
	MYSQL_RES* result = dal.select("tab", std::vector<std::string>(), 1, std::vector<std::string>());
	// TODO use adaptor
	MYSQL_ROW row = ::mysql_fetch_row(result);
	/*
	while ( ( row=::mysql_fetch_row(result)) != NULL )
	{
		std::cout << "got row 0: " << row[0] << std::endl;
	}
	*/
	//std::string fields[] = {"uid", "pageid", "title", "aside", "content", "sorting", "type"};
	pheide::model::TabModel tab_model {tab_id, page_id, row[2], row[3], row[4]};

	//pheide::model::TabModel tab_model("a title", "some content");
	return tab_model;
}

} // namespace repository
} // namespace pheide




