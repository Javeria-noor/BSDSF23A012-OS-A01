CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -g
SRCDIR = src
OBJDIR = obj
BINDIR = bin

SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))
TARGET = $(BINDIR)/client

.PHONY: all clean dirs

all: dirs $(TARGET)

dirs:
	mkdir -p $(OBJDIR) $(BINDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf $(OBJDIR)/*.o $(BINDIR)/client
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -g
SRCDIR = src
OBJDIR = obj
BINDIR = bin
LIBDIR = lib

# Only compile main.c now
SRC = $(SRCDIR)/main.c
OBJ = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))
TARGET = $(BINDIR)/client_static
LIB = $(LIBDIR)/libmyutils.a

.PHONY: all clean dirs

all: dirs $(TARGET)

dirs:
	mkdir -p $(OBJDIR) $(BINDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJ) $(LIB)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf $(OBJDIR)/*.o $(BINDIR)/client_static
