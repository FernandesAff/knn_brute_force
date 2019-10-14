.SUFFIXES: .cpp .c .o

include makefile.inc

all: main

ifeq "$(USEARPACK)" "yes"
  EXTRAYAELLDFLAG=$(ARPACKLDFLAGS)
  EXTRAMATRIXFLAG=-DHAVE_ARPACK
endif

ifeq "$(USEOPENMP)" "no"
  EXTRAMATRIXFLAG+=-fopenmp
  EXTRAYAELLDFLAG+=-fopenmp
endif

all: main

main: main.c yael/vector.h yael/nn.h
	gcc -g $(cflags) -o $@ $^ $(LDFLAGS) $(LAPACKLDFLAGS) $(THREADLDFLAGS) $(EXTRAYAELLDFLAG) $(YAELLDFLAGS)

clean: 
	rm -f *.o main
