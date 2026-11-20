struct Vector3 {
    float x;
    float y;
    float z;
};

struct Game {
    void *func_000128C0(int id);
};

extern Game *data_0022FCE0;

// One cell of a section (0xd0 bytes): bounds the point is tested against, and its kind.
struct Cell_000A6DC0 {
    char unknown_00[0x9c];
    unsigned int kind;
    char unknown_a0[0x30];
};

// One section (0x20 bytes): its cells and the table indices that gate it.
struct Section_000A6DC0 {
    char unknown_00[0x10];
    Cell_000A6DC0 *cells;
    unsigned int cell_count;
    int *indices;
    unsigned int index_count;
};

int func_0004A6F0(Vector3 *point, Cell_000A6DC0 *cell);

struct Target_000A68D0 {
    char unknown_000[0xca4];
    Vector3 position;
};

struct Object_000A63C0 {
    char unknown_000[0x8d4];
    int target_id;

    int func_000A68D0(Section_000A6DC0 *section);
};

// Whether the position (+0xca4) of the object whose id is at 0x8d4 lies in one of the section's cells of kind 0
// or 1 (func_0004A6F0); 0 when the object does not exist.
int Object_000A63C0::func_000A68D0(Section_000A6DC0 *section)
{
    Target_000A68D0 *target = (Target_000A68D0 *)data_0022FCE0->func_000128C0(target_id);
    if (target) {
        for (unsigned int i = 0; i < section->cell_count; i++) {
            if (section->cells[i].kind <= 1 && func_0004A6F0(&target->position, &section->cells[i])) {
                return 1;
            }
        }
    }
    return 0;
}
