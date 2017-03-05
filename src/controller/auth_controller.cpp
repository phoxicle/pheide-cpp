#include <map>
#include "auth_controller.h"
#include "../view/renderer.h"

namespace pheide {
namespace controller {

void AuthController::doAction(std::string action, std::map<std::string,std::string> params) {
	if (action == "login") {
		login();
	}
}


void AuthController::login() {
	view::Renderer renderer;

	// use typedef for params
	std::map<std::string,std::string> params = {
		{ "form_action", "TODO"}
	};

	std::cout << renderer.renderPage("auth/login.html", params);
}


} // namespace controller
} // namespace pheide

