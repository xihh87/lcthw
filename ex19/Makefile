CFLAGS=-Wall	-g
OBJS=object.o	game.o
LEVELS=ex19	level2

all:	$(LEVELS)

ex19:	$(OBJS)
level2:	$(OBJS)

test:
	bash /home/xihh/progs/lcthw/ex19/ex19-test.sh
	bash /home/xihh/progs/lcthw/ex19/level2-test.sh

clean:
	rm -f $(LEVELS) $(OBJS)

.PHONY: test
