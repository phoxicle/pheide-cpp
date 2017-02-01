#ifndef PHEIDE_REPOSITORY_PAGE_REPOSITORY_H_
#define PHEIDE_REPOSITORY_PAGE_REPOSITORY_H_

#include "../model/page_model.h"

namespace pheide {
namespace repository {

class PageRepository {
 public:
	pheide::model::PageModel selectByDefault();
};

} // namespace repository
} // namespace pheide

#endif // PHEIDE_REPOSITORY_PAGE_REPOSITORY_H_
