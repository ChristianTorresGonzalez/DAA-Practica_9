IDIR =../include
CC=g++
CFLAGS=-I$(IDIR) -std=c++11 -g

ODIR=../src
LDIR =../lib

LIBS=-lm

_OBJ = main.o gestora.o arista.o grafo.o nodo.o algoritmos.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

all: algoritmos

$(ODIR)/arista.o: $(ODIR)/arista.cc $(IDIR)/arista.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/nodo.o: $(ODIR)/nodo.cc $(IDIR)/nodo.h $(ODIR)/arista.o
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/grafo.o: $(ODIR)/grafo.cc $(IDIR)/grafo.h $(ODIR)/arista.o $(ODIR)/nodo.cc
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/gestora.o: $(ODIR)/gestora.cc $(IDIR)/gestora.h $(ODIR)/grafo.o
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/algoritmos.o: $(ODIR)/algoritmos.cc $(IDIR)/algoritmos.h $(ODIR)/grafo.o
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/main.o: $(ODIR)/main.cpp $(ODIR)/gestora.o $(ODIR)/algoritmos.o
	$(CC) -c -o $@ $< $(CFLAGS)

algoritmos: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ $(INCDIR)/*~
