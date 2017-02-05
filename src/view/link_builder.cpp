#include <string>
#include "link_builder.h"

namespace pheide {
namespace view {

std::string LinkBuilder::build() {
	std::string s = "?";

	if (!action.empty()) {
		s += "action=" + action;
	}

	if (page_id > 0) {
		s += "&page_id=" + std::to_string(page_id);
	}

	if (tab_id > 0) {
		s += "&tab_id=" + std::to_string(tab_id);
	}

	return s;
}

} // namespace view
} // namespace pheide
