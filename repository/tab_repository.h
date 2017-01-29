#ifndef REPOSITORY_TAB_REPOSITORY_H_
#define REPOSITORY_TAB_REPOSITORY_H_

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
};

} // namespace repository
} // namespace pheide

#endif // REPOSITORY_TAB_REPOSITORY_H_
