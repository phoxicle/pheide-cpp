#include <iostream>
#include <memory>
#include <cgicc/CgiDefs.h>
#include <cgicc/Cgicc.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>
#include "router.h"
#include "controller/factory.h"
#include "controller/base_controller.h"
#include "controller/page_controller.h"
#include "controller/tab_controller.h"
#include "controller/authenticator.h"

namespace pheide {

void Router::route() {
	cgicc::Cgicc cgi;

	// Parameters
	std::string controller_name = cgi("controller");
	std::string action = cgi("action");
	std::string page_id = cgi("page_id");
	std::string tab_id = cgi("tab_id");
	std::string username = cgi("username");
	std::string password = cgi("password");

	// Get cookies and check authentication
	controller::Authenticator authenticator;
	std::string cookie_value;
	cgicc::const_cookie_iterator cci;
	const cgicc::CgiEnvironment& env = cgi.getEnvironment();
	for( cci = env.getCookieList().begin(); cci != env.getCookieList().end(); ++cci ) {
		if (cci->getName() == authenticator.COOKIE_NAME) {
			authenticator.authenticate(cci->getValue());
		}
	}

	std::map<std::string,std::string> params = {
		{"page_id", page_id},
		{"tab_id", tab_id},
		{"username", username},
		{"password", password},
	};

	// Default is Page::show
	if (controller_name.empty()) {
		controller_name = "page";
		action = "show";
	}

	// Call action
	controller::Factory factory;
	std::unique_ptr<controller::BaseController> c_ptr(nullptr);
	c_ptr.reset(factory.get(controller_name));
	c_ptr->doAction(action, params, authenticator.isAuthenticated());
}

} // namespace pheide
