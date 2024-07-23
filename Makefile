# Compiler to use
CC = g++

# Compiler flags
CFLAGS = -Wall -Wextra -std=c++11

# Output executable
TARGET = add-nbo

# Source files
SRCS = add_nbo.c

# Object files (derived from source files)
OBJS = $(SRCS:.c=.o)

# Default target
all: $(TARGET)

# Linking
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compilation
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(TARGET) $(OBJS)

# Rebuild
rebuild: clean all
