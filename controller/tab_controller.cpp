#include <map>
#include <fstream>
#include "tab_controller.h"
#include "../repository/tab_repository.h"
#include "../model/tab_model.h"

namespace pheide {
namespace controller {

void TabController::show(int page_id, int tab_id) {
	// use repo to get a Tab model
	pheide::repository::TabRepository tab_repository;
	pheide::model::TabModel tab_model = tab_repository.selectById(page_id, tab_id);

	std::map<std::string, std::string> vars = {
		{"title", tab_model.title},
		{"content", tab_model.content}
	};
	render("templates/tab/show.html", vars);

	// use a view to show the Tab model
	//std::cout << tab_model.title << tab_model.content << std::endl;

}

// TODO move to parent
void TabController::render(std::string template_path, std::map<std::string, std::string> vars) {
	// Get template
	std::ifstream file(template_path);
	std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

	// Populate vars
	replace_vars(content, vars);
	std::cout << content << std::endl;

}

void TabController::replace_vars(std::string& str, const std::map<std::string, std::string>& vars) {
	for(auto const& ent : vars) {
		std::string key = "%%%" + ent.first + "%%%";
		std::string value = ent.second;

		// Replace all occurrences
	    size_t start_pos = 0;
		while((start_pos = str.find(key, start_pos)) != std::string::npos) {
			str.replace(start_pos, key.length(), value);
			start_pos += value.length(); // handle where 'to' is a substring of 'from'
		}
	}
}

} // namespace controller
} // namespace pheide

