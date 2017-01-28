#ifndef PHEIDE_MODEL_TAB_MODEL_H_
#define PHEIDE_MODEL_TAB_MODEL_H_

#include <string>
#include "tab_model.h"

namespace pheide {
namespace model {

struct TabModel {
	int uid;
	int page_id;
	std::string title;
	std::string aside;
	std::string content;
};

} // namespace model
} // namespace pheide

#endif // PHEIDE_MODEL_TAB_MODEL_H_
