#include "tab_repository.h"
#include "../model/tab_model.h"

namespace pheide {
namespace repository {

pheide::model::TabModel TabRepository::selectById(int page_id, int tab_id) {
	// TODO retrieve from DB
	pheide::model::TabModel tab_model("a title", "some content");
	return tab_model;
}

} // namespace repository
} // namespace pheide




