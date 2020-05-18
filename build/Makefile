IDIR =../include
CC=g++
CFLAGS=-I$(IDIR) -std=c++11 -g

ODIR=../src
LDIR =../lib

LIBS=-lm

_OBJ = main.o gestora.o arista.o grafo.o nodo.o cronometro.o  coordenada.o algoritmos.o algoritmo_voraz.o algoritmo_voraz_nuevo.o algoritmo_busqueda_local.o algoritmo_grasp.o algoritmo_busqueda_tabu.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

all: algoritmos

$(ODIR)/arista.o: $(ODIR)/arista.cc $(IDIR)/arista.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/algoritmos.o: $(ODIR)/algoritmos.cc $(IDIR)/algoritmos.h $(ODIR)/grafo.o $(ODIR)/cronometro.o
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/algoritmo_voraz.o: $(ODIR)/algoritmo_voraz.cc $(IDIR)/algoritmo_voraz.h $(ODIR)/algoritmos.o
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/algoritmo_voraz_nuevo.o: $(ODIR)/algoritmo_voraz_nuevo.cc $(IDIR)/algoritmo_voraz_nuevo.h $(ODIR)/algoritmos.o
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/algoritmo_busqueda_local.o: $(ODIR)/algoritmo_busqueda_local.cc $(IDIR)/algoritmo_busqueda_local.h $(ODIR)/algoritmos.o
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/algoritmo_grasp.o: $(ODIR)/algoritmo_grasp.cc $(IDIR)/algoritmo_grasp.h $(ODIR)/algoritmos.o
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/algoritmo_busqueda_tabu.o: $(ODIR)/algoritmo_busqueda_tabu.cc $(IDIR)/algoritmo_busqueda_tabu.h $(ODIR)/algoritmos.o
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/coordenada.o: $(ODIR)/coordenada.cc $(IDIR)/coordenada.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/nodo.o: $(ODIR)/nodo.cc $(IDIR)/nodo.h $(ODIR)/coordenada.o
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/cronometro.o: $(ODIR)/cronometro.cc $(IDIR)/cronometro.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/grafo.o: $(ODIR)/grafo.cc $(IDIR)/grafo.h $(ODIR)/nodo.cc
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/gestora.o: $(ODIR)/gestora.cc $(IDIR)/gestora.h $(ODIR)/grafo.o
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/main.o: $(ODIR)/main.cpp $(ODIR)/gestora.o 
	$(CC) -c -o $@ $< $(CFLAGS)

algoritmos: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ $(INCDIR)/*~
