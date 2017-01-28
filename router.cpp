#include <iostream>
#include "router.h"
#include "controller/tab_controller.h"

namespace pheide {

void Router::Route() {

	int page_id = 10;
	int tab_id = 20;

	// TabController should show pageid/tabid.
	pheide::controller::TabController tab_controller;
	tab_controller.show(page_id, tab_id);
}

}
