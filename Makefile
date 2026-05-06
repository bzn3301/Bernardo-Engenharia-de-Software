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