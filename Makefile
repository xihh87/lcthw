CFLAGS=-Wall	-Wpedantic	-g
SRCS=$(wildcard ex??.c)
PROGS=$(SRCS:.c=)
OBJS=ex22.o

all:	$(PROGS)
	mkdir	-p	build
	mv	$(PROGS)	build

test:
	bash	test/ex17.sh
	cd	ex19	&&	make	test

ex19/ex19:
	$(MAKE)	-C	ex19

ex22:	ex22_main.c	ex22.o

clean:
	rm	-f	$(PROGS)	$(OBJS)
	$(MAKE)	-C	ex19	clean

.PHONY:	test
