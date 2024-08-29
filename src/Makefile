CC=g++
CFLAGS = -Wall -Werror -Wextra -std=c++17
TEST_LIBS = -lgtest
SOURCES = $(wildcard s21_*.cpp)
OS = $(shell uname)
GCOV_FLAG = --no-external

TARGET=s21_matrix_oop.a

ifneq ($(OS), Darwin)
	TEST_LIBS = -lgtest -pthread -lrt
	GCOV_FLAG =
endif

all: $(TARGET) test gcov_report

$(TARGET):
	$(CC) $(CFLAGS) -c $(SOURCES)
	ar rcs $(TARGET) *.o

test: $(TARGET)
	$(CC) $(CFLAGS) --coverage $(SOURCES) test.cpp $(TARGET) $(TEST_LIBS) -o test
	./test

debug: $(TARGET)
	$(CC) $(SOURCES) test.cpp $(TARGET) $(TEST_LIBS) -o test -g

gcov_report: add_coverage_flag test
	./test
	lcov -t "test" -o test.info -c -d ./  --no-external $(LCOVFLAGS)
	lcov --remove test.info 'test.cpp' -o test.info
	genhtml -o report test.info $(LCOVFLAGS)

add_coverage_flag:
	$(eval CFLAGS += --coverage)

valgrind: $(TARGET) debug
	valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./test > valgrind_log.txt 2>&1

clang-format:
	clang-format -style=Google -n $(SOURCES)
	clang-format -style=Google -i $(SOURCES)

clean:
	rm -rf ./*.o ./*.a gcov_test ./*.gcno ./*.gcda report/ ./test ./test.c ./*.info valgrind_log.txt

rebuild: clean all