#ifndef PHEIDE_CONTROLLER_PAGE_CONTROLLER_H_
#define PHEIDE_CONTROLLER_PAGE_CONTROLLER_H_

#include "base_controller.h"

namespace pheide {
namespace controller {

class PageController : public BaseController {
 public:
	void doAction(std::string, std::map<std::string,std::string>);
	void show();
	void show(int);
};

} // namespace controller
} // namespace pheide

#endif // PHEIDE_CONTROLLER_PAGE_CONTROLLER_H_

