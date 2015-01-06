int Monster_attack(void *self, int damage);
int Monster_init(void *self);

Object MonsterProto = {
	.init = Monster_init,
	.attack = Monster_attack,
};

struct Monster {
	Object proto;
	int hit_points;
};

typedef struct Monster Monster;


void *Room_move(void *self, Direction direction);
int Room_atack(void *self, int damage);
int Room_init(void *self);

struct Room {
	Object proto;

	Monster *bad_guy;

	struct Room *north;
	struct Room *south;
	struct Room *east;
	struct Room *west;
};

typedef struct Room Room;

void *Map_move(void *self, Direction direction);
int Map_attack(void *self, int damage);
int Map_init(void *self);

struct Map {
	Object proto;
	Room *start;
	Room *location;
};

Object MapProto = {
	.init = Map_init,
	.move = Map_move,
	.attack = Map_attack,
};

typedef struct Map Map;

int process_input(Map *game);

