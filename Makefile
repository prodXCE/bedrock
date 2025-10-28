# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -g -Iinclude

# Linker flags
LDFLAGS = 

# Our target exec name
TARGET = bedrock

SOURCES = $(wildcard src/*.c)

OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS) $(LDFLAGS)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJECTS)



