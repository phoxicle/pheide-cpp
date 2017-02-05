#ifndef PHEIDE_MODEL_PAGE_MODEL_H_
#define PHEIDE_MODEL_PAGE_MODEL_H_

#include <string>

namespace pheide {
namespace model {

struct PageModel {
	int uid;
	std::string title;
	std::string header_id;
	bool is_default;
};

} // namespace model
} // namespace pheide

#endif // PHEIDE_MODEL_PAGE_MODEL_H_
