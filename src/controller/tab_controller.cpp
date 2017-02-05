#include <map>
#include "tab_controller.h"
#include "../repository/page_repository.h"
#include "../repository/tab_repository.h"
#include "../model/tab_model.h"
#include "../view/renderer.h"
#include "../view/link_builder.h"

namespace pheide {
namespace controller {

void TabController::show(int page_id, int tab_id) {
	pheide::repository::PageRepository page_repository;
	pheide::repository::TabRepository tab_repository;

	pheide::view::LinkBuilder link_builder;
	pheide::view::Renderer renderer;

	// Build the header
	std::vector<pheide::model::PageModel> other_pages = page_repository.selectAll();
	std::string header_images;
	for (auto other_page : other_pages) {
		header_images += renderer.render("header_image.html", {
			{"link", link_builder.withAction("show").withPageId(other_page.uid).build()},
			{"css_id", other_page.header_id},
			{"title", other_page.title}
		});
	}


	// Build the tab bar
	std::vector<pheide::model::TabModel> other_tabs = tab_repository.selectByPageId(page_id);
	std::string tab_bar;
	for (auto other_tab : other_tabs) {
		tab_bar += renderer.render("tab.html", {
			{"tab_link", link_builder.withAction("show").withPageId(page_id).withTabId(other_tab.uid).build()},
			{"tab_title", other_tab.title},
			{"tab_class", tab_id == other_tab.uid ? "activeTab" : ""}
		});
	}

	// Get the Page object
	// TODO check number of queries being executed
	pheide::model::PageModel page_model = page_repository.selectById(page_id);

	// Get the Tab object
	pheide::model::TabModel tab_model = tab_repository.selectById(page_id, tab_id);

	std::map<std::string, std::string> template_vars {
		{"page_title", page_model.title},
		{"tab_title", tab_model.title},
		{"aside", tab_model.aside},
		{"content", tab_model.content},
		{"header_images", header_images},
		{"tab_bar", tab_bar}
	};

	std::cout << renderer.renderPage("tab/show.html", template_vars);
}

} // namespace controller
} // namespace pheide

