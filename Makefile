CC := g++
CFLAGS := -Wall -Iinclude
SRCDIR := src
BINDIR := bin
TESTDIR := test

all: main

main:
	$(CC) $(CFLAGS) $(SRCDIR)/*.cpp -o $(BINDIR)/programa.exe

# Alvo para gerar o binário de testes solicitado
test:
	$(CC) $(CFLAGS) $(TESTDIR)/main.cpp $(SRCDIR)/bib.cpp -o $(BINDIR)/testeRegressivo.exe
CC := g++
CFLAGS := -Wall -g -Iinclude
SRCDIR := src
BINDIR := bin
TESTDIR := test

# Garante que a pasta bin exista antes de compilar
$(shell mkdir -p $(BINDIR))

all: main

main:
	$(CC) $(CFLAGS) $(SRCDIR)/*.cpp -o $(BINDIR)/programa.exe

# Alvo para os testes (Regra 9 e 10)
test:
	$(CC) $(CFLAGS) $(TESTDIR)/main.cpp $(SRCDIR)/bib.cpp -o $(BINDIR)/testeRegressivo.exe

clean:
	rm -rf $(BINDIR)/*
CC := g++
SRCDIR := src
INCDIR := include
BINDIR := bin

all: main

main:
    $(CC) $(SRCDIR)/*.cpp -I$(INCDIR) -o $(BINDIR)/programa.exe