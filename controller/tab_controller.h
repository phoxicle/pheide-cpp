#ifndef PHEIDE_CONTROLLER_TAB_CONTROLLER_H_
#define PHEIDE_CONTROLLER_TAB_CONTROLLER_H_

#include <map>
#include "../repository/tab_repository.h"
#include "../model/tab_model.h"
#include "../view/renderer.h"

namespace pheide {
namespace controller {

class TabController {
 public:
	void show(int, int);
};

} // namespace controller
} // namespace pheide

#endif // PHEIDE_CONTROLLER_TAB_CONTROLLER_H_

