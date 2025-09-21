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
