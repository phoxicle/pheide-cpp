#ifndef PHEIDE_CONTROLLER_TAB_CONTROLLER_H_
#define PHEIDE_CONTROLLER_TAB_CONTROLLER_H_

#include <map>
#include "base_controller.h"
#include "../repository/tab_repository.h"
#include "../model/tab_model.h"
#include "../view/renderer.h"

namespace pheide {
namespace controller {

class TabController : public BaseController {
 public:
	void doAction(std::string, std::map<std::string,std::string>);
	void show(int, int);
};

} // namespace controller
} // namespace pheide

#endif // PHEIDE_CONTROLLER_TAB_CONTROLLER_H_

