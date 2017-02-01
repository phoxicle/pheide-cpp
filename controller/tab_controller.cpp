#include <map>
#include "tab_controller.h"
#include "../repository/tab_repository.h"
#include "../model/tab_model.h"
#include "../view/renderer.h"
#include "../view/link_builder.h"

namespace pheide {
namespace controller {

void TabController::show(int page_id, int tab_id) {
	// Get the Tab object
	pheide::repository::TabRepository tab_repository;
	pheide::model::TabModel tab_model = tab_repository.selectById(page_id, tab_id);

	pheide::view::LinkBuilder link_builder;
	pheide::view::Renderer renderer;
	std::vector<pheide::model::TabModel> other_tabs = tab_repository.selectByPageId(page_id);
	std::string tab_bar;
	for (auto other_tab : other_tabs) {
		tab_bar += renderer.render("tab.html", {
			{"tab_link", link_builder.withAction("show").withPageId(page_id).withTabId(other_tab.uid).build()},
			{"tab_title", other_tab.title},
			{"tab_class", tab_id == other_tab.uid ? "activeTab" : ""}
		});
	}

	std::map<std::string, std::string> template_vars {
		{"page_title", "PAGE TITLE PLACEHOLDER"},
		{"tab_title", tab_model.title},
		{"aside", tab_model.aside},
		{"content", tab_model.content},
		{"tab_bar", tab_bar}
	};

	std::cout << renderer.renderPage("tab/show.html", template_vars);
}

} // namespace controller
} // namespace pheide

