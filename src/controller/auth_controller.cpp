#include <map>
#include "auth_controller.h"
#include "page_controller.h"
#include "authenticator.h"
#include "../view/renderer.h"
#include "../view/link_builder.h"

namespace pheide {
namespace controller {

void AuthController::doAction(std::string action, std::map<std::string,std::string> params, bool is_authenticated) {
	if (action == "login") {
		login();
	} else if (action == "logout") {
		logout();
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

void AuthController::logout() {
	view::Renderer renderer;

	Authenticator authenticator;
	std::string additional_headers = "Set-Cookie:" + authenticator.COOKIE_NAME + "=invalid;\r\n";
	std::cout << renderer.renderPage("auth/logout.html", {}, additional_headers);
}

void AuthController::authenticate(std::string username, std::string password) {
	view::Renderer renderer;

	try {
		Authenticator authenticator;
		std::string cookie = authenticator.exchangeForCookie(username, password);
		std::string additional_headers = "Set-Cookie:" + cookie + ";\r\n";
		std::cout << renderer.renderPage("auth/success.html", {}, additional_headers);
	} catch (const std::invalid_argument& e) {
		std::cout << renderer.renderPage("auth/failure.html", {});
	}
}

} // namespace controller
} // namespace pheide

