#ifndef PHEIDE_CONTROLLER_AUTH_CONTROLLER_H_
#define PHEIDE_CONTROLLER_AUTH_CONTROLLER_H_

#include <iostream>
#include "base_controller.h"

namespace pheide {
namespace controller {

class AuthController : public BaseController {
 public:
	void doAction(std::string, std::map<std::string,std::string>, bool);
	void login();
	void logout();
	void authenticate(std::string,std::string);
};

} // namespace controller
} // namespace pheide

#endif // PHEIDE_CONTROLLER_AUTH_CONTROLLER_H_

