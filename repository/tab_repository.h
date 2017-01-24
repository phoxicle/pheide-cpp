#ifndef REPOSITORY_TAB_REPOSITORY_H_
#define REPOSITORY_TAB_REPOSITORY_H_

#include "../model/tab_model.h"

namespace pheide {
namespace repository {

class TabRepository {
 public:
	pheide::model::TabModel selectById(int, int);
};

} // namespace repository
} // namespace pheide

#endif // REPOSITORY_TAB_REPOSITORY_H_