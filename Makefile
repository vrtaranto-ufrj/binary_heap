CC = g++
CFLAGS = -Wall -std=c++11

TARGETS_O = main.o binary_heap.o
SOURCES = main.cc binary_heap.cc
HEADERS = binary_heap.hh
OUTPUT = heap

all: $(OUTPUT)

$(OUTPUT): $(TARGETS_O)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cc $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGETS_O) $(OUTPUT)

run: all
	./$(OUTPUT)
