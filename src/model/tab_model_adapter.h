#ifndef PHEIDE_MODEL_TAB_ADAPTER_H_
#define PHEIDE_MODEL_TAB_ADAPTER_H_

#include <string>
#include <mysql.h>
#include "tab_model.h"

namespace pheide {
namespace model {

struct TabModelAdapter : TabModel {
	TabModelAdapter(MYSQL_ROW row) {
		uid = std::stoi(row[0]);
		page_id = std::stoi(row[1]);
		title = row[2] ?: "";
		aside = row[3] ?: "";
		content = row[4] ?: "";
	}
};

} // namespace model
} // namespace pheide

#endif // PHEIDE_MODEL_TAB_MODEL_H_
