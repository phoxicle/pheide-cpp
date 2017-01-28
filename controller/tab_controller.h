#ifndef CONTROLLER_TAB_CONTROLLER_H_
#define CONTROLLER_TAB_CONTROLLER_H_

#include <map>
#include <fstream>
#include "../repository/tab_repository.h"
#include "../model/tab_model.h"

namespace pheide {
namespace controller {

class TabController {
 public:
	void show(int, int);
	void render(std::string, std::map<std::string, std::string>);
 private:
	void replace_vars(std::string&, const std::map<std::string, std::string>&);
};

} // namespace controller
} // namespace pheide

#endif // CONTROLLER_TAB_CONTROLLER_H_

