#include <iostream>
#include <cgicc/CgiDefs.h>
#include <cgicc/Cgicc.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>
#include "router.h"
#include "controller/page_controller.h"
#include "controller/tab_controller.h"

namespace pheide {

void Router::Route() {
	cgicc::Cgicc cgi;

	std::string page_id = cgi("page_id");
	std::string tab_id = cgi("tab_id");

	if (page_id.empty()) {

		// Show default page
		pheide::controller::PageController page_controller;
		page_controller.show();
	} else {

		if (tab_id.empty()) {

			// Show default tab for this page
			pheide::controller::PageController page_controller;
			page_controller.show(std::stoi(page_id));
		} else {

			// Show specific tab
			pheide::controller::TabController tab_controller;
			tab_controller.show(std::stoi(page_id), std::stoi(tab_id));
		}
	}
}

} // namespace pheide
