#ifndef PHEIDE_REPOSITORY_TAB_REPOSITORY_H_
#define PHEIDE_REPOSITORY_TAB_REPOSITORY_H_

#include <iostream>
#include <mysql.h>
#include <map>
#include "dal.h"
#include "query_builder.h"
#include "../model/tab_model.h"
#include "../model/tab_model_adapter.h"

namespace pheide {
namespace repository {

class TabRepository {
 public:
	pheide::model::TabModel selectById(int, int);
	pheide::model::TabModel selectByDefault(int);
	std::vector<pheide::model::TabModel> selectByPageId(int);
};

} // namespace repository
} // namespace pheide

#endif // PHEIDE_REPOSITORY_TAB_REPOSITORY_H_
