#pragma once

namespace pheide {
namespace controller {

class Authenticator {
 public:
	static const std::string COOKIE_NAME;

	void authenticate(const std::string&);
	std::string exchangeForCookie(const std::string&, const std::string&);
	bool isAuthenticated();
 private:
	bool is_authenticated;
};


} // namespace controller
} // namespace pheide


