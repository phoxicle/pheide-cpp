#include <iostream>
#include <cgicc/CgiDefs.h>
#include <cgicc/Cgicc.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>
#include "router.h"
#include "controller/factory.h"
#include "controller/base_controller.h"
#include "controller/page_controller.h"
#include "controller/tab_controller.h"

namespace pheide {

void Router::Route() {
	cgicc::Cgicc cgi;

	// Parameters
	std::string controller_name = cgi("controller");
	std::string action = cgi("action");
	std::string page_id = cgi("page_id");
	std::string tab_id = cgi("tab_id");

	std::map<std::string,std::string> params = {
		{"page_id", page_id},
		{"tab_id", tab_id}
	};

	// Default is Page::show
	if (controller_name.empty()) {
		controller_name = "page";
		action = "show";
	}

	// Call action
	controller::Factory factory;
	controller::BaseController* controller = factory.get(controller_name);
	controller->doAction(action, params);
	// TODO use smart pointers.
	delete controller;
}

} // namespace pheide
