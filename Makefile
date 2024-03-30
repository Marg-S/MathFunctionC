CC = gcc
CFLAGS = -Wall  -Wextra -std=c11 -g
GCOVFLAGS = -fprofile-arcs -ftest-coverage
LDFLAGS = $(shell pkg-config --cflags --libs check) -lcheck -lm

OS := $(shell uname)

ifeq ($(OS),Linux)
	LDFLAGS += -lsubunit
endif

GCOV_HTML_DIR = report
SRC_DIR = .
OBJ_DIR = obj
OBJ_DIR_TEST = obj_test
TEST_DIR = tests

SRC = my_abs.c my_sin.c my_tan.c my_ceil.c my_floor.c my_exp.c my_log.c my_asin.c my_acos.c  my_atan.c  my_cos.c  my_fabs.c  my_fmod.c  my_pow.c my_sqrt.c 
UTILS = my_utils.c
OBJ = $(addprefix $(OBJ_DIR)/, $(UTILS:.c=.o)) $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
OBJ_TEST = $(addprefix $(OBJ_DIR_TEST)/, $(UTILS:.c=.o)) $(addprefix $(OBJ_DIR_TEST)/, $(SRC:.c=.o))
TEST = my_tests.c $(patsubst %.c, test_%.c, $(SRC))
TEST_SRC = $(addprefix $(TEST_DIR)/, $(TEST))
TEST_OBJ = $(addprefix $(TEST_DIR)/$(OBJ_DIR)/, $(TEST:.c=.o))

LIB = my_math.a
EXECUTABLE = test_set
COVERAGE_INFO = coverage.info

all: clean gcov_html

$(LIB): ${OBJ}
	@echo "Building the static library..."
	ar rc $(LIB) $^
	ranlib $(LIB)

gcov_report: test
	@echo "Preparing a report..."
	gcov $(SRC)
	@echo "Generating HTML coverage report..."
	@mkdir -p $(GCOV_HTML_DIR)
	geninfo $(SRC_DIR) --output-file $(GCOV_HTML_DIR)/$(COVERAGE_INFO)
	genhtml $(GCOV_HTML_DIR)/$(COVERAGE_INFO) --output-directory $(GCOV_HTML_DIR)
	open $(GCOV_HTML_DIR)/index.html

test: clean ${EXECUTABLE}
	@echo "Running tests..."
	./${EXECUTABLE}

memory_test: 
ifeq ($(OS),Linux)
	valgrind --leak-check=full ./$(EXECUTABLE)
else
	CK_FORK=no leaks -quiet --atExit -- ./$(EXECUTABLE)
endif

style:
	@echo "Checking styles..."
	clang-format -n -style=Google *.c *.h tests/*.c tests/*.h

format_style:
	@echo "Formatting styles..."
	clang-format -i -style=Google *.c *.h tests/*.c tests/*.h

clean:
	@echo "Cleaning up..."
	rm -rf *.o $(EXECUTABLE) *.gcov *.gcda *.gcno $(LIB) $(OBJ_DIR) $(OBJ_DIR_TEST) $(GCOV_HTML_DIR) ${TEST_DIR}/$(OBJ_DIR) $(TEST_DIR)/*.gcov $(TEST_DIR)/*.gcda $(TEST_DIR)/*.gcno $(TEST_DIR)/$(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_DIR_TEST)/%.o: %.c
	@mkdir -p $(OBJ_DIR_TEST)
	$(CC) $(CFLAGS) $(GCOVFLAGS) -c -o $@ $<

$(TEST_DIR)/$(OBJ_DIR)/%.o: $(TEST_DIR)/%.c
	@mkdir -p $(TEST_DIR)/$(OBJ_DIR)
	$(CC) $(CFLAGS) $(GCOVFLAGS) -c -o $@ $<

$(EXECUTABLE): $(TEST_OBJ) $(OBJ_TEST)
	$(CC) $(CFLAGS) $(GCOVFLAGS) $^ -o $@ $(LDFLAGS)

.PHONY: all gcov_report test memory_test style format_style clean