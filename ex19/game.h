int Monster_attack(void *self, int damage);
int Monster_init(void *self);

struct Monster {
	Object proto;
	int hit_points;
};

Object MonsterProto;

typedef struct Monster Monster;

void *Room_move(void *self, Direction direction);
int Room_attack(void *self, int damage);
int Room_init(void *self);
typedef int (*init_cb)(void *self);

struct Room {
	Object proto;

	Monster *bad_guy;

	struct Room *north;
	struct Room *south;
	struct Room *east;
	struct Room *west;
};

typedef struct Room Room;

Object RoomProto;

void *Map_move(void *self, Direction direction);
int Map_attack(void *self, int damage);
void Map_destroy(void *self);

struct Map {
	Object proto;
	Room *start;
	Room *location;
};

typedef struct Map Map;

int process_input(Map *game);
