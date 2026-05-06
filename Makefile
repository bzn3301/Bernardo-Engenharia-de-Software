CC := g++
SRCDIR := src
INCDIR := include
BINDIR := bin

all: main

main:
    $(CC) $(SRCDIR)/*.cpp -I$(INCDIR) -o $(BINDIR)/programa.exe