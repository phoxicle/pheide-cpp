#include <iostream>
#include <map>
#include <fstream>
#include "renderer.h"

namespace pheide {
namespace view {

void Renderer::render(std::string template_name, std::map<std::string, std::string> vars) {
	// Get template
	std::string body(read_file("templates/" + template_name));

	// Add header and footer
	std::string header(read_file("templates/header.html"));
	std::string footer(read_file("templates/footer.html"));
	std::string content = header + body + footer;

	// Populate vars
	replace_vars(content, vars);

	// Output
	std::cout << "Content-type:text/html\r\n\r\n";
	std::cout << content;
}

std::string Renderer::read_file(const std::string& path) {
	std::ifstream file(path);
	std::string contents((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
	return contents;
}

void Renderer::replace_vars(std::string& str, const std::map<std::string, std::string>& vars) {
	// Process all vars
	for(auto const& ent : vars) {
		std::string key = "%%%" + ent.first + "%%%";
		std::string value = ent.second;

		// Replace all occurrences
	    size_t start_pos = 0;
		while((start_pos = str.find(key, start_pos)) != std::string::npos) {
			str.replace(start_pos, key.length(), value);
			start_pos += value.length(); // handle where value is a substring of key
		}
	}
}

} // namespace view
} // namespace pheide

