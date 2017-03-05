#include <iostream>
#include "factory.h"
#include "base_controller.h"
#include "page_controller.h"
#include "tab_controller.h"
#include "auth_controller.h"

namespace pheide {
namespace controller {

BaseController* Factory::get(std::string name) {
	BaseController* controller = NULL;
	if (name == "page") {
		controller = new PageController;
	} else if (name == "tab") {
		controller = new TabController;
	} else if (name == "auth") {
		controller = new AuthController;
	}

	return controller;
}

} // namespace controller
} // namespace pheide


