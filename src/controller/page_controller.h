#ifndef PHEIDE_CONTROLLER_PAGE_CONTROLLER_H_
#define PHEIDE_CONTROLLER_PAGE_CONTROLLER_H_

#include "base_controller.h"

namespace pheide {
namespace controller {

class PageController : public BaseController {
 public:
	void doAction(std::string, std::map<std::string,std::string>, bool);
	void show(bool);
	void show(int, bool);
};

} // namespace controller
} // namespace pheide

#endif // PHEIDE_CONTROLLER_PAGE_CONTROLLER_H_

