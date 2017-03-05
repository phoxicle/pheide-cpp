#
#  Makefile
#  Pheide
#
#  Mac CGI executable path:
#  cp bin/pheide /Library/WebServer/CGI-Executables/
#

CC := g++

SRCDIR := src
BUILDDIR := build
TARGETDIR := bin
TARGET := bin/pheide

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name '*.$(SRCEXT)')
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

CFLAGS := -std=c++11
LIB := `mysql_config --libs` -L/usr/local/lib -lcgicc
INC := `mysql_config --include` -I/usr/local/include

$(TARGET): $(OBJECTS)
	@mkdir -p $(TARGETDIR)
	@echo "[0]  $(CC) $^ -o $(TARGET) $(LIB)"; $(CC) $^ -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)/controller
	@mkdir -p $(BUILDDIR)/view
	@mkdir -p $(BUILDDIR)/repository
	@echo "[1]  $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo "[2]  $(RM) -r $(BUILDDIR) $(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGET)
	@echo "[2]  $(RM) -f $(TESTS) gtest.a gtest_main.a *.o"; $(RM) -f $(TESTS) gtest.a gtest_main.a *.o

# Points to the root of Google Test, relative to where this file is.
GTEST_DIR = ./gtest

# Where to find user code.
USER_DIR = src

# Flags passed to the preprocessor.
# Set Google Test's header directory as a system directory, such that
# the compiler doesn't generate warnings in Google Test headers.
CPPFLAGS += -isystem $(GTEST_DIR)/include

# Flags passed to the C++ compiler.
CXXFLAGS += -g -Wall -Wextra -std=c++11

# All tests produced by this Makefile.  Remember to add new tests you created to the list.
TEST_SRCEXT := cc
TEST_SOURCES := $(shell find $(SRCDIR) -type f -name '*.$(TEST_SRCEXT)')
TEST_OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(TEST_SOURCES:.$(TEST_SRCEXT)=.o))
TESTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(TEST_SOURCES:.$(TEST_SRCEXT)=))

# All Google Test headers.  Usually you shouldn't change this definition.
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

# House-keeping build targets.
test : $(TESTS)

# Builds gtest.a and gtest_main.a.
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

# Compile gtest
gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c $(GTEST_DIR)/src/gtest_main.cc

gtest.a : gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a : gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

# Build sources
$(BUILDDIR)/%_test.o : $(SRCDIR)/%_test.cc $(GTEST_HEADERS)
	@echo "[4]  $(CXX) $(CPPFLAGS) $(CXXFLAGS) $(INC) -c $< -o $@"; $(CXX) $(CPPFLAGS) $(CXXFLAGS) $(INC) -c $< -o $@

$(BUILDDIR)/%_test : $(BUILDDIR)/%.o $(BUILDDIR)/%_test.o gtest_main.a
	@echo "[5]  $(CXX) $(CPPFLAGS) $(CXXFLAGS) $(INC) -lpthread $^ -o $@"; $(CXX) $(CPPFLAGS) $(CXXFLAGS) $(INC) -lpthread $^ -o $@
	$@


