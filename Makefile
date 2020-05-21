CFLAGS=-Wall	-Wpedantic	-g
PROGS=ex01	ex03	ex04	ex06	ex07	ex08	ex09	\
	ex10	ex11	ex12	ex13	ex14	ex15	ex16	\
	ex17	ex18	ex20	ex22	ex23	ex24	ex25	ex27
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
