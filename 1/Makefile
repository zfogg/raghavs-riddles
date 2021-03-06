#!/usr/bin/make -f


SRC_D = src

OUT_D = build

BIN_D = bin

TEST_D = test


CC = clang -std=c99 -O2 -Wextra -Wno-unused-parameter -Wno-sign-compare


LIB = one


OBJECTS = $(patsubst $(SRC_D)/%.c, $(OUT_D)/%.o, $(wildcard $(SRC_D)/*.c))

OBJECTS_T = $(patsubst $(TEST_D)/%.c, $(OUT_D)/%.o, $(wildcard $(TEST_D)/*.c))

HEADERS = $(wildcard $(SRC_D)/*.h)

HEADERS_T = $(wildcard $(TEST_D)/*.h)


TARGET = $(OUT_D)/lib$(LIB).so

TESTS = $(BIN_D)/$(LIB)_tests


export LD_LIBRARY_PATH=$(OUT_D)

.PHONY: default all clean test


default: $(TARGET)

all: default

clean:
	rm -rf $(OUT_D)/* $(BIN_D)/*

test: all $(TESTS)
	./$(TESTS)


$(OBJECTS): $(OUT_D)/%.o: $(SRC_D)/%.c $(HEADERS)
	$(CC) -c -fpic $< -o $@

$(OUT_D)/%.so: $(OBJECTS)
	$(CC) -shared $^ -o $@

$(OBJECTS_T): $(OUT_D)/%.o: $(TEST_D)/%.c $(HEADERS_T)
	$(CC) -c -fpic $< -o $@

$(TESTS): $(OBJECTS_T)
	$(CC) $^ -o $@ -L$(OUT_D) -l$(LIB)

