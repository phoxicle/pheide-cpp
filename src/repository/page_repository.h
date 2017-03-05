#ifndef PHEIDE_REPOSITORY_PAGE_REPOSITORY_H_
#define PHEIDE_REPOSITORY_PAGE_REPOSITORY_H_

#include <vector>
#include "../model/page_model.h"

namespace pheide {
namespace repository {

class PageRepository {
 public:
	std::vector<model::PageModel> selectAll();
	model::PageModel selectById(int);
	model::PageModel selectByDefault();
};

} // namespace repository
} // namespace pheide

#endif // PHEIDE_REPOSITORY_PAGE_REPOSITORY_H_
