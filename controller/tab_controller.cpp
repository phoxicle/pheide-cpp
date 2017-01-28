#include <map>
#include "tab_controller.h"
#include "../repository/tab_repository.h"
#include "../model/tab_model.h"
#include "../view/renderer.h"

namespace pheide {
namespace controller {

void TabController::show(int page_id, int tab_id) {
	// Get the Tab object
	pheide::repository::TabRepository tab_repository;
	pheide::model::TabModel tab_model = tab_repository.selectById(page_id, tab_id);

	std::map<std::string, std::string> template_vars {
		{"page_title", "PAGE TITLE PLACEHOLDER"},
		{"tab_title", tab_model.title},
		{"aside", tab_model.aside},
		{"content", tab_model.content}
	};

	pheide::view::Renderer renderer;
	renderer.render("tab/show.html", template_vars);
}

} // namespace controller
} // namespace pheide

