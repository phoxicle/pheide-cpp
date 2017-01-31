CC=g++
CPPFLAGS=-std=c++11
LDFLAGS=`mysql_config --include`
LDLIBS=`mysql_config --libs`

all: pheide

dal.o: repository/dal.cpp repository/dal.h
	$(CC) $(CPPFLAGS) $(LDFLAGS) -c -o dal.o -c repository/dal.cpp

query_builder.o: repository/query_builder.cpp repository/query_builder.h
	$(CC) $(CPPFLAGS) -c -o query_builder.o repository/query_builder.cpp

repository.o: repository/tab_repository.cpp repository/tab_repository.cpp
	$(CC) $(CPPFLAGS) $(LDFLAGS) -c -o repository.o repository/tab_repository.cpp

link_builder.o: view/link_builder.cpp view/link_builder.h
	$(CC) $(CPPFLAGS) -c -o link_builder.o view/link_builder.cpp

view.o: view/renderer.cpp view/renderer.h
	$(CC) $(CPPFLAGS) -c -o view.o view/renderer.cpp

controller.o: controller/tab_controller.cpp
	$(CC) $(CPPFLAGS) -c -o controller.o controller/tab_controller.cpp

router.o: router.cpp router.h
	$(CC) $(CPPFLAGS) -c -o router.o router.cpp

main.o: main.cpp
	$(CC) $(CPPFLAGS) -c -o main.o main.cpp

pheide: dal.o query_builder.o repository.o view.o controller.o main.o router.o link_builder.o
	$(CC) $(CPPFLAGS) $(LDFLAGS) -o pheide dal.o query_builder.o repository.o view.o controller.o main.o router.o link_builder.o $(LDLIBS)
