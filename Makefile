CC = g++
LC = g++

CFLAGS = -Wall
LFLAGS = -Wall

TARGETS_O = main.o binary_heap.o
SOURCES = main.cc binary_heap.cc
OUTPUT = heap

all: $(TARGETS_O)
	$(LC) $(LFLAGS) -o $(OUTPUT) $(TARGETS_O)

TARGETS_O: $(SOURCES)
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(TARGETS_O) $(OUTPUT)

run: all
	./$(OUTPUT)
