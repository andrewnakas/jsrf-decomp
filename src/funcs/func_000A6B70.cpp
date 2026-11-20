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
    int section_count;
};

int func_0004A6F0(Vector3 *point, Cell_000A6DC0 *cell);

struct Player_000A6B70 {
    char unknown_000[0x8d4];
    int target_id;
};

struct Target_000A68D0 {
    char unknown_000[0xca4];
    Vector3 position;
};

// The camera rig's anchor (section +0x80, cell +0x84, player +0x88, position +0x8c).
struct Object_000A63C0 {
    char unknown_000[0x80];
    int section_index;
    int cell_index;
    int player;
    Vector3 position;

    int func_000A6490(Section_000A6DC0 *section);
    int func_000A6B70(Map_000A6DC0 *map);
};

// Keeps the anchor while its point stays in the remembered cell: kind 0 the point from func_00014A10, kind 1 the
// player func_00014C30 names when it is the remembered one, kind 2 the remembered player; otherwise forgets it.
int Object_000A63C0::func_000A6B70(Map_000A6DC0 *map)
{
    if (section_index >= 0) {
        switch (map->kind) {
        case 0: {
            Vector3 point;
            if (data_001EB938.func_00014A10(&point) && section_index < map->section_count) {
                Section_000A6DC0 *section = &map->sections[section_index];
                if (func_0004A6F0(&point, &section->cells[cell_index]) && func_000A6490(section)) {
                    position = point;
                    return 1;
                }
            }
            break;
        }
        case 1: {
            int id;
            int other;
            if (data_001EB938.func_00014C30(&id, &other) && player >= 0 && id == player) {
                Player_000A6B70 *owner = (Player_000A6B70 *)data_0022FCE0->func_000128C0(player + 0xc);
                if (owner) {
                    Target_000A68D0 *target = (Target_000A68D0 *)data_0022FCE0->func_000128C0(owner->target_id);
                    if (target) {
                        Section_000A6DC0 *section = &map->sections[section_index];
                        if (func_0004A6F0(&target->position, &section->cells[cell_index]) && func_000A6490(section)) {
                            position = target->position;
                            return 1;
                        }
                    }
                }
            }
            break;
        }
        case 2:
            if (player >= 0) {
                Player_000A6B70 *owner = (Player_000A6B70 *)data_0022FCE0->func_000128C0(player + 0xc);
                if (owner) {
                    Target_000A68D0 *target = (Target_000A68D0 *)data_0022FCE0->func_000128C0(owner->target_id);
                    if (target && section_index >= 0) {
                        Section_000A6DC0 *section = &map->sections[section_index];
                        if (func_0004A6F0(&target->position, &section->cells[cell_index]) && func_000A6490(section)) {
                            position = target->position;
                            return 1;
                        }
                    }
                }
            }
            break;
        }
    }
    section_index = -1;
    cell_index = -1;
    player = -1;
    return 0;
}
