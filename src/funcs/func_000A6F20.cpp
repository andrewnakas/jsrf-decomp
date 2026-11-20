struct Vector3 {
    float x, y, z;
};

struct Game {
    void *func_000128C0(int id);
};
extern Game *data_0022FCE0;

struct Object_00014A80 {
    int func_00014A10(Vector3 *point);
    int func_00014C30(int *first, int *second);
};
extern Object_00014A80 data_001EB938;

struct Cell_000A6DC0 {
    char unknown_00[0xd0];
};

struct Section_000A6DC0 {
    char unknown_00[0x10];
    Cell_000A6DC0 *cells;
    unsigned int cell_count;
    int *indices;
    unsigned int index_count;
};

struct Map_000A6DC0 {
    int kind;
    Section_000A6DC0 *sections;
    unsigned int section_count;
};

// The engine's random number (0 to 0x7fff).
unsigned int func_0014C2B0();
extern int data_00257C64;

int func_0004A6F0(Vector3 *point, Cell_000A6DC0 *cell);

struct Player_000A6B70 {
    char unknown_000[0x8a4];
    int id;
    int team;
    char unknown_8ac[0x28];
    int target_id;
};

struct Target_000A68D0 {
    char unknown_000[0xca4];
    Vector3 position;
};

// The camera rig's anchor (section +0x80, cell +0x84, player +0x88, position +0x8c); its own player's id and team
// at 0x8a4/0x8a8 and its target at 0x8d4.
struct Object_000A63C0 {
    char unknown_000[0x80];
    int section_index;
    int cell_index;
    int player;
    Vector3 position;
    char unknown_098[0x80c];
    int id;
    int team;
    char unknown_8ac[0x28];
    int target_id;

    int func_000A6DC0(Map_000A6DC0 *map, int arg, Vector3 *point);
    int func_000A6F20(Map_000A6DC0 *map);
};

// Picks an anchor when there is none: kind 0 the point from func_00014A10, kind 1 the player func_00014C30 names,
// kind 2 the first of the 32 players in shuffled order; each must be of another id and team and be found by
// func_000A6DC0 from the target's position.
int Object_000A63C0::func_000A6F20(Map_000A6DC0 *map)
{
    if (section_index < 0) {
        Target_000A68D0 *self = (Target_000A68D0 *)data_0022FCE0->func_000128C0(target_id);
        if (self) {
            Vector3 point = self->position;
            switch (map->kind) {
            case 0: {
                Vector3 found;
                if (data_001EB938.func_00014A10(&found) && func_000A6DC0(map, (int)&point, &found)) {
                    position = found;
                    return 1;
                }
                break;
            }
            case 1: {
                int other_id;
                int other_team;
                if (data_001EB938.func_00014C30(&other_id, &other_team) && other_id != id && other_team != team) {
                    Player_000A6B70 *owner = (Player_000A6B70 *)data_0022FCE0->func_000128C0(other_id + 0xc);
                    if (owner) {
                        Target_000A68D0 *target = (Target_000A68D0 *)data_0022FCE0->func_000128C0(owner->target_id);
                        if (target && func_000A6DC0(map, (int)&point, &target->position)) {
                            player = other_id;
                            position = target->position;
                            return 1;
                        }
                    }
                }
                break;
            }
            case 2: {
                int order[32];
                unsigned int i;
                for (i = 0; i < 32; i++) {
                    order[i] = i;
                }
                for (i = 0; i < 32; i++) {
                    int j = (func_0014C2B0() >> 8) & 0x1f;
                    int swap = order[i];
                    order[i] = order[j];
                    order[j] = swap;
                }
                for (i = 0; i < 32; i++) {
                    Player_000A6B70 *owner = (Player_000A6B70 *)data_0022FCE0->func_000128C0(order[i] + 0xc);
                    if (owner && owner->id != id && owner->team != team) {
                        Target_000A68D0 *target = (Target_000A68D0 *)data_0022FCE0->func_000128C0(owner->target_id);
                        if (target) {
                            data_00257C64 = 0;
                            if (func_000A6DC0(map, (int)&point, &target->position)) {
                                player = order[i];
                                position = target->position;
                                return 1;
                            }
                        }
                    }
                }
                break;
            }
            }
        }
    }
    return 0;
}
