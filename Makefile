#Makefile for bigInteger library using DlinkedList
#Thibault Miclo - thibault.miclo@utbm.fr
#Isaac Chiboub - isaac.chiboub@utbm.fr
#15/11/11
#
#
# Use lib target to compile the library
# Use run to compile and run the test program
# Use make alone to compile the program
# Use clean to remove .o .so .tmp and .s files 


DEL=rm
CXX=gcc
LIB=lib

EXE=bigInteger

SOURCES=main DlinkedList bigInteger
SOURCESFILES = $(SOURCES:=.c)
OBJECTSFILES = $(SOURCES:=.o)


CCFLAGS = -Werror -Wall -ansi -pedantic -g
LIBS=BigInteger
LIBSDIR= -L.
INCLUDEDIR = -I. -I/usr/include 


all:$(EXE)
	
$(EXE): $(OBJECTSFILES)
	@echo "\n ---------- Linking ---------------"
	$(CXX) $(CCFLAGS) $(LIBSDIR) -o $(EXE) $(OBJECTSFILES) 

.c.o:
	@echo "\n ---------- Compilation of" $@ "---------------"
	$(CXX) $(INCLUDEDIR) $(CCFLAGS) -fPIC -c -o $@ $<
	
lib: $(OBJECTSFILES)
	@echo "\n ----- Building the bigInteger lib ---------- "
	$(CXX) $(CCFLAGS) -shared -fPIC -o libBigInteger.so bigInteger.o
	$(DEL) -f *.o *.tmp *.s

clean:
	@echo "\n-----------Cleaning tmp files------------\n"
	$(DEL) -f *.o *.so *.tmp $(EXE) *.s

run: all
	./$(EXE)

