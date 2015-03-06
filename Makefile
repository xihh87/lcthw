CFLAGS=-Wall	-g
PROGS=ex1	ex3	ex4	ex6	ex7	ex8	ex9	\
	ex10	ex11	ex12	ex13	ex14	ex15	ex16	\
	ex17	ex18	ex20	ex22	ex23	ex24	ex27
OBJS=ex22.o

all:	$(PROGS) ex19/ex19

test:
	bash test/ex17.sh
	cd ex19 && make test

ex19/ex19:
	$(MAKE) -C ex19

ex22: ex22_main.c ex22.o

clean:
	rm	-f	$(PROGS)	$(OBJS)
	$(MAKE)	-C	ex19	clean

.PHONY: test
