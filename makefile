#compile with "make -f makefile" in root directory
#then execute program with "./major1"
#clean up src and obj directories with "make clean"
#remove quotation marks when actually running these commands in the terminal

#define variables for all relevant directories
#include directory is for header files (*.h)
IDIR =include
#obj directory is for object files (*.o)
ODIR=src/obj
#src directory is for source code files (*.c)
SDIR =src

#define variables for various commands and flags
CC=gcc
CFLAGS=-Wall -I$(IDIR)
RM=rm -f

#creates the DEPS macro for the set of *.h files that *.c files depend on
#ensures recompilation of *.c files when any header file in the set is changed
_DEPS = major1.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

#creates the OBJ macro for the set of *.o files that depend on the *.c files
_OBJ = major1.o rotate.o clz.o endian.o parity.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

#actually compile the code and create the executable
$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

major1: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

#the following rules clean up the src and obj directories & cleans up the old executable
#prevents make from messing with (or trying to mess with) a file called clean as opposed to the clean command
.PHONY: clean

clean:
	$(RM) $(ODIR)/*.o *~ core $(INCDIR)/*~ major1