#ifndef PHEIDE_CONTROLLER_FACTORY_H_
#define PHEIDE_CONTROLLER_FACTORY_H_

#include <iostream>
#include "base_controller.h"

namespace pheide {
namespace controller {

class Factory {
 public:
	BaseController* get(std::string);
};

} // namespace controller
} // namespace pheide

#endif // PHEIDE_CONTROLLER_FACTORY_H_

