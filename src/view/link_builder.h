#ifndef PHEIDE_VIEW_LINK_BUILDER_H_
#define PHEIDE_VIEW_LINK_BUILDER_H_

#include <string>

namespace pheide {
namespace view {

class LinkBuilder {
 public:
	LinkBuilder& withAction(const std::string& s) {
		action = s;
		return *this;
	}

	LinkBuilder& withPageId(const int s) {
		page_id = s;
		return *this;
	}

	LinkBuilder& withTabId(const int s) {
		tab_id = s;
		return *this;
	}

	std::string build();
 private:
	std::string action;
	int page_id;
	int tab_id;
};

} // namespace view
} // namespace pheide

#endif // PHEIDE_VIEW_LINK_BUILDER_H_

