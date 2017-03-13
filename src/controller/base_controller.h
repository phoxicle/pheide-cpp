#ifndef PHEIDE_CONTROLLER_BASE_CONTROLLER_H_
#define PHEIDE_CONTROLLER_BASE_CONTROLLER_H_

#include <iostream>
#include <map>

namespace pheide {
namespace controller {

class BaseController {
 public:
	virtual void doAction(std::string, std::map<std::string,std::string>, bool) = 0;
	virtual ~BaseController(){};
};

} // namespace controller
} // namespace pheide

#endif // PHEIDE_CONTROLLER_BASE_CONTROLLER_H_

