# CC := g++
# CFLAGS := -std=c99 -Werror -Wall -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -Wvla
# LINKFLAGS :=
# DEBUGFLAGS := -g3 --coverage
# INC_DIR := inc
# SRC_DIR := src
# OUT_DIR := out
# UNIT_DIR := unit_tests
# SRCS := $(wildcard $(SRC_DIR)/*.c)
# SRCS_UNIT := $(wildcard $(UNIT_DIR)/*.c)
# OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OUT_DIR)/%.o)
# OBJS := $(filter-out $(OUT_DIR)/main.o, $(OBJS))
# OBJS_UNIT := $(SRCS_UNIT:$(UNIT_DIR)/%.c=$(OUT_DIR)/%.o)
# OBJS_UNIT := $(filter-out $(OUT_DIR)/%main.o, $(OBJS_UNIT))
# GCOV_MODULES := $(OBJS:%.o=%.gcno)
# DEPENDS := $(SRCS:$(SRC_DIR)/%.c=$(OUT_DIR)/%.d)
# DEPENDS += $(SRCS_UNIT:$(UNIT_DIR)/%.c=$(OUT_DIR)/%.d)

# _MAKE_OUT_DIR_ := $(shell mkdir -p $(OUT_DIR))

# .PHONY: debug release func unit clean
# .NOTPARALLEL: debug release

# debug: CFLAGS += $(DEBUGFLAGS)
# debug: LINKFLAGS += $(DEBUGFLAGS)
# debug: debug.lastbuildstate app.exe

# release: release.lastbuildstate app.exe

# debug.lastbuildstate:
# 	touch debug.lastbuildstate
# 	rm -f $(OBJS) $(OUT_DIR)/main.o $(OUT_DIR)/*.g* *.exe
# 	rm -f release.lastbuildstate

# release.lastbuildstate:
# 	touch release.lastbuildstate
# 	rm -f $(OBJS) $(OUT_DIR)/main.o $(OUT_DIR)/*.g* *.exe
# 	rm -f debug.lastbuildstate

# func: debug
# 	cd func_tests && ./run_tests.sh && cd ..
# 	@echo
# 	gcov -r $(OUT_DIR)/main.gcno $(GCOV_MODULES)
# 	mv *.gcov $(OUT_DIR)/

# unit: CFLAGS += $(DEBUGFLAGS)
# unit: LINKFLAGS += $(DEBUGFLAGS)
# unit: debug.lastbuildstate unit_tests.exe
# 	./unit_tests.exe
# 	@echo
# 	gcov -r $(GCOV_MODULES)
# 	mv *.gcov $(OUT_DIR)/

# app.exe: $(OUT_DIR)/main.o $(OBJS)
# 	$(CC) $^ -o $@ $(LINKFLAGS)

# unit_tests.exe: $(OUT_DIR)/check_main.o $(OBJS) $(OBJS_UNIT)
# 	$(CC) $^ -o $@ -lcheck $(LINKFLAGS)

# $(OUT_DIR)/%.o: $(SRC_DIR)/%.c
# 	$(CC) $(CFLAGS) -I$(INC_DIR) -MMD -o $@ -c $<

# $(OUT_DIR)/%.o: $(UNIT_DIR)/%.c
# 	$(CC) $(CFLAGS) -I$(INC_DIR) -MMD -o $@ -c $<

# -include $(DEPENDS)

# clean:
# 	rm -f $(OUT_DIR)/* *.exe *.lastbuildstate
	