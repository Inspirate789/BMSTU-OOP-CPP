CC := g++
CPPFLAGS := -std=c++20 -Werror -Wall -Wno-unknown-pragmas -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -Wvla
LINKFLAGS := -lgtest -lgtest_main -lpthread
DEBUGFLAGS := -g3 --coverage
INC_DIRS := inc imp tests
INC_DIRS := $(INC_DIRS:%=-I%)
SRC_DIR := src
OUT_DIR := out
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(OUT_DIR)/%.o)
GCOV_MODULES := $(OBJS:%.o=%.gcno)
DEPENDS := $(SRCS:$(SRC_DIR)/%.cpp=$(OUT_DIR)/%.d)

_MAKE_OUT_DIR_ := $(shell mkdir -p $(OUT_DIR))

.PHONY: debug release coverage clean
.NOTPARALLEL: debug release

debug: CPPFLAGS += $(DEBUGFLAGS)
debug: LINKFLAGS += $(DEBUGFLAGS)
debug: debug.lastbuildstate app.exe

release: release.lastbuildstate app.exe

debug.lastbuildstate:
	touch debug.lastbuildstate
	rm -f $(OBJS) $(OUT_DIR)/main.o $(OUT_DIR)/*.g* *.exe
	rm -f release.lastbuildstate

release.lastbuildstate:
	touch release.lastbuildstate
	rm -f $(OBJS) $(OUT_DIR)/main.o $(OUT_DIR)/*.g* *.exe
	rm -f debug.lastbuildstate

coverage: debug
	./app.exe
	gcov -r $(GCOV_MODULES)
	mv *.gcov $(OUT_DIR)/

app.exe: $(OBJS)
	$(CC) $^ -o $@ $(LINKFLAGS)

$(OUT_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CPPFLAGS) $(INC_DIRS) -MMD -o $@ -c $<

-include $(DEPENDS)

clean:
	rm -f $(OUT_DIR)/* *.exe *.lastbuildstate
	