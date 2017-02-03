CC=g++
CPPFLAGS=-std=c++11 -I/usr/local/include
LDFLAGS=`mysql_config --include` -I/usr/local/include
LDLIBS=`mysql_config --libs` -L/usr/local/lib -lcgicc

all: pheide

dal.o: repository/dal.cpp repository/dal.h
	$(CC) $(CPPFLAGS) $(LDFLAGS) -c -o dal.o -c repository/dal.cpp

query_builder.o: repository/query_builder.cpp repository/query_builder.h
	$(CC) $(CPPFLAGS) -c -o query_builder.o repository/query_builder.cpp

repository.o: repository/tab_repository.cpp repository/tab_repository.h
	$(CC) $(CPPFLAGS) $(LDFLAGS) -c -o repository.o repository/tab_repository.cpp

page_repository.o: repository/page_repository.cpp repository/page_repository.h model/page_model.h model/page_model_adapter.h
	$(CC) $(CPPFLAGS) $(LDFLAGS) -c -o page_repository.o repository/page_repository.cpp

link_builder.o: view/link_builder.cpp view/link_builder.h
	$(CC) $(CPPFLAGS) -c -o link_builder.o view/link_builder.cpp

view.o: view/renderer.cpp view/renderer.h
	$(CC) $(CPPFLAGS) -c -o view.o view/renderer.cpp

controller.o: controller/tab_controller.cpp controller/tab_controller.h
	$(CC) $(CPPFLAGS) -c -o controller.o controller/tab_controller.cpp

page_controller.o: controller/page_controller.cpp controller/page_controller.h
	$(CC) $(CPPFLAGS) -c -o page_controller.o controller/page_controller.cpp

router.o: router.cpp router.h
	$(CC) $(CPPFLAGS) $(LDFLAGS) -c -o router.o router.cpp

main.o: main.cpp
	$(CC) $(CPPFLAGS) -c -o main.o main.cpp

pheide: dal.o query_builder.o repository.o page_repository.o view.o controller.o page_controller.o  main.o router.o link_builder.o
	$(CC) $(CPPFLAGS) $(LDFLAGS) -o pheide dal.o query_builder.o repository.o page_repository.o view.o controller.o page_controller.o main.o router.o link_builder.o $(LDLIBS)
