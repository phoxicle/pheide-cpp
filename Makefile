CXX=g++
CXXFLAGS=-std=c++11 -I/usr/local/include
LDFLAGS=`mysql_config --include` -I/usr/local/include
LDLIBS=`mysql_config --libs` -L/usr/local/lib -lcgicc

all: pheide


# TODO use implicit rules
dal.o: repository/dal.cpp repository/dal.h
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -c -o $@ $<

query_builder.o: repository/query_builder.cpp repository/query_builder.h
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -c -o $@ $<

link_builder.o: view/link_builder.cpp view/link_builder.h
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -c -o $@ $<

renderer.o: view/renderer.cpp view/renderer.h
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -c -o $@ $<



tab_repository.o: repository/tab_repository.cpp repository/tab_repository.h dal.o query_builder.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -c -o $@ $<

page_repository.o: repository/page_repository.cpp repository/page_repository.h dal.o query_builder.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -c -o $@ $<

tab_controller.o: controller/tab_controller.cpp controller/tab_controller.h tab_repository.o renderer.o link_builder.o
	$(CXX) $(CXXFLAGS) -c -o $@ $<

page_controller.o: controller/page_controller.cpp controller/page_controller.h page_repository.o renderer.o link_builder.o tab_controller.o
	$(CXX) $(CXXFLAGS) -c -o $@ $<

router.o: router.cpp router.h page_controller.o tab_controller.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -c -o $@ $<

main.o: main.cpp router.o
	$(CXX) $(CXXFLAGS) -c -o $@ $<

pheide: main.o router.o page_controller.o tab_controller.o page_repository.o tab_repository.o renderer.o link_builder.o query_builder.o dal.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBS)
