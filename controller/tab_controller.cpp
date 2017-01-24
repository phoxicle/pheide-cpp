#include <iostream>
#include "tab_controller.h"
#include "../repository/tab_repository.h"
#include "../model/tab_model.h"

namespace pheide {
namespace controller {

void TabController::show(int page_id, int tab_id) {
	// use repo to get a Tab model
	pheide::repository::TabRepository tab_repository;
	pheide::model::TabModel tab_model = tab_repository.selectById(page_id, tab_id);

	// use a view to show the Tab model
	std::cout << tab_model.title << tab_model.content << std::endl;

}

} // namespace controller
} // namespace pheide

