#ifndef PHEIDE_MODEL_PAGE_ADAPTER_H_
#define PHEIDE_MODEL_PAGE_ADAPTER_H_

#include <string>
#include <iostream>
#include <mysql.h>
#include "page_model.h"

namespace pheide {
namespace model {

struct PageModelAdapter : PageModel {
	PageModelAdapter(MYSQL_ROW row) {
		title = row[0] ?: "";
		header_id = row[1] ?: "";
		is_default = row[2] ? true : false;
		uid = std::stoi(row[3]);
	}
};

} // namespace model
} // namespace pheide

#endif // PHEIDE_MODEL_PAGE_MODEL_H_
