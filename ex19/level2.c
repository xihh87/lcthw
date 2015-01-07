#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "object.h"
#include "game.h"

int Map_init(void *self)
{
	Map *map = self;
	
	// Make some rooms fo a small map
	Room *hall = NEW(Room, "The great Hall");
	Room *throne = NEW(Room, "The throne room");
	Room *arena = NEW(Room, "The arena, with the minotaur");
	Room *kitchen = NEW(Room, "Kitchen, you have the knife now");

	// put the bad guy in the arena
	arena->bad_guy = NEW(Monster, "Little Vampire");

	// setup the map rooms
	hall->north = throne;

	throne->west = arena;
	throne->east = kitchen;
	throne->south = hall;

	arena->east = throne;
	kitchen->west = throne;

	// start the map and the character off in the hall
	map->start = hall;
	map->location = hall;

	return 1;
}



Object MapProto = {
	.init = Map_init,
	.move = Map_move,
	.attack = Map_attack,
};

int main(int argc, char *argv[])
{
	// simple way to setup the randomness
	srand(time(NULL));

	// make our map to work with
	Map *game = NEW(Map, "Pensylvanian Castle.");

	printf("You enter the ");
	game->location->proto.describe(game->location);

	while(process_input(game)) {
	}

	return 0;
}

