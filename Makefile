
pheide.o:
	g++ `mysql_config --include` model/tab_model.cpp repository/tab_repository.cpp controller/tab_controller.cpp router.cpp main.cpp `mysql_config --libs`