#ifndef PHEIDE_VIEW_RENDERER_H_
#define PHEIDE_VIEW_RENDERER_H_

#include <iostream>
#include <map>
#include <fstream>

namespace pheide {
namespace view {

class Renderer {
 public:
	void render(std::string, std::map<std::string, std::string>);
 private:
	void replace_vars(std::string&, const std::map<std::string, std::string>&);
	std::string read_file(const std::string&);
};

} // namespace view
} // namespace pheide

#endif // PHEIDE_VIEW_RENDERER_H_

