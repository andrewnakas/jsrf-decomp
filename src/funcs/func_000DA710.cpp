struct Vector3 {
    float x;
    float y;
    float z;
};

struct Rotation_000D2B90 {
    Vector3 axis;
    int angle;
};

struct Object_00066980 {
    float func_00066950();
};

// The object at data_00257CE4: a random source at 0x78 and its position at 0x7c.
struct Object_000C1270 {
    char unknown_00[0x78];
    Object_00066980 *random;
    Vector3 position;
};

extern Object_000C1270 *data_00257CE4;

struct Vertex_000DA710 {
    Vector3 position;
};

struct Mesh_00017F60 {
    Vertex_000DA710 *vertices;
    char unknown_04[4];
    Vector3 center;
};

struct Item_00016260 {
    char unknown_00[8];
};

struct Box_00017CC0 {
    char unknown_00[8];
};

// A drawn mark (0x24 bytes).
struct Item_000162A0 {
    int flags;
    int value_04;
    Mesh_00017F60 *mesh;
    char unknown_0c[0x18];
};

struct Object_00016200 {
    void func_00016260(Item_00016260 *item, int value);
    void func_000162A0(Item_000162A0 *item);
    void func_00017CC0(Box_00017CC0 *box, const Vector3 *points, unsigned int count);
};

extern Object_00016200 data_0022FCE8;

float __fastcall func_0014C580(const Vector3 *a, const Vector3 *b);
void __fastcall func_0014C730(Vector3 *target, Vector3 *direction, float scale);
void func_001BAA00();
void __fastcall func_001BAA50();
void __fastcall func_001BAC00(Vector3 *out, const Vector3 *in);
void __fastcall func_001BAC70(Rotation_000D2B90 *rotation);

// One of the sixty slots at 0x64 (16 bytes).
struct Slot_000DA5B0 {
    Vector3 position;
    unsigned int state;
};

// The child of Node whose table is at 0x1CE658 (constructor func_000DA1E0).
struct Object_000DA3E0 {
    char unknown_000[0x44];
    int full;
    char unknown_048[8];
    Vector3 direction;
    unsigned int end;
    unsigned int start;
    Slot_000DA5B0 slots[60];
    Item_00016260 link;
    Box_00017CC0 box;
    char unknown_434[0x34];
    Item_000162A0 marks[16];
    Vector3 ends[2];

    int func_000DA5B0();
    void func_000DA710();
};

// Draws a mark (0x468, at most 16) at each slot from the start to the end index within 400 of the object at
// data_00257CE4. Unless 0x44 is set, takes a slot from func_000DA5B0 and puts the box at 0x42c (link 0x424) on a
// segment from it along the direction at 0x50 turned by a random angle (up to 1/12 turn either way), 40 long, its ends
// raised and lowered by 20.
void Object_000DA3E0::func_000DA710()
{
    unsigned int drawn = 0;
    for (unsigned int i = start; i != end;) {
        if (func_0014C580(&data_00257CE4->position, &slots[i].position) < 400.0f) {
            marks[drawn].mesh->center = slots[i].position;
            marks[drawn].mesh->vertices->position = slots[i].position;
            data_0022FCE8.func_000162A0(&marks[drawn]);
            if (++drawn >= 16) {
                break;
            }
        }
        if (++i >= 60) {
            i = 0;
        }
    }
    if (full == 0) {
        int found = func_000DA5B0();
        if (found != -1) {
            ends[0] = slots[found].position;
            ends[1] = slots[found].position;
            Rotation_000D2B90 rotation = {{0.0f, 1.0f, 0.0f}, 0};
            rotation.angle = (int)((data_00257CE4->random->func_00066950() - 0.5f) * 10922.0f);
            func_001BAA00();
            func_001BAC70(&rotation);
            Vector3 along;
            func_001BAC00(&along, &direction);
            func_001BAA50();
            func_0014C730(&ends[1], &along, 40.0f);
            ends[0].y += 20.0f;
            ends[1].y -= 20.0f;
            data_0022FCE8.func_00017CC0(&box, ends, 2);
            data_0022FCE8.func_00016260(&link, -1);
        }
    }
}
