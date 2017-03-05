#include <map>
#include "page_controller.h"
#include "../repository/page_repository.h"
#include "../repository/tab_repository.h"
#include "../controller/tab_controller.h"
#include "../model/page_model.h"
#include "../model/tab_model.h"

namespace pheide {
namespace controller {

void PageController::doAction(std::string action, std::map<std::string,std::string> params) {
	if (action == "show") {
		if (params["page_id"].empty()) {
			show();
		} else {
			show(std::stoi(params["page_id"]));
		}
	}
}


void PageController::show() {
	repository::PageRepository page_repository;
	model::PageModel page_model = page_repository.selectByDefault();

	show(page_model.uid);
}

void PageController::show(int page_id) {
	repository::TabRepository tab_repository;
	model::TabModel tab_model = tab_repository.selectByDefault(page_id);

	TabController tab_controller;
	tab_controller.show(page_id, tab_model.uid);
}

} // namespace controller
} // namespace pheide

