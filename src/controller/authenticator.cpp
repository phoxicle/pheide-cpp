#include <string>
#include <stdexcept>
#include "authenticator.h"

namespace pheide {
namespace controller {

const std::string Authenticator::COOKIE_NAME = "user";

void Authenticator::authenticate(const std::string& cookie_val) {
	if (cookie_val == "mycookie") {
		is_authenticated = true;
	} else {
		// TODO Logger
		is_authenticated = false;
	}
}

std::string Authenticator::exchangeForCookie(const std::string& username, const std::string& password) {
	if (username == "test" && password == "test") {
		is_authenticated = true;

		// Top-secret auth cookie
		std::string cookie_value = "mycookie";
		return COOKIE_NAME + "=" + cookie_value;
	} else {
		throw std::invalid_argument("Wrong username/password");
	}
}

bool Authenticator::isAuthenticated() {
	return is_authenticated;
}

} // namespace controller
} // namespace pheide
