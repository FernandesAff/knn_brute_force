
# generated by ./configure.sh 

CC=gcc

CFLAGS=-fPIC -Wall -g -O3 
LDFLAGS=-g -fPIC 

PYTHONCFLAGS = -I/usr/include/python2.7

YAELCONF=linux64
YAELCFLAGS=-I/home/andre/Downloads/trabalho_PC
YAELLDFLAGS=-L/home/andre/Downloads/trabalho_PC/yael -Wl,-rpath,/home/andre/Downloads/trabalho_PC/yael -lyael


SWIG=swig -python

WRAPLDFLAGS=-shared
LAPACKLDFLAGS=-lblas -llapack
LAPACKCFLAGS=-DFINTEGER=int

USEARPACK=no
ARPACKLDFLAGS=/usr/lib64/libarpack.so.2

USETHREADS=yes
THREADCFLAGS=-DHAVE_THREADS

SHAREDEXT=so
SHAREDFLAGS=-shared
YAELSHAREDFLAGS=-shared

USENUMPY=
NUMPYCFLAGS=
NUMPYSWIGFLAGS=


USEOPENMP=yes

