#include <map>
#include "page_controller.h"
#include "../repository/page_repository.h"
#include "../repository/tab_repository.h"
#include "../controller/tab_controller.h"
#include "../model/page_model.h"
#include "../model/tab_model.h"

namespace pheide {
namespace controller {

void PageController::doAction(std::string action, std::map<std::string,std::string> params, bool is_authenticated) {
	if (action == "show") {
		if (params["page_id"].empty()) {
			show(is_authenticated);
		} else {
			show(std::stoi(params["page_id"]), is_authenticated);
		}
	}
}


void PageController::show(bool is_authenticated) {
	repository::PageRepository page_repository;
	model::PageModel page_model = page_repository.selectByDefault();

	show(page_model.uid, is_authenticated);
}

void PageController::show(int page_id, bool is_authenticated) {
	repository::TabRepository tab_repository;
	model::TabModel tab_model = tab_repository.selectByDefault(page_id);

	TabController tab_controller;
	tab_controller.show(page_id, tab_model.uid, is_authenticated);
}

} // namespace controller
} // namespace pheide

