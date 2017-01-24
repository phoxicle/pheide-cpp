#include <iostream>
#include "router.h"
#include "repository/abstract_repository.h"

namespace pheide {

void Router::Route() {
	std::cout << "hi" << std::endl;

	pheide::repository::AbstractRepository repository;
	std::cout << "title is: " << repository.selectByTitle("aoeu") << std::endl;
}

}
