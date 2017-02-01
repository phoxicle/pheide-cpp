#include <iostream>
#include <cgicc/CgiDefs.h>
#include <cgicc/Cgicc.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>
#include "router.h"
#include "controller/tab_controller.h"

namespace pheide {

void Router::Route() {
	cgicc::Cgicc cgi;
	//int page_id = 10;
	//int tab_id = 20;

	std::string page_id = cgi("page_id");
	std::string tab_id = cgi("tab_id");

	// TabController should show pageid/tabid.
	pheide::controller::TabController tab_controller;
	tab_controller.show(std::stoi(page_id), std::stoi(tab_id));
}

} // namespace pheide
