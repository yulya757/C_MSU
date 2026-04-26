# Directory to hold libraries header files
INCLUDEDIR = include
# Directory to hold binary files
BINDIR = bin

# Filename with masterlib binary - for debug purposes
MASTERLIB = master

# Standart variables for implicit compile rules
CC = gcc
CFLAGS = --std=c99 -fPIC -Wall -Werror -O2 -iquote $(INCLUDEDIR)
LDLIBS = -L$(BINDIR) -lstructs
ARFLAGS = rcsv

# Explicit list of basic libraries
LIBS = vector

# Special targets
##  Doesn't procude a file and executed unconditionally
.PHONY= $(LIBS) clean docs all
##  Deleted after non-intermediate target reached
.INTERMEDIATE: $(BINDIR)/%.o

# Default target - in our case, main shared library
all: $(BINDIR)/libstructs.so

# Generate docs
docs:
	doxygen doxygen.conf
	(cd docs/latex && make)

# Clean repo from generates
clean:
	find bin/ -type f -a ! -name lib$(MASTERLIB).a -a ! -name lib$(MASTERLIB).so -execdir rm {} \;
	find . -regextype egrep -regex '\./.*-test(-static)?(-master)?' -a -type f -execdir rm {} \;
	rm -rf docs/

# Shared libraries
##  Explicit target to compile main shared library
$(BINDIR)/libstructs.so: $(addprefix $(BINDIR)/, $(addsuffix .o, $(LIBS)))
	$(CC) --shared $(CFLAGS) $^ -o $@
	

##  Wildcard target to compile specific shared library
$(BINDIR)/lib%.so: src/%.c $(INCLUDEDIR)/%.h
	$(CC) $(CPPFLAGS) $(CFLAGS) --shared -c $< -o $@

##  Shortcut for shared libraries
$(LIBS): %: $(BINDIR)/lib%.so

##  Wildcard target to compile specific object file
$(BINDIR)/%.o: src/%.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# Static libraries
##  Explicit target to compile main static library
$(BINDIR)/libstructs.a: $(BINDIR)/libstructs.a($(addprefix $(BINDIR)/, $(addsuffix .o, $(LIBS))))

##  Wildcard implicit target to compile specific static library
$(BINDIR)/lib%.a: $(BINDIR)/lib%.a($(BINDIR)/%.o)

##  Shortcut for static libraries
%-static: $(BINDIR)/lib%.a

# Tests
## Wildcard target to compile & execute test for specific library
%-test: tests/%_test.c all
	$(CC) $(CPPFLAGS) $(CFLAGS) $< $(LDLIBS) -o $@ 
	LD_LIBRARY_PATH=$(BINDIR) valgrind ./$@

## Wildcard target to compile & execute test for specific library with master library
%-test-master: tests/%_test.c all
	$(CC) $(CPPFLAGS) $(CFLAGS) $< $(LDLIBS) -l $(MASTERLIB) -o $@ 
	LD_LIBRARY_PATH=$(BINDIR) valgrind ./$@

## Wildcard target to compile & execute test for specific static library 
%-test-static: tests/%_test.c $(BINDIR)/libstructs.a
	$(CC) -static $(CPPFLAGS) $(CFLAGS) $^ -o $@ 
	./$@

## Wildcard target to compile & execute test for specific library with master library
%-test-static-master: tests/%_test.c $(BINDIR)/libstructs.a $(BINDIR)/lib$(MASTERLIB).a
	$(CC) -static $(CPPFLAGS) $(CFLAGS) $^ -o $@ 
	./$@
