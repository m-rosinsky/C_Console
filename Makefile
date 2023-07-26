# Compiler selection.
CC=gcc

# Compiler flags.
CFLAGS=-Wall -Wextra -pedantic

# Object dir.
OBJS=objs

# Binary dir.
BINS=bins

# Executable name.
EXEC=console

# Steps.
all: setup compile link

setup:
	@echo -n "Creating subdirs..."
	@mkdir -p $(OBJS) $(BINS)
	@echo "   done"

compile: setup
	@echo -n "Compiling sources..."

	@$(CC) $(CFLAGS) -o $(OBJS)/queue.o -c source/common/queue.c

	@echo "   done"

link: setup compile
	@echo -n "Linking binaries..."

	@$(CC) $(CFLAGS) -o $(BINS)/$(EXEC) source/main.c $(OBJS)/*.o

	@echo "   done"

clean:
	@$(RM) -rf $(OBJS) $(BINS)
