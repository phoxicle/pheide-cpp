#include <iostream>
#include "router.h"
#include "repository/abstract_repository.h"
#include "controller/tab_controller.h"

namespace pheide {

void Router::Route() {
	std::cout << "hi" << std::endl;

	// TODO Use proper type
	int page_id = 10;
	int tab_id = 20;

	//pheide::repository::AbstractRepository repository;
	//std::cout << "title is: " << repository.selectByTitle("aoeu") << std::endl;

	// TabController should show pageid/tabid.
	pheide::controller::TabController tab_controller;
	tab_controller.show(page_id, tab_id);
}

}
