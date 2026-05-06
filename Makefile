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