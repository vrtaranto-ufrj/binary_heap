CC = g++
CFLAGS = -Wall -std=c++11

TARGETS_O = main.o binary_heap.o
TEST_TARGETS_O = binary_heap_tests.o binary_heap.o
SOURCES = main.cc binary_heap.cc
TEST_SOURCES = binary_heap_tests.cc binary_heap.cc
HEADERS = binary_heap.hh
OUTPUT = heap
TEST_OUTPUT = test_binary_heap

all: $(OUTPUT)

$(OUTPUT): $(TARGETS_O)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cc $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

test: $(TEST_SOURCES)
	$(CC) $(CFLAGS) -o $(TEST_OUTPUT) $^
	./$(TEST_OUTPUT)

clean:
	rm -f $(TARGETS_O) $(TEST_TARGETS_O) $(OUTPUT) $(TEST_OUTPUT)

run: all
	./$(OUTPUT)
