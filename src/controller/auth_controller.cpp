#include <map>
#include "auth_controller.h"
#include "page_controller.h"
#include "../view/renderer.h"
#include "../view/link_builder.h"

namespace pheide {
namespace controller {

void AuthController::doAction(std::string action, std::map<std::string,std::string> params) {
	if (action == "login") {
		login();
	} else if (action == "authenticate") {
		authenticate(params["username"], params["password"]);
	}
}

void AuthController::login() {
	view::Renderer renderer;

	// TODO use typedef for params
	view::LinkBuilder link_builder;
	std::map<std::string,std::string> params = {
		{ "form_action", link_builder.withController("auth").withAction("authenticate").build() }
	};

	std::cout << renderer.renderPage("auth/login.html", params);
}

void AuthController::authenticate(std::string username, std::string password) {
	view::Renderer renderer;

	// TODO security
	if (username == "test" && password == "pass") {
		// Set top-secret auth cookie
		std::string cookie_value = "mycookie";
		std::string additional_headers = "Set-Cookie:user=" + cookie_value + ";\r\n";

		std::cout << renderer.renderPage("auth/success.html", {}, additional_headers);
	} else {
		std::cout << renderer.renderPage("auth/failure.html", {});
	}
}

} // namespace controller
} // namespace pheide

