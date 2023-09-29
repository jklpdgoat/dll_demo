# Basic Makefile
# Source / Credit:
# https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/

# Makefile structure:
# 	- .h files in an include directory found in the project root
#   - source code will be under src directory
#   - local libraries under lib directory
# 	- place .o files in their own directory / obj dir

# Compiler version: 
# clang version 14.0.6
# Target: x86_64-unknown-linux-gnu
# Thread model: posix
# InstalledDir: /nix/store/pl4kwicji3vr968vd8j8lh934m6f9bkh-clang-14.0.6/bin

# Some notes:
# hellomake: hellomake.c hellofunc.c
# 	clang -g -Wall -o hellomake hellomake.c hellofunc.c -I.

# $(CC) -g -Wall -o $@ $^ $(CFLAGS)

# baseline compiler flags

# header files
IDIR =../include
CC=clang
CFLAGS=-I$(IDIR) -g3 -Wall -Wextra -Wconversion -Wdouble-promotion \
     -Wno-unused-parameter -Wno-unused-function -Wno-sign-conversion \
     -fsanitize=undefined -fsanitize-trap

ODIR=obj
LDIR =../lib

LIBS=-lm

_DEPS = dll_ops.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = dll_ops.o dll_ops_impl.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

dll_ops: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 