CC=gcc
FLAGS=-Wall -Wextra -g -I include
SOURCE_FILES=$(wildcard src/*.c)
OBJECT_FILES=$(patsubst src/%.c, src/%.o, $(SOURCE_FILES))
TARGET=bin/clip

all: $(TARGET)

$(TARGET): $(OBJECT_FILES)
	$(CC) $(FLAGS) $^ -o $@

src/%.o: src/%.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJECT_FILES)
